#include "iostream"
#include <stdint.h>

using namespace std;

#ifndef __ModBusMasterManager_h__
#define __ModBusMasterManager_h__

class ModBusMasterManager
{
  public:
    ModBusMasterManager();
    
    /// @brief ModBus Coil Function (Only Access Bit)
    void readCoil();
    void readDiscreteInputs();
    void writeSingleCoil();
    void writeMultipleCoils();
    
    /// @brief ModBus Register Function (Only Access 16 Bit)
    void readHoldingRegisters();
    void readInputRegister();
    void writeSingleRegister();
    void writeMultipleRegisters();
    void send();
    
  private:
    /// @brief Common Process Status Code
    static const uint8_t successCode =  0x00;
    static const uint8_t failedCode =  0x01;
    
    /// @brief ModBus Coil Function Hex Code (Only Access Bit)
    static const uint8_t readCoilCode                = 0x01;
    static const uint8_t readDiscreteInputsCode      = 0x02;
    static const uint8_t writeSingleCoilCode         = 0x05;
    static const uint8_t writeMultipleCoilsCode      = 0x0F;
    
    /// @brief ModBus Register Function Hex Code (Only Access 16 Bit)
    static const uint8_t readHoldingRegistersCode    = 0x03;
    static const uint8_t readInputRegisterCode       = 0x04;
    static const uint8_t writeSingleRegisterCode     = 0x06;
    static const uint8_t writeMultipleRegistersCode  = 0x10;
        
    /// @brief Logics...
    void selectCallFunction(uint8_t functionCode);
    
    /// @brief ModBus Master Function
    uint8_t master(uint8_t functionCode);
};

#endif __ModBusMasterManager_h__