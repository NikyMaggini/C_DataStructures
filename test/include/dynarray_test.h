#pragma once
#include "clove.h"
#include "..\..\dynamic_array\include\dynarray.h"

CLOVE_TEST(DYNARRAY_INIT)
{
    dynarray_t dynarray;
    dynarray_init_type(&dynarray, int);

    CLOVE_INT_EQ(0, dynarray.number_of_elements);
    CLOVE_INT_EQ(4, dynarray.size_of_element);
    CLOVE_INT_EQ(2, dynarray.capacity);
}

CLOVE_TEST(DYNARRAY_APPEND_OK)
{
    dynarray_t dynarray;
    dynarray_init_type(&dynarray, int);

    int a = 1;
    int b = 2;

    dynarray_append(&dynarray, &a);
    dynarray_append(&dynarray, &b);

    CLOVE_INT_EQ(2, dynarray.number_of_elements);
    CLOVE_INT_EQ(4, dynarray.capacity);
}

CLOVE_TEST(DYNARRAY_CLEAR)
{
    dynarray_t dynarray;
    dynarray_init_type(&dynarray, int);

    int a = 1;
    int b = 2;

    dynarray_append(&dynarray, &a);
    dynarray_append(&dynarray, &b);

    dynarray_clear(&dynarray);

    CLOVE_INT_EQ(0, dynarray.number_of_elements);
}

CLOVE_TEST(DYNARRAY_REMOVE)
{
    dynarray_t dynarray;
    dynarray_init_type(&dynarray, int);

    int a = 1;
    int b = 2;

    dynarray_append(&dynarray, &a);
    dynarray_append(&dynarray, &b);

    dynarray_remove(&dynarray, 1);

    CLOVE_INT_EQ(1, dynarray.number_of_elements);
}

