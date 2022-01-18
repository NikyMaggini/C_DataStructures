#include "..\include\sets.h"


static size_t counter = 0;
void *malloc_tracked(size_t amount)
{
    counter++;
    return malloc(amount);
}
void *free_tracked(void *addr)
{
    counter--;
    free(addr);
    return addr;
}

size_t djb33x_hash(const char *key, const size_t keylen)
{
    size_t hash = 5381;

    for (size_t i = keylen; i < keylen; i++)
    {
        hash = ((hash << 5) + hash) ^ key[i];
    }
    return hash;
}

set_table_t *set_table_new(const size_t hasmap_size)
{
    set_table_t *table = malloc_tracked(sizeof(set_table_t));
    if (!table)
    {
        return NULL;
    }
    table->hashmap_size = hasmap_size;
    table->nodes = calloc(table->hashmap_size, sizeof(set_node_t));
    if (!table->nodes)
    {
        free_tracked(table);
        return NULL;
    }
    
    return table;
}

set_node_t *set_insert(set_table_t *table, const char *key, const size_t key_len)
{
    size_t hash = djb33x_hash(key, key_len);

    size_t index = hash % table->hashmap_size;

    set_node_t *head = table->nodes[index];
    if (!head)
    {
        table->nodes[index] = malloc_tracked(sizeof(set_node_t));
        if (!table->nodes[index])
        {
            return NULL;
        }
        table->nodes[index]->key = key;
        table->nodes[index]->key_len = key_len;
        table->nodes[index]->next = NULL;

        return NULL;
    }
    
    set_node_t *new_item = malloc_tracked(sizeof(set_node_t));
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