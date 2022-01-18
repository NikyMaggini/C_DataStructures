#include "..\include\dynarray.h"

int __Test_Dynarray()
{
    dynarray_t array;
    dynarray_init_type(&array,int);

    int a = 100;
    int b = 200;
    int c = 300;
    dynarray_append(&array, &a);

    dynarray_append(&array, &b);
    dynarray_append(&array, &c);
    dynarray_append(&array, &c);
    dynarray_append(&array, &c);
    dynarray_append(&array, &c);
    dynarray_append(&array, &c);
    dynarray_append(&array, &c);

    // printf("number of elements = %llu\n", dynarray_len(&array));
    // printf("Array capacity = %llu\n", array.capacity);
    // printf("Size_of_element: %llu\n", array.size_of_element);
    // printf("Number_of_element: %llu\n", array.number_of_elements);


    for (size_t i = 0; i < dynarray_len(&array); i++)
    {
        int value;
        if (!dynarray_get(&array, i, &value))
        {
            printf("[%llu] %d\n", i, value);
        }
    }

    dynarray_clear(&array);

    return 0;
}

int main()
{
    __Test_Dynarray();

    return 0;
}