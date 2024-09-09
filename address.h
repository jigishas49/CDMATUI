#ifndef MEMORY_MAPPED_IO_H
#define MEMORY_MAPPED_IO_H

#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

#define REGISTER_WIDTH 4
#define Base_Address 0x00a0050000

 
// Function declarations
int map_memory_region(unsigned char** mapped_area, int* file_descriptor, u_int64_t base_address, int page_size);
void unmap_memory_region(unsigned char* mapped_area, int file_descriptor, int page_size);
u_int32_t* set_registers(unsigned char* mapped_area, u_int64_t address_offset,int valueToWrite);
u_int32_t** set_registers2(unsigned char* mapped_area, u_int64_t address_offset);
#endif // MEMORY_MAPPED_IO_H
