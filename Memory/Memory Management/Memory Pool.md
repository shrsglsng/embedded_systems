The main problem 'Memory Pool' solves : **Memory Fragmentation** using **Linked List**

Design: spilt the memory pool into blocks. And store the 'next' address in the first byte of each block.

The 'split' is executed by just placing the 'next' address in the first byte of each block and and doing ptr += bock_size


The sneaky double ptr casting to access the first byte of each block  === **dereferencing a uint8_t double ptr casting** 

```cpp
uint8_t *current;
*(uint8_t **)current = pool-->free_next;
```

Code Design:

1) Create a macro for SENSOR_SIZE and MAX_SENSORS
2) Statically / Dynamically alloc memory using above macros
3) Create a 'status-tracking' array  --status array
4) Alloc / Dealloc based based on status array



