cmake_minimum_required (VERSION 2.8)

project (Demo8) # PROJECT(projectname [CXX] [C] [Java]), 指定工程支持的语言, 默认支持所有语言
set (Demo_VERSION_MAJOR 1)
set (Demo_VERSION_MINOR 0)

set (CMAKE_INCLUDE_CURRENT_DIR ON)

# 检查系统是否支持 pow()
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (pow HAVE_POW)

# 加入一个配置头文件，用于处理 CMake 对源码的设置
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

if (NOT HAVE_POW)
  include_directories ("${PROJECT_SOURCE_DIR}/math")
  add_subdirectory (math)  
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (NOT HAVE_POW)



# 查找当前目录下的所有源文件，并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

include_directories ("${PROJECT_SOURCE_DIR}/commandTest")
add_subdirectory (commandTest)
#add_subdirectory(commandTest/library lib)  # .so store in build/lib


message(info "  1 DIR_SRCS : ${DIR_SRCS}")

add_executable(Demo ${DIR_SRCS})
target_link_libraries(Demo ${EXTRA_LIBS})

install (TARGETS Demo DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h"
         DESTINATION include)


# --------------------------------------------------------------------------------------------------
# 构建一个 CPack 安装包（需要依赖 install 模块）
include (InstallRequiredSystemLibraries)  # 导入 InstallRequiredSystemLibraries 模块，以便之后导入 CPack 模块
set (CPACK_RESOURCE_FILE_LICENSE
  "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")  # 设置一些 CPack 相关变量，包括版权信息和版本信息
set (CPACK_PACKAGE_VERSION_MAJOR "${Demo_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Demo_VERSION_MINOR}")
include (CPack) # 导入 CPack 模块
