
Hardware access memory in specific pattern + Alignment by padding ensures the memory is arranged in this pattern.

Struct Padding: Compiler inserts empty bytes in-between + @ end to ensure that each block / data type; so that the ***starting address*** of those blocks are optimal for CPU access. (By 'optimal' I mean if it is a 32-bit system, the starting address of block should be a multiple of 4).

Structure size == multiple of the largest member

Insertion Rule:
1) @middle: insert padding in between elements until you reach multiple of 4 (for 32-bit systems)
2) @end: insert padding at the end to match the sizeof the largest member

Another Perspective: Think in terms of ***offset*** . Optimal scenario; the N-th element must be offset i.e a multiple of 4.

Scenario: If compiler has to read a 32bit value from a address starting @ odd, It might have to do 2 reads or in some cases trigger a hardware falut.

Real world usecase of struct padding: "large array of struct type"


Key concepts:

	- Alignment
	- Padding
	- Data Packing
	- Endians

Embedded System usecase for alignment:

	- Memory Access
	- DMA 
	- Hardware Reg
	- Interrupts Vetors
	- Array performance
	- Network protocols


C cmd to ensure alignment:

```cpp
__attribute__((aligned(4)))
```

usecase:

```cpp
typedef struc{
	uint32_t STATUS;
	uint32_t CONTROL;
	uint32_t DATA;
} __attribute__((aligned(4))) hardware_reg_t;
```



'Memory Alignment' means placing the memory block @ optimal starting mem address, this means placing data types aligned to its size, pacing struct aligned to its largest member and placing array aligned to its element size.


==> Memory Alignment for DMA:

- Reason DMA requires mem alignment; unlike CPU (that can overwork for multiple reads) DMA is a 'dumb-but-fast data mover'. It expects the data to be a perfect grid

- Alignment for DMA burst transfers: DMA can transfer 4, 8, 16 words in one continous stream
















-----------------------------------------------------------xxx----------------------------------------------------------------------------

General Note: Memory is always byte addressable (every byte has a unique address) whereas the data-bus is of 32-bits wide (word addressable). So the system fetches 32-bits at a time


- DMA Operations require memory alignment

==> Actual Memory Architecture: 

- Contrary to popular belief, actual memory is not accessed directly at byte level. Instead the memory is **hard-wired**  to  blocks called 'Memory Banks'. 

- Memory banks are grid-like, where a 32-bit system contains 4 banks (remainder theorem) namely bank0, bank1, bank2, bank3. 

- Each bank contains remainder-like memory addresses i.e bank0 = 0x00, 0x04, 0x08.. bank 1 = 0x01, 0x05 ... bank2= 0x02, 0x04... bank3 = 0x03, 0x06, 0x09....

- These banks are hard-wired vertically. That means in a single read (bank[0] + bank[1] + bank[2] + bank[3] ) is put into the 32-bit data bus.

- This is the reason starting addresses (Memory Alignment) matters.

