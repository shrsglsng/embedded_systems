#include <stdlib.h>
#include <stdint.h>

/* Design: remember the N+1 rule; i.e if the thing you want to edit is in level N
 you need to pass a ptr to level N+1 as reference (if not it will be passedby value / copy)
 Here  we need to pass the malloc ptr as reference. That means (uint8_t*) is @ level N so we need
 to pass level N+1 i.e (uint8_t**) so thatwe can uint8_t* = NULL
 */

void safe_free(void **ptr)
{
    if (ptr == NULL || *ptr == NULL)
        return; // reference to malloc is NULL or the malloc itself is NULL

    free(*ptr);

    *ptr = NULL;
    /*there is no need for ptr == NULL, as ptr is a local copy  */
}

void cleanup_example()
{
    uint8_t *buffer = malloc(1024);

    /* after using buffer */
    safe_free((void **)&buffer);
}

int main()
{
    return 0;
}
