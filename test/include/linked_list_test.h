#pragma once
#include "..\include\clove.h"
#include "..\..\linked_list\include\linked_list.h"

CLOVE_TEST(LINKED_LIST_APPEND)
{
    string_item_t *list = NULL;
    string_item_t *test001 = string_item_new("Test001");
    string_item_t *test002 = string_item_new("Test002");
    string_item_t *test003 = string_item_new("Test003");

    LIST_APPEND(&list, test001);
    LIST_APPEND(&list, test002);
    LIST_APPEND(&list, test003);

    CLOVE_PTR_EQ(list, test001);
    CLOVE_PTR_EQ(test001->node.next, test002);
    CLOVE_PTR_EQ(test002->node.next, test003);
    CLOVE_NULL(test003->node.next);
};

CLOVE_TEST(LINKED_LIST_POP)
{
    string_item_t *list = NULL;
    string_item_t *test001 = string_item_new("Test001");
    string_item_t *test002 = string_item_new("Test002");
    string_item_t *test003 = string_item_new("Test003");

    LIST_APPEND(&list, test001);
    LIST_APPEND(&list, test002);
    LIST_APPEND(&list, test003);

    LIST_POP(&list);

    CLOVE_PTR_NE(list, test001);
    CLOVE_PTR_NE(list->node.next, test002);
    CLOVE_PTR_EQ(list, test002);
    CLOVE_PTR_EQ(test002->node.next, test003);
    CLOVE_NULL(test003->node.next);
}

CLOVE_TEST(LINKED_LIST_REMOVE)
{
    string_item_t *list = NULL;
    string_item_t *test001 = string_item_new("Test001");
    string_item_t *test002 = string_item_new("Test002");
    string_item_t *test003 = string_item_new("Test003");
    string_item_t *test004 = string_item_new("Test004");

    LIST_APPEND(&list, test001);
    LIST_APPEND(&list, test002);
    LIST_APPEND(&list, test003);
    LIST_APPEND(&list, test004);

    LIST_REMOVE(&list, test002);

    CLOVE_PTR_EQ(test001->node.next, test003);
    CLOVE_PTR_EQ(test003->node.next, test004);
    CLOVE_NULL(test004->node.next);
}
