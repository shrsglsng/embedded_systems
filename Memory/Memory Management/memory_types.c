#include <stdint.h>
#include <stdlib.h>

const uint32_t firmware_version = 0x0102; // lives in Flash + .data

static int calibration_offset = -5; // lives in .data

uint8_t rx_buffer[128]; // lives in .bss

struct sensor_data{
    int value;
};

void process_data(int input)
{ // 'input' lives in stack

    uint32_t temp = 0xFF; // lives in stack

    static uint16_t counter = 0; // lives in .bss

    uint8_t *ptr = (uint8_t *)malloc(10 * sizeof(uint8_t)); // 'ptr' is stored in stack and its memory is stored in heap
}

/*Uninitialised stack variabels have garbage values  */

void stack_example(){

    int stack_variable; //variable alloc on stack 

    int stack_array[2];     //array alloc on stack

    struct sensor_data stack_struct;    //struct alloc on a stack
}

/* in heap; the fragmentation behaviour depends on the heap allocator */

void heap_example(){
    uint8_t *buffer = (uint8_t *)malloc(1024);

    if(buffer == NULL) return NULL;     //handling dynamic alloc failures 

    free(buffer);
    buffer = NULL;
}

int main(void)
{
    process_data(10);
    while (1);
}