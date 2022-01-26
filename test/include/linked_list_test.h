#include "..\include\clove.h"
#include "..\..\linked_list\include\linked_list.h"

CLOVE_TEST(LINKED_LIST_APPEND)
{
    list_node_t *list = NULL;
    STRING_ITEM_P test001 = string_item_new("Test001");

    list_append(&list, test001);

    CLOVE_NULL(list->next);
};
