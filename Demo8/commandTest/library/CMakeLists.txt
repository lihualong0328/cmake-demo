
set(LIBHELLO_SRC ${CMAKE_CURRENT_SOURCE_DIR}/hello.cpp)
# set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)    # .so store in build/lib

message(STATUS "    library : CMAKE_CURRENT_SOURCE_DIR : ${CMAKE_CURRENT_SOURCE_DIR}")
message(STATUS "    library : PROJECT_BINARY_DIR : ${PROJECT_BINARY_DIR}")


# add_library(<name> [STATIC | SHARED | MODULE]
#            [EXCLUDE_FROM_ALL]
#            source1 [source2 ...])
# MODULE : 在使用dyld的系统有效，如果不支持dyld，则被当作SHARED对待
# EXCLUDE_FROM_ALL : 指库不会被默认构建，除非有其他的组件依赖或手动构建
add_library(hello SHARED ${LIBHELLO_SRC})
add_library(hello_static STATIC ${LIBHELLO_SRC})   # hello作为一个target是不能重名的


# set_target_properties(target1 target2 ...PROPERTIES prop1 value1 prop2 value2 ...)
set_target_properties(hello_static PROPERTIES OUTPUT_NAME "hello") # 希望 "hello_static" 在输出时，不是"hello_static"，而是以"hello"的名字显示
get_target_property(OUTPUT_VALUE hello_static OUTPUT_NAME)
message(STATUS "    hello_static OUTPUT_NAME: " ${OUTPUT_VALUE})    # 如果没 set_target_properties()，返回 NOTFOUND

# cmake在构建一个新的target时，会尝试清理掉其他使用这个名字的库，因此，在构建libhello.a时，就会清理掉libhello.so，为了回避这个问题，比如再次使用SET_TARGET_PROPERTIES定义 CLEAN_DIRECT_OUTPUT属性
set_target_properties(hello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)
set_target_properties(hello PROPERTIES CLEAN_DIRECT_OUTPUT 1)

# VERSION指代动态库版本，SOVERSION指代API版本
set_target_properties(hello PROPERTIES VERSION 1.2 SOVERSION 1)

# 安装到系统目录
#install(TARGETS hello hello_static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)
#install(FILES hello.h DESTINATION include/hello)









