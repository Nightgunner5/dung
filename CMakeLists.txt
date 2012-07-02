cmake_minimum_required(VERSION 2.8)
project(dung)

add_definitions(-std=c++0x)

FIND_PATH(READLINE_INCLUDE_DIR readline/readline.h)
FIND_LIBRARY(READLINE_LIBRARY NAMES readline)

IF (READLINE_INCLUDE_DIR AND READLINE_LIBRARY)
   SET(READLINE_FOUND TRUE)
ENDIF (READLINE_INCLUDE_DIR AND READLINE_LIBRARY)

IF (READLINE_FOUND)
   IF (NOT Readline_FIND_QUIETLY)
      MESSAGE(STATUS "Found GNU readline: ${READLINE_LIBRARY}")
   ENDIF (NOT Readline_FIND_QUIETLY)
ELSE (READLINE_FOUND)
   IF (Readline_FIND_REQUIRED)
      MESSAGE(FATAL_ERROR "Could not find GNU readline")
   ENDIF (Readline_FIND_REQUIRED)
ENDIF (READLINE_FOUND)

add_executable(dung main.cc helper.cc command_look.cc command_save.cc command_location.cc dungtext.cc)
target_link_libraries(dung ${READLINE_LIBRARY})