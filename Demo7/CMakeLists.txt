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
# CMAKE_BUILD_TYPE ，可以取值: Debug & Release & RelWithDebInfo & MinSizeRel
# CMAKE_BUILD_TYPE == Debug 时, CMake 会用变量 CMAKE_CXX_FLAGS_DEBUG 和 CMAKE_C_FLAGS_DEBUG 中的字符串作编译选项生成 Makefile 
# CMAKE_BUILD_TYPE == Release 时, 用变量 CMAKE_CXX_FLAGS_RELEASE 和 CMAKE_C_FLAGS_RELEASE 选项生成 Makefile
#set(CMAKE_BUILD_TYPE "Debug")
set(CMAKE_BUILD_TYPE Debug CACHE STRING "set build type to debug")  # 貌似不管用
#set(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g -ggdb")
#set(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall")

message (info "       CMAKE_BUILD_TYPE: " ${CMAKE_BUILD_TYPE})
message (info "       CMAKE_CXX_FLAGS_DEBUG: " ${CMAKE_CXX_FLAGS_DEBUG})
message (info "       CMAKE_CXX_FLAGS_RELEASE: " ${CMAKE_CXX_FLAGS_RELEASE})

# or
# mkdir Release  
# cd Release  
# cmake -DCMAKE_BUILD_TYPE=Release .. 或 gui 中设置 CMAKE_BUILD_TYPE
# make  

# --------------------------------------------------------------------------------------------------

include_directories ("${PROJECT_SOURCE_DIR}/math")
add_subdirectory (math)  
set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)

aux_source_directory(. DIR_SRCS)

add_executable(Demo ${DIR_SRCS})
target_link_libraries (Demo  ${EXTRA_LIBS})
