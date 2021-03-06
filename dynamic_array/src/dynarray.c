#include "..\include\dynarray.h"

static size_t counter = 0;
void *malloc_tracked(size_t amount)
{
    counter++;
    return malloc(amount);
}
void *free_tracked(void *addr)
{
    counter--;
    free(addr);
    return addr;
}

int dynarray_init(dynarray_t *array, const size_t size_of_element)
{
    array->number_of_elements = 0;
    array->size_of_element = size_of_element;
    array->capacity = array->number_of_elements + 2;
    // array->data = malloc(array->size_of_element * array->capacity);
    array->data = malloc_tracked(array->size_of_element * array->capacity);
    // array->tmp_data = malloc(size_of_element);
    array->tmp_data = malloc_tracked(size_of_element);
    if (!array->tmp_data)
    {
        return -1;
    }
    return 0;
}

void dynarray_clear(dynarray_t *array)
{
    array->number_of_elements = 0;
    array->capacity = 0;
    // free(array->data);
    free_tracked(array->data);
    array->data = NULL;
    // free(array->tmp_data);
    free_tracked(array->tmp_data);
    array->tmp_data = NULL;
}

size_t get_size_element(size_t value)
{
    size_t size = sizeof(&value);
    return size;
}

size_t dynarray_len(const dynarray_t *array)
{
    return array->number_of_elements;
}

size_t dynarray_capacity(const dynarray_t *array)
{
    return array->capacity;
}

int dynarray_append(dynarray_t *array, void *value)
{
    const size_t new_size = array->number_of_elements + 1;

    if (new_size > array->capacity)
    {
        uint8_t *new_ptr = realloc(array->data, new_size * array->size_of_element);
        if (!new_ptr)
        {
            return -1;
        }
        array->data = new_ptr;
        array->capacity += 1;
    }

    size_t offset = array->number_of_elements * array->size_of_element;
    memcpy(array->data + offset, value, array->size_of_element);
    array->number_of_elements = new_size;
    array->capacity += 1;

    return 0;
}

int dynarray_get(const dynarray_t *array, const size_t index, void *value)
{
    if (index >= array->number_of_elements)
    {
        return -1;
    }

    const size_t offset = index * array->size_of_element;
    memcpy(value, array->data + offset, array->size_of_element);
    return 0;
}

int dynarray_remove(dynarray_t *array, const size_t index)
{
    if (index >= array->number_of_elements)
    {
        return -1;
    }

    const size_t offset = index * array->size_of_element;

    if (index < array->number_of_elements - 1)
    {
        memcpy(array->tmp_data, array->data + offset, array->size_of_element);
        memmove(array->data + offset, array->data + offset + array->size_of_element, (array->number_of_elements - index) * array->size_of_element);
    }

    const size_t new_size = array->number_of_elements - 1;
    uint8_t *new_ptr = realloc(array->data, new_size * array->size_of_element);
    if (!new_ptr)
    {
        // restore the original condition
        if (index < array->number_of_elements - 1)
        {
            memmove(array->data + offset + array->size_of_element, array->data + offset, (array->number_of_elements - index) * array->size_of_element);
            memcpy(array->data + offset, array->tmp_data, array->size_of_element); // restore the original data
        }
        return -1;
    }

    array->data = new_ptr;
    array->number_of_elements = new_size;
    return 0;
}