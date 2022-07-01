#include "modbus_master_manager.h"

ModBusMasterManager::ModBusMasterManager() {
    mTransactionId = 1;
    mProtocolId = 0;
}

void ModBusMasterManager::UpdateTransactionId(uint16_t transactionId) {
    mTransactionId = transactionId;
}

void ModBusMasterManager::UpdateUnitId(uint8_t unitId) {
    mUnitId = unitId;
}

void ModBusMasterManager::SetSlaveIPAddress(std::string slaveIPAddress) {
    mSlaveIPAddress = slaveIPAddress;
}

void ModBusMasterManager::ReadCoil(u_int16_t coilAddress, u_int16_t coilCount) {
    masterTransaction(kReadCoilCode, coilAddress, coilCount);
}

void ModBusMasterManager::ReadDiscreteInputs(u_int16_t inputAddress, u_int16_t inputCount) {
    masterTransaction(kReadDiscreteInputsCode, inputAddress, inputCount);
}

void ModBusMasterManager::WriteSingleCoil(u_int16_t coilAddress, u_int16_t coilValue) {
    masterTransaction(kWriteSingleCoilCode, coilAddress, coilValue);
}

void ModBusMasterManager::WriteMultipleCoils(u_int16_t registerAddress, u_int16_t registerCount) {
    masterTransaction(kWriteMultipleCoilsCode, registerAddress, registerCount);
}

void ModBusMasterManager::ReadHoldingRegisters(u_int16_t inputAddress, u_int16_t registerCount) {
    masterTransaction(kReadHoldingRegistersCode, inputAddress, registerCount);
}

void ModBusMasterManager::ReadInputRegister(u_int16_t inputAddress, u_int16_t registerCount) {
    masterTransaction(kReadInputRegisterCode, inputAddress, registerCount);
}

void ModBusMasterManager::WriteSingleRegister(u_int16_t registerAddress, u_int16_t registerValue) {
    masterTransaction(kWriteSingleRegisterCode, registerAddress, registerValue);
}

void ModBusMasterManager::WriteMultipleRegisters(u_int16_t registerAddress, u_int16_t registerCount) {
    masterTransaction(kWriteMultipleRegistersCode, registerAddress, registerCount);
}

void ModBusMasterManager::Request(uint8_t functionCode, u_int16_t registerAddress, u_int16_t registerCount) {
    /// exchange master <-> slave
}

void ModBusMasterManager::masterTransaction(uint8_t functionCode, u_int16_t registerAddress, u_int16_t registerCount) {
    std::cout << mTransactionId << std::endl;
    std::cout << mUnitId << std::endl;
    std::cout << mSlaveIPAddress << std::endl;
    std::cout << functionCode << std::endl;
    std::cout << registerAddress << std::endl;
    std::cout << registerCount << std::endl;
    
    if (mSlaveIPAddress.empty()) {
      throw InvalidData();
    }

    Request(functionCode, registerAddress, registerCount);

    /// if exchange successful?
    UpdateTransactionId(++mTransactionId);
}

/// this main is only for test run...
int main() {
    ModBusMasterManager masterInstance = ModBusMasterManager();

    // ...
    return 0;
}