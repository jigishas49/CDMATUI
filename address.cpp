#include "address.h"
#include <cstdint>   // Include for uint32_t and other C standard types
#include <cstdlib>   //
#include "Types.h"
    
  
   
int map_memory_region(unsigned char** mapped_area, int* file_descriptor, u_int64_t base_address, int page_size) {
    *file_descriptor = open("/dev/mem", O_RDWR | O_SYNC);
    if (*file_descriptor == -1) {
        printf("Error opening /dev/mem: %s\n", strerror(errno));
        return -1;
    }

    *mapped_area = (unsigned char*) mmap(NULL, page_size * 0x0120, PROT_READ | PROT_WRITE, MAP_SHARED, *file_descriptor, base_address);
    if (*mapped_area == MAP_FAILED) {
        printf("Error mapping memory: %s\n", strerror(errno));
        close(*file_descriptor);
        return -1;
    }

    return 0;
}

void unmap_memory_region(unsigned char* mapped_area, int file_descriptor, int page_size) {
    if (munmap(mapped_area, page_size * 0x0120) == -1) {
        printf("Error unmapping memory: %s\n", strerror(errno));
    }
    close(file_descriptor);
}

TransmitterStatus set_registers(unsigned char* mapped_area, u_int64_t address_offset) {
  
    TransmitterStatus transmiter_status;
    transmiter_status.tx_on_off  = (u_int32_t*)(mapped_area + address_offset + 0 * REGISTER_WIDTH);
    transmiter_status.mod_on_off = (u_int32_t*)(mapped_area + address_offset + 1 * REGISTER_WIDTH);
    transmiter_status.chip_sel   = (u_int32_t*)(mapped_area + address_offset + 2 * REGISTER_WIDTH);
   transmiter_status.msg  = (u_int32_t*)(mapped_area + address_offset + 3 * REGISTER_WIDTH);
    transmiter_status.prn  = (u_int32_t*)(mapped_area + address_offset + 4 * REGISTER_WIDTH);
 


     return transmiter_status;
}
ReceiverStatus set_registers2(unsigned char* mapped_area, u_int64_t address_offset) {
    
   ReceiverStatus receiver_status;

        receiver_status.prn   = (u_int32_t*)(mapped_area + address_offset + 0 * REGISTER_WIDTH);
        receiver_status.fll   = (u_int32_t*)(mapped_area+ address_offset+ 14 * REGISTER_WIDTH);
        receiver_status.fll_carr   = (u_int32_t*)(mapped_area+ address_offset + 1 * REGISTER_WIDTH);
        receiver_status.psr   = (u_int32_t*)(mapped_area +address_offset + 2 * REGISTER_WIDTH);
        receiver_status.adr_int   = (u_int32_t*)(mapped_area+ address_offset + 3 * REGISTER_WIDTH);
          


    // Store the pointers in the array
   

    // Print the values
    //printf("PRN = %d FLL = %d FLL_CARR = %f PSR = %f ADR_INT = %d\r\n", *prn, *fll, *fll_carr-10e6, *psr*0.299792458, *adr_int);

    // Return the array of pointers
    return receiver_status;

}
