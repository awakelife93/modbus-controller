#include "iostream"
#include "ModBusController.h"

using namespace std;

ModBusController::ModBusController()
{
  /// function code sample
  uint8_t functionCode = readCoilCode;
  uint8_t test = master(functionCode);
}

// todo: send request 할 때 공통화 작업 할 경우, 아래의 function code별 분기 메소드 구조가 바뀔 수 있을 것 같음.
void ModBusController::readCoil()
{
  cout << "Call readCoil!!" << endl;
}

void ModBusController::readDiscreteInputs()
{
  cout << "Call readDiscreteInputs!!" << endl;
}

void ModBusController::writeSingleCoil()
{
  cout << "Call writeSingleCoil!!" << endl;
}

void ModBusController::writeMultipleCoils()
{
  cout << "Call writeMultipleCoils!!" << endl;
}

void ModBusController::readHoldingRegisters()
{
  cout << "Call readHoldingRegisters!!" << endl;
}

void ModBusController::readInputRegister()
{
  cout << "Call readInputRegister!!" << endl;
}

void ModBusController::writeSingleRegister()
{
  cout << "Call writeSingleRegister!!" << endl;
}

void ModBusController::writeMultipleRegisters()
{
  cout << "Call writeMultipleRegisters!!" << endl;
}

void ModBusController::selectCallFunction(uint8_t functionCode)
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

uint8_t ModBusController::master(uint8_t functionCode)
{
  selectCallFunction(functionCode);
  return successCode;
}

/// this main is only for test run...
void main()
{
  ModBusController();
}