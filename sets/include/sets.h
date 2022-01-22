#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <string.h>

typedef struct set_node
{
    const char *key;
    size_t key_len;
    struct set_node *next;   
}set_node_t;

typedef struct set_table
{
    struct set_node **nodes;
    size_t hashmap_size;
}set_table_t;

size_t djb33x_hash(const char *key, const size_t keylen);
set_table_t *set_table_new(const size_t hasmap_size);
set_node_t *set_insert(set_table_t *table, const char *key, const size_t key_len);
set_node_t *set_search(set_table_t *table, const char *key);
set_node_t *set_remove(set_table_t *table, const char *key);