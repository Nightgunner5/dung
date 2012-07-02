cmake_minimum_required(VERSION 2.8)
project(dung)

add_definitions(-std=c++0x)

find_path(READLINE_INCLUDE_DIR readline/readline.h)
find_library(READLINE_LIBRARY NAMES readline)

IF(READLINE_INCLUDE_DIR AND READLINE_LIBRARY)
  message(STATUS "Found GNU readline: ${READLINE_LIBRARY}")
else (READLINE_INCLUDE_DIR AND READLINE_LIBRARY)
  message(FATAL_ERROR "Could not find GNU readline")
endif(READLINE_INCLUDE_DIR AND READLINE_LIBRARY)

add_executable(dung main.cc helper.cc dungtext.cc
		    command_look.cc command_save.cc command_location.cc command_generic.cc
		    storyline_test.cc)
target_link_libraries(dung ${READLINE_LIBRARY})