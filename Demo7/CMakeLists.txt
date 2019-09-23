cmake_minimum_required (VERSION 2.8)
project (Demo7)


# --------------------------------------------------------------------------------------------------
# 1.
set (Demo_VERSION_MAJOR 1)
set (Demo_VERSION_MINOR 0)

configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
# 2. config.h.in
# 3. main.cc


# --------------------------------------------------------------------------------------------------
set (CMAKE_INCLUDE_CURRENT_DIR ON)


# --------------------------------------------------------------------------------------------------
# 指定 Debug 模式下开启 -g 选项
set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

message (info "       CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE})
message (info "       CMAKE_CXX_FLAGS_DEBUG: " ${CMAKE_CXX_FLAGS_DEBUG})
message (info "       CMAKE_CXX_FLAGS_RELEASE: " ${CMAKE_CXX_FLAGS_RELEASE})


# --------------------------------------------------------------------------------------------------

include_directories ("${PROJECT_SOURCE_DIR}/math")
add_subdirectory (math)  
set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)


set (CMAKE_INCLUDE_CURRENT_DIR ON)

aux_source_directory(. DIR_SRCS)

add_executable(Demo ${DIR_SRCS})
target_link_libraries (Demo  ${EXTRA_LIBS})
