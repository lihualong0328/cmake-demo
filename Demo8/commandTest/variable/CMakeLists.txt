
# cmake 内置变量
message(STATUS "cmake build-in variable ------------------------------------")
message(STATUS "    variable : CMAKE_BUILD_TYPE : ${CMAKE_BUILD_TYPE}")   # cmake -DCMAKE_BUILD_TYPE=DEBUG(RELEASE)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m32")
message(STATUS "    variable : CMAKE_C_FLAGS : ${CMAKE_C_FLAGS}")   # set compiler for c
message(STATUS "    variable : CMAKE_CXX_FLAGS : ${CMAKE_CXX_FLAGS}")   # set compiler for c++
message(STATUS "    variable : BUILD_SHARED_LIBS : ${BUILD_SHARED_LIBS}")   # set the default value when using ADD_LIBRARY()，如果未进行设置,使用ADD_LIBRARY时又没有指定库类型,默认编译生成的库都是静态库

message(STATUS "    variable : CMAKE_INCLUDE_CURRENT_DIR : ${CMAKE_INCLUDE_CURRENT_DIR}")   # equal to INCLUDE_DIRECTORY(${CMAKE_CURRENT_BINARY_DIR} ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "    variable : CMAKE_CURRENT_BINARY_DIR : ${CMAKE_CURRENT_BINARY_DIR}") # ADD_SURDIRECTORY(src bin)可更改此变量的值，SET(EXECUTABLE_OUTPUT_PATH <新路径>)不影响此变量，只改变最终目标文件的存储路径
message(STATUS "    variable : CMAKE_CURRENT_SOURCE_DIR : ${CMAKE_CURRENT_SOURCE_DIR}")    # 指当前处理的 CMakeLists.txt 所在路径
message(STATUS "    variable : CMAKE_BINARY_DIR : ${CMAKE_BINARY_DIR}") # 内部编译指工程顶级目录；外部编译指工程编译发生的目录
message(STATUS "    variable : PROJECT_BINARY_DIR : ${PROJECT_BINARY_DIR}") # 同 CMAKE_BINARY_DIR
message(STATUS "    variable : _BINARY_DIR : ${_BINARY_DIR}")   # 同 CMAKE_BINARY_DIR
message(STATUS "    variable : CMAKE_SOURCE_DIR : ${CMAKE_SOURCE_DIR}") # 工程顶级目录
message(STATUS "    variable : PROJECT_SOURCE_DIR : ${PROJECT_SOURCE_DIR}") # 同 CMAKE_SOURCE_DIR
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")   # 同 CMAKE_SOURCE_DIR
message(STATUS "    variable : CMAKE_CURRENT_LIST_DIR : ${CMAKE_CURRENT_LIST_DIR}")
message(STATUS "    variable : CMAKE_CURRENT_LIST_LINE : ${CMAKE_CURRENT_LIST_LINE}")
message(STATUS "    variable : CMAKE_CURRENT_LIST_FILE : ${CMAKE_CURRENT_LIST_FILE}")

message(STATUS "    variable : CMAKE_MODULE_PATH : ${CMAKE_MODULE_PATH}")   # 工程复杂时需要编写一些cmake模块
message(STATUS "    variable : LIBRARY_OUTPUT_DIR : ${LIBRARY_OUTPUT_DIR}")
message(STATUS "    variable : BINARY_OUTPUT_DIR : ${BINARY_OUTPUT_DIR}")
message(STATUS "    variable : CMAKE_MODULE_PATH : ${CMAKE_MODULE_PATH}")
message(STATUS "    variable : CMAKE_ROOT : ${CMAKE_ROOT}")
message(STATUS "    variable : EXECUTABLE_OUTPUT_PATH : ${EXECUTABLE_OUTPUT_PATH}") # 重新定义目标二进制可执行文件的存放位置
message(STATUS "    variable : LIBRARY_OUTPUT_PATH : ${LIBRARY_OUTPUT_PATH}")   # 重新定义目标链接库文件的存放位置
message(STATUS "    variable : CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS : ${CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS}")   # 控制IF ELSE语句的书写方式
message(STATUS "    variable : CMAKE_MAJOR_VERSION : ${CMAKE_MAJOR_VERSION}")
message(STATUS "    variable : CMAKE_MINOR_VERSION : ${CMAKE_MINOR_VERSION}")
message(STATUS "    variable : CMAKE_PATCH_VERSION : ${CMAKE_PATCH_VERSION}")
message(STATUS "    variable : CMAKE_SYSTEM : ${CMAKE_SYSTEM}")
message(STATUS "    variable : CAMKE_SYSTEM_NAME : ${CAMKE_SYSTEM_NAME}")
message(STATUS "    variable : CMAKE_SYSTEM_VERSION : ${CMAKE_SYSTEM_VERSION}")
message(STATUS "    variable : CMAKE_SYSTEM_PROCESSOR : ${CMAKE_SYSTEM_PROCESSOR}")
message(STATUS "    variable : UNIX : ${UNIX}") # 在所有的类UNIX平台为TRUE,包括OS X和cygwin
message(STATUS "    variable : WIN32 : ${WIN32}")   # 在所有的win32平台为TRUE,包括cygwin

message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")
message(STATUS "    variable : _SOURCE_DIR : ${_SOURCE_DIR}")




#message(STATUS "   1_2 DIR_SRCS : ${DIR_SRCS}")

#list(APPEND DIR_SRCS 
#    Test.cpp
#)
#message(STATUS "   1_3 DIR_SRCS : ${DIR_SRCS}")

#message(STATUS "   ${PWD} DIR_SRCS : ${DIR_SRCS}")

# 系统环境变量
message(STATUS "system environment variable ------------------------------------")
message(STATUS "    variable : PWD : $ENV{PWD}")
message(STATUS "    variable : PATH : $ENV{PATH}")
set(ENV{PATH} $ENV{PATH}:.)
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : CMAKE_INCLUDE_PATH : $ENV{CMAKE_INCLUDE_PATH}")
message(STATUS "    variable : CMAKE_LIBRARY_PATH : $ENV{CMAKE_LIBRARY_PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")
message(STATUS "    variable : PATH : $ENV{PATH}")





