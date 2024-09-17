#ifndef TUITYPES_H
#define TUITYPES_H

#include <sys/types.h>

#ifndef CHIPPING_RATES_ENUM
#define CHIPPING_RATES_ENUM
enum ChippingRates {
    ChippingRates_1M = 1,
    ChippingRates_2_5M,
    ChippingRates_5M,
    ChippingRates_10M
};
#endif

#ifndef LOCK_STATUS_ENUM
#define LOCK_STATUS_ENUM
enum ReceiverLockStatus {
    Unlocked = 1,
    CodeLock,
    CodeCarrierLock,
};
#endif

#pragma pack(1)
#ifndef RECIVER_STATUS_TYPE
#define RECIVER_STATUS_TYPE
typedef struct ReceiverStatus {
     u_int32_t* prn;
    u_int32_t* fll;
    u_int32_t* fll_carr;
    u_int32_t* psr;
    u_int32_t* adr_int;
}ReceiverStatus;
#endif
#pragma pack()

#pragma pack(1)
#ifndef TRANSMITTER_STATUS_TYPE
#define TRANSMITTER_STATUS_TYPE
typedef struct TransmitterStatus {
    u_int32_t* tx_on_off;
    u_int32_t* mod_on_off;
    u_int32_t* chip_sel;
     u_int32_t* msg;
      u_int32_t* prn;


}TransmitterStatus;
#endif
#pragma pack()


#endif // TYPES_H
