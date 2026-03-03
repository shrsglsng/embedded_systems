#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* static allocation with static keyword (generally in .bss) */

#define BUFFER_SIZE 1024
#define MAX_NO_SENSORS 8

typedef struct{
    int sensor_reading;
}sensor_data_t;

static uint8_t sensor_buffer[BUFFER_SIZE];      //static so that if a sensor is init. it persists through a power cycle
static struct sensor_data sensors[MAX_NO_SENSORS];

#define POOL_SIZE 16    //in bytes
#define NO_OF_POOLS 32

typedef struct{
    uint8_t data[POOL_SIZE];
    uint8_t used;
}memory_pool_t;

static memory_pool_t pool[NO_OF_POOLS];


/* Memory Allignement, to allocate 32-byte aligned memory */

/* __attribute__(aligned(32)) static uint8_t buffer[1024]; */   // do not run this, it is for a non-OS baremetal env



/* Dynamic Allocation: */

void *safe_malloc(size_t size){
    void *ptr = malloc(size);
    if(ptr == NULL){
        /* log the error or handle it gracefully */
        return NULL;
    }
    return ptr;
}



int main(){
    return 0;
}