
#include "..\include\doubly_linked_list.h"

d_list_node_t *d_list_get_tail(d_list_node_t **head) //è un metodo tipo un iteratore, prende la coda
{
    d_list_node_t *current_node = *head; //leggo il valore che cè nella test (*head)
    d_list_node_t *last_node = NULL;

    while (current_node) //vedo se la lista è definita, potrebbe essere vuota
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

d_list_node_t *d_list_pop(d_list_node_t **head) // pop = take the head of the list and remove it
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

int d_item_contains(d_list_node_t **head, d_list_node_t *item) // return 0 if contains item
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
    // d_list_node_t *current_node = *head;
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

d_string_item_t *d_string_item_new(const char *string) // prova
{
    d_string_item_t *item = malloc(sizeof(d_string_item_t));
    if (!item)
    {
        return NULL;
    }
    item->string = string;
    return item;
}

// void Test_Doubly_Linked_List()
// {
//     D_STRING_ITEM_P doubly_linked_list = NULL;
//     D_STRING_ITEM_P d_test001 = d_string_item_new("d_test001");
//     D_STRING_ITEM_P d_test002 = d_string_item_new("d_test002");
//     D_STRING_ITEM_P d_test003 = d_string_item_new("d_test003");
//     D_STRING_ITEM_P d_test004 = d_string_item_new("d_test004");
//     D_STRING_ITEM_P d_test005 = d_string_item_new("d_test005");
//     D_STRING_ITEM_P d_test006 = d_string_item_new("d_test006");

//     d_list_append((DOUBLE_LINKED_PP)&doubly_linked_list, (DOUBLE_LINKED_P)d_test001);
//     d_list_append((DOUBLE_LINKED_PP)&doubly_linked_list, (DOUBLE_LINKED_P)d_test002);
//     d_list_append((DOUBLE_LINKED_PP)&doubly_linked_list, (DOUBLE_LINKED_P)d_test003);
//     d_list_append((DOUBLE_LINKED_PP)&doubly_linked_list, (DOUBLE_LINKED_P)d_test004);
//     d_list_append((DOUBLE_LINKED_PP)&doubly_linked_list, (DOUBLE_LINKED_P)d_test005);

//     // d_list_pop((DOUBLE_LINKED_PP)&doubly_linked_list);
//     // d_list_remove((DOUBLE_LINKED_PP)&doubly_linked_list, (DOUBLE_LINKED_P)d_test001);
//     d_instert_before_item((DOUBLE_LINKED_PP)&doubly_linked_list, (DOUBLE_LINKED_P)d_test004, (DOUBLE_LINKED_P)d_test006);
//     // d_instert_after_item((DOUBLE_LINKED_PP)&doubly_linked_list, (DOUBLE_LINKED_P)d_test004, (DOUBLE_LINKED_P)d_test006);

//     D_STRING_ITEM_P doubly_string_item = doubly_linked_list;
//     while (doubly_string_item)
//     {
//         printf("%s\n", doubly_string_item->string);
//         doubly_string_item = (D_STRING_ITEM_P )doubly_string_item->node.next;
//     }
// }