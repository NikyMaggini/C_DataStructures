MD bin

clang ^
-I test\include -I linked_list\include\doubly_linked_list.h ^
-o bin\test_doubly_linked.exe test\src\doubly_linked_test_main.c ^
-L bin -l doubly_linked 