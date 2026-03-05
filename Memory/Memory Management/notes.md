Key concepts in embedded environment;

- Deterministic Allocation ; predictable mem usage pattern

- Memory safety: Preventing Buffer Overflow + Memory leaks

- Resource Constraints: limited RAM

- Real-time requirements: Avoid dynamic alloc

Interviewers Intent:

```
- Can you justify static v/s stack v/s heap choices?
  
- Do you understand - determinism
					- fragmentation
					- failure modes
					  
- Can you explain memory tradeoffs in real time systems?
```

Memory Overview in an Embedded Systems:

- There are only two physical memory components:   <"separated by volitility / lifespan of the data">
	- Flash (ROM, .rodata)
	- RAM  (also referred to as SRAM)


General Note: in E.S. when we say 'Static Memory'...we mean those variables that are allocated at compile time(strictly speaking - link time) (rather than run time)..... this includes .bss and .data alloc

IMPORTAN:

-  Scope + 'static-ness' decides: stack alloc v/s static alloc (.bss / .data)
- 'static'+ local variable == .data section

- init state decides :  .bss v/s .data

- Mutability decides Flash (.rodata) or RAM: 'const' variables are init. into Flash (.rodata)

![[Pasted image 20260226193741.png]]

Embedded Systems  memory layout:

- Fixed and predictable emory is place first (@ lower address)

- Reason for the Stack + Heap design: so that they can use memory on-demand + the combined memory use (Stack + Heap as a whole) is maximized


Mehods to detect Stack-Heap collision + Stack Overflow:

- Generally modern mcu have MPU - Memory Protection Unit ---> this defines a **No Access** zone

- Comaparing ***Stack ptr*** and Heap start address


Notes on ***Memory Alignment*** :

- Memory Allignment is required for DMA operations (and other high-performance)

- Memory Allignment == starting mem address of ***each block in the mem***. Generally malloc can give 8byte / 16byte aligned but if a peripheral requires a 32 bit aligned memory (meaning mem address ending with `00`, `20`, `40`, `60`) malloc cannot provide it. To achieve this, we must use

```
__attribute__(alligned(32)) static uint8_t buffer[1024];
```


General Note: **N+1 rule** : when you want to edit a vairable present at level N through a func, pass a ptr to the N+1 level as a parameter



Common pitfalls in memory management:

 - Memory leak: forgetting to call free()

- Dangling Ptr + Use - After - Free

- Stack Overflow ; caused by deep recursive functions, large array inside a function


General Memory Management Guidelines:

- Allways check for allocation failures

- Use 'const' keyword for read-only data  ---> stored in .rodata in Flash.

- Init. to 0. To avoid garbage value init. and Hindenberg errors

- Use appropriate data-types (uint8_t, uint16_t or uint32_t)

- check bounds before array access













------------------------------------------------------------------xxx---------------------------------------------------------------------------

General Note: use size_t while init. variables that should not be negative, like memory sizes, indexes etc
