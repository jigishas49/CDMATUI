#ifndef SHARED_VARIABLE_H
#define SHARED_VARIABLE_H

extern int valueToWrite;// Declaration of the shared variable
void memory_map();
TransmitterStatus mem_trans();
ReceiverStatus mem_rx();
#endif