#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // required for NULL

#define LIST_NODE_PP list_node_t **
#define LIST_NODE_P list_node_t *
#define STRING_ITEM_P string_item_t *

#define LIST_APPEND(head, item) list_append((LIST_NODE_PP)head, (LIST_NODE_P)item);
#define LIST_REMOVE(head, item) list_remove((LIST_NODE_PP)head, (LIST_NODE_P)item);
#define LIST_POP(head) list_pop((LIST_NODE_PP)head);

typedef struct list_node
{
    struct list_node *next;
}list_node_t;

typedef struct 
{
    struct list_node node;
    const char *string;
}string_item_t;

LIST_NODE_P list_get_tail(LIST_NODE_PP head);
LIST_NODE_P list_append(LIST_NODE_PP head, LIST_NODE_P item);
LIST_NODE_P list_pop(LIST_NODE_PP head);
void list_remove(LIST_NODE_PP head, LIST_NODE_P item);
STRING_ITEM_P string_item_new(const char *string);

void Test_Linked_List();