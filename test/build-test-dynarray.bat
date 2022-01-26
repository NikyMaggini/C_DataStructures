MD bin

clang ^
-I test\include -I dynamic_array\include ^
-o bin\test_dynarray.exe test\src\dynarray_test_main.c ^
-L bin -l dynarray ^
 && bin\test_dynarray.exe