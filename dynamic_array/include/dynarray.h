#pragma once

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

/*
 * Define for Api: int dynarray_init(dynarray_t *array, const size_t size_of_element); 
*/
#define dynarray_init_type(array, type) dynarray_init(array, sizeof(type))


typedef struct // typedef crea un alias (dynarray_t), che useremo poi per chiamare questa struttura
{
    size_t number_of_elements; // quantità (size_t = rappresenta il numero piu grande rappresentabile dall'architettura)
    size_t size_of_element;     // dimensione (del singolo elemento)
    size_t capacity;
    uint8_t *data;                // indirizzo    - usiamo uint8_t perche almeno possiamo aggiungere/sottrarre 1,2,3,ecc perche con void non puoi
    uint8_t *tmp_data;          // usato per salavare quello che ci serve, un taqquino (usato malloc)
} dynarray_t;


int dynarray_init(dynarray_t *array, const size_t size_of_element);
void dynarray_clear(dynarray_t *array);
int dynarray_append(dynarray_t *array, void *value); // append = aggiungo elemente all'array
size_t dynarray_len(const dynarray_t *array);
size_t dynarray_capacity(const dynarray_t *array);
int dynarray_get(const dynarray_t *array, const size_t index, void *value); // per prendere un elemento in un determinato indice
int dynarray_remove(dynarray_t *array, const size_t index);
int Test_Dynarray();
