cmake_minimum_required(VERSION 3.11)

target_compile_features(${TARGET_NAME} PRIVATE cxx_std_17)

project(
  ModooCode
  VERSION 0.1
  DESCRIPTION "modbus_protocol_tcp_sample"
  LANGUAGES CXX)

add_executable (modbus_sample_sh src/modbus_master_manager.cpp)