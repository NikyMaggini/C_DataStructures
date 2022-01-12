#pragma once
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#define DOUBLE_LINKED_PP d_list_node_t **
#define DOUBLE_LINKED_P d_list_node_t *
#define D_STRING_ITEM_P d_string_item_t *

typedef struct d_list_node
{
    struct d_list_node *prev;
    struct d_list_node *next;
}d_list_node_t;

typedef struct d_string_item
{
    d_list_node_t node;
    const char *string;
}d_string_item_t;

DOUBLE_LINKED_P d_list_append(DOUBLE_LINKED_PP head, DOUBLE_LINKED_P item);
DOUBLE_LINKED_P d_list_pop(DOUBLE_LINKED_PP head);
int d_item_contains(DOUBLE_LINKED_PP head, DOUBLE_LINKED_P item);
void d_list_remove(DOUBLE_LINKED_PP head, DOUBLE_LINKED_P item);
void d_instert_before_item(DOUBLE_LINKED_PP head, DOUBLE_LINKED_P item_to_append, DOUBLE_LINKED_P item);
void d_instert_after_item(DOUBLE_LINKED_PP head, DOUBLE_LINKED_P append, DOUBLE_LINKED_P item);
d_string_item_t *d_string_item_new(const char *string);

void Test_Doubly_Linked_List();