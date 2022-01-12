#include "..\include\linked_list.h"

list_node_t *list_get_tail(list_node_t **head) //è un metodo tipo un iteratore, prende la coda
{
    list_node_t *current_node = *head; //leggo il valore che cè nella test (*head)
    list_node_t *last_node = NULL;
    while (current_node) //vedo se la lista è definita, potrebbe essere vuota
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
        *head = item; //qui praticamente dereferenzia **head. dereferenziandolo (cosi *head) ottengo il suo contenuto
    }
    else
    {
        tail->next = item;
    }
    item->next = NULL;
    return item;
}

list_node_t *list_pop(list_node_t **head) // pop = take the head of the list and remove it
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

void list_remove(list_node_t **head, list_node_t *item) //head da dove inizio ad iterare
{
    if(item == NULL) return;

    list_node_t *current_node = *head;
    list_node_t *prev_node = NULL;

    if(current_node == item)
    {
        list_pop(head);                                 //if item is the same as the head, I’ll take the head
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

void Test_Linked_List()
{
    STRING_ITEM_P my_linked_list = NULL;
    STRING_ITEM_P test001 = string_item_new("Test001");
    STRING_ITEM_P test002 = string_item_new("Test002");
    STRING_ITEM_P test003 = string_item_new("Test003");
    STRING_ITEM_P test004 = string_item_new("Test004");

    list_append((LIST_NODE_PP)&my_linked_list, (LIST_NODE_P)test001);
    list_append((LIST_NODE_PP)&my_linked_list, (LIST_NODE_P)test002);
    list_append((LIST_NODE_PP)&my_linked_list, (LIST_NODE_P)test003);
    list_append((LIST_NODE_PP)&my_linked_list, (LIST_NODE_P)test004);
    // list_pop(&my_linked_list);
    STRING_ITEM_P string_item = my_linked_list;

    list_remove((LIST_NODE_PP)&string_item, (LIST_NODE_P)test002);

    while (string_item)
    {
        printf("%s\n", string_item->string);
        string_item = (STRING_ITEM_P)string_item->node.next;
    }
}