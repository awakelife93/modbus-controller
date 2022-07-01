cmake_minimum_required(VERSION 3.11)

project(
  ModooCode
  VERSION 0.1
  DESCRIPTION "Modbus_sample"
  LANGUAGES CXX)

add_executable (modbus_sample_sh src/modbus_master_manager.cpp)