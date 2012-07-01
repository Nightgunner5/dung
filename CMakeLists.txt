cmake_minimum_required(VERSION 2.8)
project(dung)

add_definitions(-std=c++0x)

add_executable(dung main.cc helper.cc command_look.cc command_save.cc command_location.cc dungtext.cc)