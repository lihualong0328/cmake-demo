# CMake 最低版本号要求
cmake_minimum_required (VERSION 2.8)

# 项目信息
project (Demo5)

# 查找当前目录下的所有源文件，并将名称保存到 DIR_SRCS 变量
aux_source_directory(. DIR_SRCS)


# --------------------------------------------------------------------------------------------------
message (info "       CMAKE_INCLUDE_CURRENT_DIR: " ${CMAKE_INCLUDE_CURRENT_DIR})
set (CMAKE_INCLUDE_CURRENT_DIR ON)

# 加入一个配置头文件，用于处理 CMake 对源码的设置。这样可以通过预定义一些参数和变量来控制代码生成
# 不直接编写config.h，为了方便从 CMakeLists.txt 中导入配置，编写一个 config.h.in，config.h由 CMake 从 config.h.in 生成
configure_file (
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )


# 是否使用自己的 MathFunctions 库，添加了一个 自定义编译选项 USE_MYMATH，默认值为 ON
option (USE_MYMATH "Use provided math implementation" ON)

# 是否加入 MathFunctions 库
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/math")  # 提供了一个搜索头文件暂时的根目录
  add_subdirectory (math) # 添加 math 子目录
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)


# 1. 检查系统环境，例如要用一个平台相关特性时。检查系统是否自带pow()
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake) # 添加 CheckFunctionExists 宏
check_function_exists (pow HAVE_POW)  # 测试链接器是否能在链接阶段找到 pow()
# 2. 预定义相关宏变量，见 config.h.in 
# 3. 在代码中使用宏和函数，见 main.cc

# 是否加入 MathFunctions 库
if (NOT HAVE_POW)
  message (info "       HAVE_POW: " ${HAVE_POW})
  #include_directories ("${PROJECT_SOURCE_DIR}/math")
  #add_subdirectory (math)
  #set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (NOT HAVE_POW)


# --------------------------------------------------------------------------------------------------
# 指定生成目标
add_executable (Demo ${DIR_SRCS})
target_link_libraries (Demo  ${EXTRA_LIBS})


# --------------------------------------------------------------------------------------------------
message (info "       CMAKE_INSTALL_PREFIX: " ${CMAKE_INSTALL_PREFIX})
set (CMAKE_INSTALL_PREFIX ${PROJECT_BINARY_DIR}/install)
message (info "       CMAKE_INSTALL_PREFIX: " ${CMAKE_INSTALL_PREFIX})

# 指定安装路径
install (TARGETS Demo DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h"
         DESTINATION include)


# --------------------------------------------------------------------------------------------------
# 启用测试，CMake 提供 CTest 测试工具
enable_testing()

# 测试1 : 测试程序是否成功运行并返回 0 值
add_test (test_run Demo 5 2)

# 测试帮助信息是否可以正常提示
add_test (test_usage Demo)
set_tests_properties (test_usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent") # PASS_REGULAR_EXPRESSION 测试输出是否包含后面跟着的字符串

# 测试2 : 测试 5 的平方
# add_test (test_5_2 Demo 5 2)
# set_tests_properties (test_5_2
#  PROPERTIES PASS_REGULAR_EXPRESSION "is 25")

# 测试3 : 测试 10 的 5 次方
# add_test (test_10_5 Demo 10 5)
# set_tests_properties (test_10_5
#  PROPERTIES PASS_REGULAR_EXPRESSION "is 100000")

# 测试4 : 测试 2 的 10 次方
# add_test (test_2_10 Demo 2 10)
# set_tests_properties (test_2_10
#  PROPERTIES PASS_REGULAR_EXPRESSION "is 1024")


# 测试更多的输入数据，像上面那样一个个写测试用例太繁琐。可通过编写宏来实现
# 定义一个宏，用来简化测试工作
macro (do_test arg1 arg2 result)
  add_test (test_${arg1}_${arg2} Demo ${arg1} ${arg2})
  set_tests_properties (test_${arg1}_${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

# 利用 do_test 宏，测试一系列数据
do_test (5 2 "is 25")
do_test (10 5 "is 100000")
do_test (2 10 "is 1024")





