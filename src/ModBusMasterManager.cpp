#include "ModBusMasterManager.h"

ModBusMasterManager::ModBusMasterManager()
{
  /// function code sample
  uint8_t functionCode = readCoilCode;
  uint8_t test = master(functionCode);
}

void ModBusMasterManager::send()
{
  /// @brief exchange master <-> slave
}

// todo: send request 할 때 공통화 작업 할 경우, 아래의 function code별 분기 메소드 구조가 바뀔 수 있을 것 같음.
void ModBusMasterManager::readCoil()
{
  cout << "Call readCoil!!" << endl;
}

void ModBusMasterManager::readDiscreteInputs()
{
  cout << "Call readDiscreteInputs!!" << endl;
}

void ModBusMasterManager::writeSingleCoil()
{
  cout << "Call writeSingleCoil!!" << endl;
}

void ModBusMasterManager::writeMultipleCoils()
{
  cout << "Call writeMultipleCoils!!" << endl;
}

void ModBusMasterManager::readHoldingRegisters()
{
  cout << "Call readHoldingRegisters!!" << endl;
}

void ModBusMasterManager::readInputRegister()
{
  cout << "Call readInputRegister!!" << endl;
}

void ModBusMasterManager::writeSingleRegister()
{
  cout << "Call writeSingleRegister!!" << endl;
}

void ModBusMasterManager::writeMultipleRegisters()
{
  cout << "Call writeMultipleRegisters!!" << endl;
}

void ModBusMasterManager::selectCallFunction(uint8_t functionCode)
{
  
  switch (functionCode)
  {
    case readCoilCode:
      readCoil();
      break;
    case readDiscreteInputsCode:
      readDiscreteInputs();
      break;
    case writeSingleCoilCode:
      writeSingleCoil();
      break;
    case writeMultipleCoilsCode:
      writeMultipleCoils();
      break;
    case readInputRegisterCode:
      readInputRegister();
      break;
    case writeSingleRegisterCode:
      writeSingleRegister();
      break;
    case writeMultipleRegistersCode:
      writeMultipleRegisters();
      break;
  }
}

uint8_t ModBusMasterManager::master(uint8_t functionCode)
{
  selectCallFunction(functionCode);
  return successCode;
}

/// this main is only for test run...
int main()
{
  ModBusMasterManager();
  return 0;
}