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

void ModBusMasterManager::SetSlaveIPAddress(string slaveIPAddress) {
    mSlaveIPAddress = slaveIPAddress;
}

void ModBusMasterManager::ReadCoil(u_int16_t address, u_int16_t count) {
    cout << "Call readCoil!!" << endl;
    masterTransaction(kReadCoilCode, address, count);
}

void ModBusMasterManager::ReadDiscreteInputs(u_int16_t address, u_int16_t count) {
    cout << "Call readDiscreteInputs!!" << endl;
    masterTransaction(kReadDiscreteInputsCode, address, count);
}

void ModBusMasterManager::WriteSingleCoil(u_int16_t address, u_int16_t count) {
    cout << "Call writeSingleCoil!!" << endl;
    masterTransaction(kWriteSingleCoilCode, address, count);
}

void ModBusMasterManager::WriteMultipleCoils(u_int16_t address, u_int16_t count) {
    cout << "Call writeMultipleCoils!!" << endl;
    masterTransaction(kWriteMultipleCoilsCode, address, count);
}

void ModBusMasterManager::ReadHoldingRegisters(u_int16_t address, u_int16_t count) {
    cout << "Call readHoldingRegisters!!" << endl;
    masterTransaction(kReadHoldingRegistersCode, address, count);
}

void ModBusMasterManager::ReadInputRegister(u_int16_t address, u_int16_t count) {
    cout << "Call readInputRegister!!" << endl;
    masterTransaction(kReadInputRegisterCode, address, count);
}

void ModBusMasterManager::WriteSingleRegister(u_int16_t address, u_int16_t count) {
    cout << "Call writeSingleRegister!!" << endl;
    masterTransaction(kWriteSingleRegisterCode, address, count);
}

void ModBusMasterManager::WriteMultipleRegisters(u_int16_t address, u_int16_t count) {
    cout << "Call writeMultipleRegisters!!" << endl;
    masterTransaction(kWriteMultipleRegistersCode, address, count);
}

void ModBusMasterManager::Request(uint8_t functionCode, u_int16_t address, u_int16_t count) {
    /// exchange master <-> slave
}

void ModBusMasterManager::masterTransaction(uint8_t functionCode, u_int16_t address, u_int16_t count) {
    cout << mTransactionId << endl;
    cout << mUnitId << endl;
    cout << mSlaveIPAddress << endl;
    cout << functionCode << endl;
    cout << address << endl;
    cout << count << endl;

    if (mSlaveIPAddress.empty()) {
        /// error
    }

    Request(functionCode, address, count);

    /// if exchange successful?
    UpdateTransactionId(++mTransactionId);
}

/// this main is only for test run...
int main() {
    ModBusMasterManager masterInstance = ModBusMasterManager();
    // ...
    return 0;
}