#include "..\include\linked_list.h"

list_node_t *list_get_tail(list_node_t **head)
{
    list_node_t *current_node = *head; 
    list_node_t *last_node = NULL;
    while (current_node) 
    {
        last_node = current_node;
        current_node = current_node->next;
    }
    return last_node;
}

list_node_t *list_append(list_node_t **head, list_node_t *item)
{
    list_node_t *tail = list_get_tail(head);
    if (!tail)
    {
        *head = item;
    }
    else
    {
        tail->next = item;
    }
    item->next = NULL;
    return item;
}

list_node_t *list_pop(list_node_t **head)
{
    list_node_t *current_head = *head;
    if (!current_head)
    {
        return NULL;
    }
    *head = (*head)->next;
    current_head->next = NULL;
    return current_head;
}

void list_remove(list_node_t **head, list_node_t *item)
{
    if(item == NULL) return;

    list_node_t *current_node = *head;
    list_node_t *prev_node = NULL;

    if(current_node == item)
    {
        list_pop(head);
        return;
    }    
  
    while (current_node != item)
    {
        prev_node = current_node;
        current_node = current_node->next;
    }
    prev_node->next = current_node->next;
    prev_node = NULL;
};


string_item_t *string_item_new(const char *string)
{
    string_item_t *item = malloc(sizeof(string_item_t));
    if (!item)
    {
        return NULL;
    }
    item->string = string;
    return item;
}
