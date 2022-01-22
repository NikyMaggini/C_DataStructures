# DataStructures
Test with Data Structures. 

# Dynamic Array
## Apis:
| Api | Description |
| ------------- | ------------- |
| int dynarray_init(...) | Initializes the dynamic array |
| int dynarray_append(...) | Append an element to the array queue |
| int dynarray_get(...) | Get an element at a given index |
| int dynarray_remove(...) | Remove an element at a given index |
| void dynarray_clear(...) | Clear the dynamic array |
| size_t dynarray_len(...) | Return dynamic array lenght |
| size_t dynarray_capacity(...) | Return dynamic array capacity |

# Linked List
## Apis:
| Api | Description |
| ------------- | ------------- |
| list_node_t *list_get_tail(...) | Get linked list tail |
| list_node_t *list_append(...) | Append an element to the linked list queue |
| list_node_t *list_pop(...) | Take the head off the linked list |
| void list_remove(...) | Remove a specific item |
 
# Doubly Linked List
## Apis:
| Api | Description |
| ------------- | ------------- |
| d_list_node_t *d_list_append(...) | Append an element to the doubly linked list queue |
| d_list_node_t *d_list_pop(...) | Take the head off the doubly linked list |
| int d_item_contains(...) | If doubly linked list contains an element |
| void d_list_remove(...) | Remove a specific item |
| void d_instert_before_item(...) | (TO REVIEW) Insert an element before an specific item |
| void d_instert_after_item(...) | (TO REVIEW) Insert an element after an specific item |

# Sets - (TO COMPLETE)
## Apis
| Api | Description |
| ------------- | ------------- |
| size_t djb33x_hash(...) | Hashing algorithm |
| set_table_t *set_table_new(...) | Create a new set_table |
| set_table_t *set_insert | Insert a Set |
| set_node_t *set_search(...) | Set search |
| set_node_t *set_remove(...) | Set remove |
