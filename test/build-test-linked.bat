MD bin

clang ^
-I test\include -I linked_list\include\linked_list.h ^
-o bin\test_linked_list.exe test\src\linked_list_test_main.c ^
-L bin -l linked_list ^
 && bin\test_linked_list.exe