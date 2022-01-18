#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>


typedef struct set_node
{
    const char *key;
    size_t key_len;
    struct set_node *next;   
}set_node_t;

typedef struct set_table
{
    set_node_t **nodes;
    size_t hashmap_size;
}set_table_t;

void *malloc_tracked(size_t amount);
void *free_tracked(void *addr);
size_t djb33x_hash(const char *key, const size_t keylen);
set_table_t *set_table_new(const size_t hasmap_size);
set_node_t *set_insert(set_table_t *table, const char *key, const size_t key_len);