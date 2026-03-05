#include <stdlib.h>
#include <stdint.h>


/* Buffer Overflow Protection - in strings */

void safe_strcpy(char *dest, const char* src, size_t dest_size){
    if(dest == NULL || src == NULL || dest_size == 0) return;

    size_t i;

    for(i=0; i<dest_size-1 && src[i] != '\0'; i++){
        dest[i] = src[i];
    }
    dest[i] = '\0';


}

/* Memory Management Guidelines */

void mem_guidelines(){

    /* always check for alloc failures */
    uint8_t *buffer = malloc(1024);

    if(buffer == NULL) return;

    /* use const for read-only data */

    const float pi = 3.14;

    /* Initialize variables = 0 to avoid garbage values or the Hindenberg error */

    uint8_t small_value = 44;   //0 - 255
    uint16_t medium_value = 1000; //0 - 65535
    uint32_t large_value = 1000000; //0 - 4294967295

    /* check index bounds before access */

    int arr[10]= {0};
    int i, ele;

    if(i<10) ele = arr[i];

}

int main(){
    return 0;
}
