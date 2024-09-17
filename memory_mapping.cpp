#include <cstdint>   // Include for uint32_t and other C standard types
#include <cstdlib> 
#include "address.h"
#include "memory_mapping.h"
#include <fstream>
#include "Types.h"
int valueToWrite = 0; 

  u_int64_t   ulBaseAddress2 = Base_Address;
  unsigned char* uczMappedArea2;
	   u_int32_t* reg1;
   u_int64_t   ulSUMAddressOffset2 = 0;
 int iPageSize2 = getpagesize();
int iFileDescriptor2 = 0;

  u_int32_t** t2;
  void memory_map()
  {
    if (map_memory_region(&uczMappedArea2, &iFileDescriptor2, ulBaseAddress2, iPageSize2) != 0) {
        return ;
    }
    
  }
  TransmitterStatus mem_trans( )
  {

     TransmitterStatus transmiter_status= set_registers(uczMappedArea2, ulSUMAddressOffset2);
     printf("%d",valueToWrite);
     return transmiter_status;
    
  }
ReceiverStatus mem_rx()
  {
    ReceiverStatus reciever_status=set_registers2(uczMappedArea2, ulSUMAddressOffset2+0x20000);
    return reciever_status;

  }
  
