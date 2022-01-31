#include "clove.h"
#include "..\..\sets\include\sets.h"

CLOVE_TEST(SETS_HASHING_djb33x)
{
    char *item01 = "Ciaoooo";

    int a = djb33x_hash(item01, strlen(item01));
    int b = djb33x_hash("Ciaoooo", strlen("Ciaoooo"));

    CLOVE_INT_EQ(a,b);
}
