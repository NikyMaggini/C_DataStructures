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

    LIST_APPEND(&my_linked_list, test001);
    LIST_APPEND(&my_linked_list, test002);
    LIST_APPEND(&my_linked_list, test003);
    LIST_APPEND(&my_linked_list, test004);

    LIST_POP(&my_linked_list);

    LIST_REMOVE(&my_linked_list, test002);

    STRING_ITEM_P string_item = my_linked_list;
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

    DOUBLY_LIST_APPEND(&doubly_linked_list, d_test001);
    DOUBLY_LIST_APPEND(&doubly_linked_list, d_test002);
    DOUBLY_LIST_APPEND(&doubly_linked_list, d_test003);
    DOUBLY_LIST_APPEND(&doubly_linked_list, d_test004);
    DOUBLY_LIST_APPEND(&doubly_linked_list, d_test005);

    DOUBLY_LIST_POP(&doubly_linked_list);
    
    DOUBLY_LIST_REMOVE(&doubly_linked_list, d_test003);
    
    // DOUBLY_LIST_INSERT_BEFORE(&doubly_linked_list, d_test004, d_test006);

    DOUBLY_LIST_INSERT_AFTER(&doubly_linked_list, d_test004, d_test006);

    D_STRING_ITEM_P doubly_string_item = doubly_linked_list;
    while (doubly_string_item)
    {
        printf("%s\n", doubly_string_item->string);
        doubly_string_item = (D_STRING_ITEM_P)doubly_string_item->node.next;
    }
}

int main()
{
    __Test_Linked_List();
    __Test_Doubly_Linked_List();

    return 0;
}