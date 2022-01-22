#include "..\include\sets.h"

int __Test_Sets()
{
    char *item01 = "Ciaoooo";
    char *item02 = "Buonaseraaaa";
    char *item03 = "Niky";
    char *item04 = "Carbonara";
    char *item05 = "Fifth";
    char *item06 = "Nicola";

    set_table_t *table = set_table_new(10);

    set_insert(table, item01, strlen(item01));
    set_insert(table, item03, strlen(item03));
    set_insert(table, item04, strlen(item04));
    set_insert(table, item06, strlen(item06));
    
    set_remove(table, item04);
    set_remove(table, item05);

    set_search(table, item04);
    set_search(table, item03);
    set_search(table, item01);

    return 0;
}

int main()
{
    __Test_Sets();

    return 0;
}