#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct
{
    uint8_t *pool; // ptr to first byte of entire mem pool
    size_t pool_size;

    size_t block_count;

    uint8_t *free_list; // points to the head of the available mem list;
    size_t free_count;

} mem_pool_t;

/* init mem pool */

int init_mem_pool(mem_pool_t *pool, size_t block_size, size_t block_count)
{
    pool->pool_size = block_size * block_count;
    pool->pool = (uint8_t *)malloc(pool->pool_size);

    if (pool->pool == NULL)
        return -1;

    /* init free_list. here free list is a linked list of available mem loc */

    pool->free_list = pool->pool;
    pool->free_count = pool->block_count;

    /* after initialising the list, link all the mem, which happens to be continous at the begining of init. Also remember to use the first byte of each memory block to store the 'next' addres*/

    uint8_t *current = pool->pool;

    for (int i = 0; i < block_count; i++)
    {
        *(uint8_t **)current = current + block_size; // current jumps to each block and uses the first byte to store 'next' address
        current += block_size;
    }

    *(uint8_t **)current = NULL; // the last memory blocks 'next' should point to NULL

    return 0;
}

/* allocate from pool */

void *mem_pool_alloc(mem_pool_t *pool)
{
    if (pool->free_count == 0)
        return NULL; // pool exhausted

    uint8_t *block = pool->free_list;

    pool->free_list = *(uint8_t **)block; // remember first byte of each block has 'next' address stored in it. So update free_list with the address of next available mem
    pool->free_count--;

    return block;
}

/* Free the mem and give it to pool */

void mem_pool_free(mem_pool_t *pool, void *ptr)
{
    if (ptr == NULL)
        return; // empty mem passed

    /* first you need to make sure that the memory being added constains 'next' in its first byte */

    *(uint8_t **)ptr = pool->free_list;

    /* then update the pools free_list to point to the newly added memory */

    pool->free_list = ptr;
    pool->free_count++;

}

int main()
{
    return 0;
}
