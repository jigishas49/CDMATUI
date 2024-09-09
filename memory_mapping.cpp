#include <cstdint>   // Include for uint32_t and other C standard types
#include <cstdlib> 
#include "address.h"
#include "memory_mapping.h"
#include <fstream>
int valueToWrite = 0; 

  u_int64_t   ulBaseAddress2 = Base_Address;
  unsigned char* uczMappedArea2;
	   u_int32_t* reg1;
   u_int64_t   ulSUMAddressOffset2 = 0;
 int iPageSize2 = getpagesize();
int iFileDescriptor2 = 0;
 u_int32_t* t1;
  u_int32_t** t2;
  void memory_map()
  {
    if (map_memory_region(&uczMappedArea2, &iFileDescriptor2, ulBaseAddress2, iPageSize2) != 0) {
        return ;
    }
    
  }
  void mem_trans( int valueToWrite)
  {

     t1 = set_registers(uczMappedArea2, ulSUMAddressOffset2,valueToWrite);
     printf("%d",valueToWrite);
    
  }
  u_int32_t**  mem_rx()
  {
    t2=set_registers2(uczMappedArea2, ulSUMAddressOffset2+0x20000);
    return t2;

  }
  
