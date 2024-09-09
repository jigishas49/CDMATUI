#include "address.h"
#include <cstdint>   // Include for uint32_t and other C standard types
#include <cstdlib>   //

    
  
   
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

u_int32_t* set_registers(unsigned char* mapped_area, u_int64_t address_offset,int valueToWrite) {
    u_int32_t* tx_on_off;
    u_int32_t* mod_on_off;
    u_int32_t* chip_sel;

    tx_on_off  = (u_int32_t*)(mapped_area + address_offset + 0 * REGISTER_WIDTH);
    mod_on_off = (u_int32_t*)(mapped_area + address_offset + 1 * REGISTER_WIDTH);
    chip_sel   = (u_int32_t*)(mapped_area + address_offset + 2 * REGISTER_WIDTH);

    *tx_on_off = valueToWrite;
    *mod_on_off = 0;
    *chip_sel = 0;

    printf("CDMA TX APP \r\n");
    printf("TX = %d \r\nMOD = %d \r\nChip_Sel: %d \r\n", *tx_on_off, *mod_on_off, *chip_sel);
    printf("TX = %d \r\nMOD = %d \r\nChip_Sel: %d \r\n", *tx_on_off, *mod_on_off, *chip_sel);
     return tx_on_off;
}
u_int32_t** set_registers2(unsigned char* mapped_area, u_int64_t address_offset) {
     u_int32_t* prn;
    u_int32_t* fll;
    u_int32_t* fll_carr;
    u_int32_t* psr;
    u_int32_t* adr_int;


        prn   = (u_int32_t*)(mapped_area + address_offset + 0 * REGISTER_WIDTH);
        fll   = (u_int32_t*)(mapped_area+ address_offset+ 14 * REGISTER_WIDTH);
        fll_carr   = (u_int32_t*)(mapped_area+ address_offset + 1 * REGISTER_WIDTH);
        psr   = (u_int32_t*)(mapped_area +address_offset + 2 * REGISTER_WIDTH);
        adr_int   = (u_int32_t*)(mapped_area+ address_offset + 3 * REGISTER_WIDTH);

      
 uint32_t** reg = (uint32_t**)malloc(5 * sizeof(uint32_t*));
  

    // Store the pointers in the array
    reg[0] = prn;
    reg[1] = fll;
    reg[2] = fll_carr;
    reg[3] = psr;
    reg[4] = adr_int;

    // Print the values
    printf("PRN = %d FLL = %d FLL_CARR = %f PSR = %f ADR_INT = %d\r\n", *prn, *fll, *fll_carr-10e6, *psr*0.299792458, *adr_int);

    // Return the array of pointers
    return reg;

}
