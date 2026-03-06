#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct
{
    uint8_t reg_1;
    uint32_t reg_2;
    uint8_t reg_3;
} poor_t;       //sizeof() = 32+32+32 = 96 = 12B

typedef struct
{
    uint32_t reg_1;
    uint8_t reg_2;
    uint8_t reg_3;
} good_t;       //sizeof() = 32 + 32 = 64 = 8B

/* aligned v/s un-aligned acess */

uint32_t* aligned_ptr = (uint32_t *)0x1000;

uint32_t *unaligned_ptr = (uint32_t *)0x1007;   //not a multiple of 4















int main()
{

    poor_t poor;
    good_t good;

    printf("Size of poor: %zuB Size of good: %zuB\n", sizeof(poor), sizeof(good));

    printf("Unaligned read %p\n", unaligned_ptr);
    return 0;
}
