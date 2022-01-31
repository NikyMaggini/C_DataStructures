MD bin

clang -I test\include -I sets\include -o bin\test_sets.exe test\src\sets_test_main.c -L bin -l sets && bin\test_sets.exe