#include "..\include\linked_list.h"
#include "..\include\doubly_linked_list.h"

void __Test_Linked_List()
{
    printf("\n-------- LINKED LIST -------- \n");

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

void __Test_Doubly_Linked_List()
{
    printf("\n-------- DOUBLY LINKED LIST -------- \n");

    D_STRING_ITEM_P doubly_linked_list = NULL;
    D_STRING_ITEM_P d_test001 = d_string_item_new("d_test001");
    D_STRING_ITEM_P d_test002 = d_string_item_new("d_test002");
    D_STRING_ITEM_P d_test003 = d_string_item_new("d_test003");
    D_STRING_ITEM_P d_test004 = d_string_item_new("d_test004");
    D_STRING_ITEM_P d_test005 = d_string_item_new("d_test005");
    D_STRING_ITEM_P d_test006 = d_string_item_new("d_test006");

    d_list_append((DOUBLE_LINKED_PP)&doubly_linked_list, (DOUBLE_LINKED_P)d_test001);
    d_list_append((DOUBLE_LINKED_PP)&doubly_linked_list, (DOUBLE_LINKED_P)d_test002);
    d_list_append((DOUBLE_LINKED_PP)&doubly_linked_list, (DOUBLE_LINKED_P)d_test003);
    d_list_append((DOUBLE_LINKED_PP)&doubly_linked_list, (DOUBLE_LINKED_P)d_test004);
    d_list_append((DOUBLE_LINKED_PP)&doubly_linked_list, (DOUBLE_LINKED_P)d_test005);

    // d_list_pop((DOUBLE_LINKED_PP)&doubly_linked_list);
    // d_list_remove((DOUBLE_LINKED_PP)&doubly_linked_list, (DOUBLE_LINKED_P)d_test001);
    d_instert_before_item((DOUBLE_LINKED_PP)&doubly_linked_list, (DOUBLE_LINKED_P)d_test004, (DOUBLE_LINKED_P)d_test006);
    // d_instert_after_item((DOUBLE_LINKED_PP)&doubly_linked_list, (DOUBLE_LINKED_P)d_test004, (DOUBLE_LINKED_P)d_test006);

    D_STRING_ITEM_P doubly_string_item = doubly_linked_list;
    while (doubly_string_item)
    {
        printf("%s\n", doubly_string_item->string);
        doubly_string_item = (D_STRING_ITEM_P )doubly_string_item->node.next;
    }
}


int main()
{
    __Test_Linked_List();
    __Test_Doubly_Linked_List();    

    return 0;
}