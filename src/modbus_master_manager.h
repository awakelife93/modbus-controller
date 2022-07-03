#include <stdint.h>

#include <iostream>
#include <tuple>

#include "modbus_master_exception.h"

#ifndef __MODUS_MASTER_MANAGER_h__
#define __MODUS_MASTER_MANAGER_h__

class ModBusMasterManager
{
public:
    ModBusMasterManager();

    /// Setup MBAP Header Info
    void UpdateUnitId(uint8_t);
    void UpdateTransactionId(uint16_t);
    void SetSlaveIPAddress(std::string);

    /// Send to Slave
    std::tuple<bool, uint8_t, uint8_t, uint16_t, uint16_t, uint16_t, uint16_t,
               std::string>
        Request(uint8_t, u_int16_t, u_int16_t);

    /// ModBus Coil Function (Only Access Bit)
    void ReadCoil(u_int16_t, u_int16_t);
    void ReadDiscreteInputs(u_int16_t, u_int16_t);
    void WriteSingleCoil(u_int16_t, u_int16_t);
    void WriteMultipleCoils(u_int16_t, u_int16_t);

    /// ModBus Register Function (Only Access 16 Bit)
    void ReadHoldingRegisters(u_int16_t, u_int16_t);
    void ReadInputRegister(u_int16_t, u_int16_t);
    void WriteSingleRegister(u_int16_t, u_int16_t);
    void WriteMultipleRegisters(u_int16_t, u_int16_t);

    /// Common Process Status Code
    static const uint8_t successCode = 0x00;
    static const uint8_t failCode = 0x01;

private:
    /// Master -> Slave Request Params
    uint8_t mLength;
    uint8_t mUnitId;
    uint16_t mTransactionId;  /// Increases when master <-> slave exchange is
                              /// successful
    uint16_t mProtocolId;     /// Protocol ID is always 0x0000 in TCP mode
    std::string mSlaveIPAddress;

    /// ModBus Coil Function Hex Code (Only Access Bit)
    static const uint8_t kReadCoilCode = 0x01;
    static const uint8_t kReadDiscreteInputsCode = 0x02;
    static const uint8_t kWriteSingleCoilCode = 0x05;
    static const uint8_t kWriteMultipleCoilsCode = 0x0F;

    /// ModBus Register Function Hex Code (Only Access 16 Bit)
    static const uint8_t kReadHoldingRegistersCode = 0x03;
    static const uint8_t kReadInputRegisterCode = 0x04;
    static const uint8_t kWriteSingleRegisterCode = 0x06;
    static const uint8_t kWriteMultipleRegistersCode = 0x10;

    /// ModBus Master Transaction Method
    void masterTransaction(uint8_t, uint16_t, uint16_t);
};

#endif __MODUS_MASTER_MANAGER_h__