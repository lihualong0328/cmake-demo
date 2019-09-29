
# cmake sentence
message(STATUS "sentence ------------------------------------")
message(STATUS "    var_from_commandTest : ${var_from_commandTest}")
list(APPEND var_from_commandTest 
    2
)   # var_from_commandTest 不能把 2 带到上级目录
set(var_from_commandTest ${var_from_commandTest}
    2
)


# set(<variable> <value>... [PARENT_SCOPE]) # Set Normal Variable, in the current function or directory scope
set(set1 1 2 3)
message(STATUS "    set1 : ${set1}")
# set(<variable> <value>... CACHE <type> <docstring> [FORCE])   # Set Cache Entry

# set(ENV{<variable>} <value>...)   #Set Environment Variable


# MESSAGE([SEND_ERROR | STATUS | FATAL_ERROR] “message to display” …)   # 向终端输出用户定义的信息或变量值
message("message : none")
message(STATUS "message : STATUS")
message(WARNING "message : WARNING")
message(AUTHOR_WARNING "message : AUTHOR_WARNING")
# message(SEND_ERROR "message : SEND_ERROR")
# message(FATAL_ERROR "message : FATAL_ERROR")
message(DEPRECATION "message : DEPRECATION")


# INCLUDE_DIRECTORIES([AFTER|BEFORE] [SYSTEM] dir1 dir2 ...)    # 向工程添加多个特定的头文件搜索路径

