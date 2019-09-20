# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo4)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

# 是否使用自己的 MathFunctions 库，添加了一个 USE_MYMATH 选项，默认值为 ON
option (USE_MYMATH
	   "Use provided math implementation" ON)

# 加入一个配置头文件，用于处理 CMake 对源码的设置。这样可以通过预定义一些参数和变量来控制代码生成
# 不直接编写config.h，为了方便从 CMakeLists.txt 中导入配置，编写一个 config.h.in，config.h由 CMake 从 config.h.in 生成
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

# 是否加入 MathFunctions 库
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/math")
  add_subdirectory (math)
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)

# 查找当前目录下的所有源文件，并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable (Demo ${DIR_SRCS})
target_link_libraries (Demo  ${EXTRA_LIBS})
