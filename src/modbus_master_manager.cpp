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

std::tuple<bool, uint8_t, uint8_t, uint16_t, uint16_t, uint16_t, uint16_t> ModBusMasterManager::Request(uint8_t functionCode, u_int16_t registerAddress, u_int16_t registerCount) {
    // todo: exchange master <-> slave response to tuple
    bool isSuccess = true;
    uint8_t length = 0;
    uint8_t unitId = 0;
    uint16_t transactionId = ++mTransactionId;
    uint16_t protocolId = mProtocolId;
    uint16_t bodyLength = 0;
    uint16_t bodyCount = 0;
    
    return std::make_tuple(isSuccess, length, unitId, transactionId, protocolId, bodyLength, bodyCount);
}

void ModBusMasterManager::masterTransaction(uint8_t functionCode, u_int16_t registerAddress, u_int16_t registerCount) {
    if (mSlaveIPAddress.empty()) {
        throw InvalidData();
    }
    
    std::tuple<bool, uint8_t, uint8_t, uint16_t, uint16_t, uint16_t, uint16_t> response;
    response = Request(functionCode, registerAddress, registerCount);
    
    std::cout << "Slave Response" << std::endl;
    std::apply([](auto&&... field) { ((std::cout << field << std::endl), ...); }, response);

    bool isSuccess = std::get<0>(response);
    uint16_t transactionId = std::get<3>(response);

    if (isSuccess) {
        UpdateTransactionId(transactionId);
        std::cout << "mTransactionId" << std::endl;
        std::cout << transactionId << std::endl;
    }
}

/// this main is only for test run...
int main() {
    ModBusMasterManager masterInstance = ModBusMasterManager();
    masterInstance.SetSlaveIPAddress("localhost:3000");
    masterInstance.ReadCoil(2, 30);

    // ...
    return 0;
}