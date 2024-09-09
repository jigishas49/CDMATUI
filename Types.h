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
    ChippingRates       ChipRate;
    u_int16_t           PRN;
    double              Frequency;
    float               Power;
    float               CByNo;
    ReceiverLockStatus  LockStatus;
    u_int32_t           LockTime;
}ReceiverStatus;
#endif
#pragma pack()

#pragma pack(1)
#ifndef TRANSMITTER_STATUS_TYPE
#define TRANSMITTER_STATUS_TYPE
typedef struct TransmitterStatus {
    ChippingRates       ChipRate;
    u_int16_t           PRN;
    double              Frequency;
    float               Power;
    bool                OutputEnable;
    bool                ModulationEnable;

}TransmitterStatus;
#endif
#pragma pack()


#endif // TUITYPES_H
