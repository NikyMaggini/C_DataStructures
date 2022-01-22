#include "..\include\sets.h"

size_t djb33x_hash(const char *key, const size_t keylen) // algoritmo che data una sequenza di dati, tira fuori un numero rispettando le regole sull'hashing
{
    size_t hash = 5381;

    for (size_t i = 0; i < keylen; i++)
    {
        hash = ((hash << 5) + hash) ^ key[i];
    }
    return hash;
}

set_table_t *set_table_new(const size_t hasmap_size) // hashmap_size = numero massimo di indici che puo tirare fuori
{
    set_table_t *table = malloc(sizeof(set_table_t));
    if (!table)
    {
        return NULL;
    }
    table->hashmap_size = hasmap_size;
    table->nodes = calloc(table->hashmap_size, sizeof(set_node_t));
    if (!table->nodes)
    {
        free(table);
        return NULL;
    }

    return table;
}

set_node_t *set_insert(set_table_t *table, const char *key, const size_t key_len)
{
    size_t hash = djb33x_hash(key, key_len);
    size_t index = hash % table->hashmap_size;
    set_node_t *head = table->nodes[index];
    
    if (head)
    {
        if (!strcmp(key, head->key))
        {
            return head;
        }
    }
    if (!head)
    {
        table->nodes[index] = malloc(sizeof(set_node_t));
        if (!table->nodes[index])
        {
            return NULL;
        }
        table->nodes[index]->key = key;
        table->nodes[index]->key_len = key_len;
        table->nodes[index]->next = NULL;

        return NULL;
    }

    set_node_t *new_item = malloc(sizeof(set_node_t));
    if (!new_item)
    {
        return NULL;
    }
    new_item->key = key;
    new_item->key_len = key_len;
    new_item->next = NULL;

    set_node_t *tail = head;
    while (head)
    {
        tail = head;
        head = head->next;
    }
    tail->next = new_item;
    return new_item;
}

set_node_t *set_search(set_table_t *table, const char *key)
{
    size_t hash = djb33x_hash(key, strlen(key));
    size_t index = hash % table->hashmap_size;
    set_node_t *node = table->nodes[index];
    if (node)
    {
        if (!strcmp(key, node->key)) // se ritorna 0, cè
        {
            printf("set_search: OK - key: %s\n", node->key);
            return node;
        }
    }
    printf("set_search: FAILED - [%s] key not found\n", key);
    return NULL;
}

set_node_t *set_remove(set_table_t *table, const char *key)
{
    size_t hash = djb33x_hash(key, strlen(key));
    size_t index = hash % table->hashmap_size;
    set_node_t *node = table->nodes[index];
    if (node)
    {
        if (!strcmp(node->key, key))
        {
            table->nodes[index] = node->next; // set 'key' at next of 'current_node'
            printf("set_remove: OK - key: %s\n", key);
            return node;
        }
        else
        {
            printf("set_remove: FAILED - [%s] key not found \n", key);
        }
    }
    return NULL;
}