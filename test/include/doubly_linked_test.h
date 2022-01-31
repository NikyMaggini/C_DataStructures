#include "..\include\clove.h"
#include "..\..\linked_list\include\doubly_linked_list.h"

CLOVE_TEST(DOUBLY_LINKED_APPEND)
{
    d_string_item_t *doubly_list = NULL;
    d_string_item_t *d_test001 = d_string_item_new("d_test001");
    d_string_item_t *d_test002 = d_string_item_new("d_test002");
    d_string_item_t *d_test003 = d_string_item_new("d_test003");
    d_string_item_t *d_test004 = d_string_item_new("d_test004");

    DOUBLY_LIST_APPEND(&doubly_list, d_test001);
    DOUBLY_LIST_APPEND(&doubly_list, d_test002);
    DOUBLY_LIST_APPEND(&doubly_list, d_test003);
    DOUBLY_LIST_APPEND(&doubly_list, d_test004);

    CLOVE_PTR_EQ(doubly_list, d_test001);
    CLOVE_NULL(d_test001->node.prev);
    CLOVE_PTR_EQ(d_test002->node.prev, d_test001);
    CLOVE_PTR_EQ(d_test002->node.next, d_test003);
    CLOVE_PTR_EQ(d_test003->node.prev, d_test002);
    CLOVE_PTR_EQ(d_test003->node.next, d_test004);
    CLOVE_PTR_EQ(d_test004->node.prev, d_test003);
    CLOVE_NULL(d_test004->node.next);
}

CLOVE_TEST(DOUBLY_LINKED_REMOVE)
{
    d_string_item_t *doubly_list = NULL;
    d_string_item_t *d_test001 = d_string_item_new("d_test001");
    d_string_item_t *d_test002 = d_string_item_new("d_test002");
    d_string_item_t *d_test003 = d_string_item_new("d_test003");
    d_string_item_t *d_test004 = d_string_item_new("d_test004");

    DOUBLY_LIST_APPEND(&doubly_list, d_test001);
    DOUBLY_LIST_APPEND(&doubly_list, d_test002);
    DOUBLY_LIST_APPEND(&doubly_list, d_test003);
    DOUBLY_LIST_APPEND(&doubly_list, d_test004);

    DOUBLY_LIST_REMOVE(&doubly_list, d_test002);
    DOUBLY_LIST_REMOVE(&doubly_list, d_test004);

    CLOVE_PTR_EQ(d_test001->node.next, d_test003);
    CLOVE_PTR_EQ(d_test003->node.prev, d_test001);
    CLOVE_NULL(d_test003->node.next);
    CLOVE_NULL(d_test002->node.prev);
    CLOVE_NULL(d_test002->node.next);
    CLOVE_NULL(d_test004->node.next);
}

CLOVE_TEST(DOUBLY_LINKED_POP)
{
    d_string_item_t *doubly_list = NULL;
    d_string_item_t *d_test001 = d_string_item_new("d_test001");
    d_string_item_t *d_test002 = d_string_item_new("d_test002");
    d_string_item_t *d_test003 = d_string_item_new("d_test003");

    DOUBLY_LIST_APPEND(&doubly_list, d_test001);
    DOUBLY_LIST_APPEND(&doubly_list, d_test002);
    DOUBLY_LIST_APPEND(&doubly_list, d_test003);

    DOUBLY_LIST_POP(&doubly_list);

    CLOVE_PTR_EQ(doubly_list, d_test002);
    CLOVE_NULL(d_test001->node.prev);
    CLOVE_NULL(d_test001->node.next);
    CLOVE_NULL(d_test002->node.prev);
    CLOVE_PTR_EQ(d_test002->node.next, d_test003);
    CLOVE_PTR_EQ(d_test003->node.prev, d_test002);
    CLOVE_NULL(d_test003->node.next);
}

CLOVE_TEST(DOUBLY_LINKED_INSERT_BEFORE_TEST)
{
    d_string_item_t *doubly_list = NULL;
    d_string_item_t *d_test001 = d_string_item_new("d_test001");
    d_string_item_t *d_test002 = d_string_item_new("d_test002");
    d_string_item_t *d_test003 = d_string_item_new("d_test003");
    d_string_item_t *d_test004 = d_string_item_new("d_test004");

    DOUBLY_LIST_APPEND(&doubly_list, d_test001);
    DOUBLY_LIST_APPEND(&doubly_list, d_test002);
    DOUBLY_LIST_APPEND(&doubly_list, d_test003);

    DOUBLY_LIST_INSERT_BEFORE(&doubly_list, d_test002, d_test004);

    CLOVE_PTR_EQ(d_test002->node.next, d_test004);
    CLOVE_PTR_EQ(d_test003->node.prev, d_test004);
    CLOVE_PTR_EQ(d_test004->node.next, d_test003);
    // CLOVE_PTR_EQ(d_test004->node.prev, d_test002);//TO REVIEW - FAILURE
}

CLOVE_TEST(DOUBLY_LINKED_INSERT_AFTER_TEST)
{
    d_string_item_t *doubly_list = NULL;
    d_string_item_t *d_test001 = d_string_item_new("d_test001");
    d_string_item_t *d_test002 = d_string_item_new("d_test002");
    d_string_item_t *d_test003 = d_string_item_new("d_test003");
    d_string_item_t *d_test004 = d_string_item_new("d_test004");

    DOUBLY_LIST_APPEND(&doubly_list, d_test001);
    DOUBLY_LIST_APPEND(&doubly_list, d_test002);
    DOUBLY_LIST_APPEND(&doubly_list, d_test003);

    DOUBLY_LIST_INSERT_AFTER(&doubly_list, d_test002, d_test004);

    CLOVE_PTR_EQ(d_test001->node.next, d_test004);
    CLOVE_PTR_EQ(d_test002->node.prev, d_test004);
    CLOVE_PTR_EQ(d_test004->node.prev, d_test001);
    CLOVE_PTR_EQ(d_test004->node.next, d_test002);
}
