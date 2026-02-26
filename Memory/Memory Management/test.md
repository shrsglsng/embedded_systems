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

- There are only two physical memory components:   <separated by volitility>
		- Flash (ROM, .rodata)
		- RAM  (also referred to as SRAM)



General Note: in E.S. when we say 'Static Memory'...we mean those variables that are allocated at link time (rather than run time)..... this includes .bss and .data alloc

IMPORTANT:

-  Scope + 'static-ness' decides: stack alloc v/s static alloc (.bss / .data)

- init state decides :  .bss v/s .data

- Mutability decides Flash (.rodata) or RAM: 'const' variables are init. into Flash (.rodata)