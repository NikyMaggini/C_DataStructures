
#include "..\include\doubly_linked_list.h"

d_list_node_t *d_list_get_tail(d_list_node_t **head)
{
    d_list_node_t *current_node = *head;
    d_list_node_t *last_node = NULL;

    while (current_node)
    {
        last_node = current_node;
        current_node = current_node->next;
    }
    return last_node;
}

d_list_node_t *d_list_append(d_list_node_t **head, d_list_node_t *item)
{
    d_list_node_t *tail = d_list_get_tail(head);
    if (!tail)
    {
        *head = item;
    }
    else
    {
        tail->next = item;
    }
    item->prev = tail;
    item->next = NULL;
    return item;
}

d_list_node_t *d_list_pop(d_list_node_t **head)
{
    d_list_node_t *current_head = *head;
    if (!current_head)
    {
        return NULL;
    }
    *head = (*head)->next;
    current_head->next = NULL;
    return current_head;
}

int d_item_contains(d_list_node_t **head, d_list_node_t *item)
{
    d_list_node_t *node = *head;

    while (node)
    {
        if (node == item)
        {
            return 0;
        }

        node = node->next;
    }
    return -1;
}

void d_list_remove(d_list_node_t **head, d_list_node_t *item)
{
    d_list_node_t *prev_node = item->prev;
    d_list_node_t *next_node = item->next;

    if (!prev_node)
    {
        d_list_pop(head); // TO REVIEW
        return;
    }

    if (item == d_list_get_tail(head))
    {
        prev_node->next = NULL;
        return;
    }

    prev_node->next = item->next;
    next_node->prev = item->prev;
    item->prev = NULL;
    item->next = NULL;
}

void d_instert_before_item(d_list_node_t **head, d_list_node_t *before_node, d_list_node_t *item) // TO REVIEW (only works by adding a value not into the list)
{
    d_list_node_t *current_node = *head;
    d_list_node_t *next_node = before_node->next;

    while (current_node != before_node)
    {
        current_node = current_node->next;
    }
    item->next = before_node->next;
    item->prev = before_node->prev;

    if (current_node->prev != NULL)
    {
        next_node->prev = item;
    }
    before_node->next = item;
}

void d_instert_after_item(d_list_node_t **head, d_list_node_t *after_node, d_list_node_t *item) // TO REVIEW (only works by adding a value not into the list)
{
    d_list_node_t *current_node = *head;
    d_list_node_t *prev_node = after_node->prev;

    while (current_node != after_node)
    {
        current_node = current_node->next;
    }
    item->prev = current_node->prev;
    item->next = current_node;
    if (current_node->prev != NULL)
    {
        prev_node->next = item;
    }
    current_node->prev = item;
}

d_string_item_t *d_string_item_new(const char *string)
{
    d_string_item_t *item = malloc(sizeof(d_string_item_t));
    if (!item)
    {
        return NULL;
    }
    item->string = string;
    return item;
}
