#pragma once

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>


typedef struct 
{
    size_t number_of_elements; 
    size_t size_of_element; 
    size_t capacity;
    uint8_t *data; 
    uint8_t *tmp_data;  
} dynarray_t;


int dynarray_init(dynarray_t *array, const size_t size_of_element);
void dynarray_clear(dynarray_t *array);
int dynarray_append(dynarray_t *array, void *value);
size_t dynarray_len(const dynarray_t *array);
size_t dynarray_capacity(const dynarray_t *array);
int dynarray_get(const dynarray_t *array, const size_t index, void *value); 
int dynarray_remove(dynarray_t *array, const size_t index);
int Test_Dynarray();
