#ifndef SHARED_VARIABLE_H
#define SHARED_VARIABLE_H

extern int valueToWrite;// Declaration of the shared variable
void memory_map();
void mem_trans(int valueTowrite);
u_int32_t** mem_rx();
#endif