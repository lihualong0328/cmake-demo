<!--
 * @Description: 
* @Copyright(c) 2019 enst.org.cn. All rights reserved.
 * @version: 1.0.0.1
* @Filename:
 * @Author: lihualong
 * @Date: 2019-09-25 15:18:36
 * @LastEditors: lihualong
 * @LastEditTime: 2019-09-27 19:02:58
 -->

# 查找并使用其他程序库
* 先找到 lib 的头文件 & 链接库所在目录以便生成编译选项
* Findlibdb_cxx.cmake 的语法与 CMakeLists.txt 相同
1. 库说明文件。在根目录创建目录 cmake/modules/Findlibdb_cxx.cmake ，内容如下:
```
MESSAGE(STATUS "Using bundled Findlibdb.cmake...")
FIND_PATH(
  LIBDB_CXX_INCLUDE_DIR
  db_cxx.h 
  /usr/include/ 
  /usr/local/include/ 
  )
IF(LIBDB_CXX_INCLUDE_DIR)
  INCLUDE_DIRECTORIES(${LIBDB_CXX_INCLUDE_DIR})
ENDIF(LIBDB_CXX_INCLUDE_DIR)

FIND_LIBRARY(
  LIBDB_CXX_LIBRARIES NAMES
  db_cxx
  PATHS /usr/lib/ /usr/local/lib/
  )
```
* find_path(<VAR> name1 [path1 path2 ...]) 该命令在参数 path* 指示的目录中查找文件 name1 并将查找到的路径保存在变量 VAR中

2. 根目录中的 CmakeList.txt
SET(CMAKE_MODULE_PATH ${CMAKE_ROOT}/Modules ${CMAKE_SOURCE_DIR}/cmake/modules)

AUX_SOURCE_DIRECTORY(. DIR_SRCS)
ADD_EXECUTABLE(main ${DIR_SRCS})

FIND_PACKAGE(libdb_cxx REQUIRED)  # 到 CMAKE_MODULE_PATH 指示的目录中查找 Findlibdb_cxx.cmake 并执行
MARK_AS_ADVANCED(
  LIBDB_CXX_INCLUDE_DIR
  LIBDB_CXX_LIBRARIES
)

IF (LIBDB_CXX_INCLUDE_DIR AND LIBDB_CXX_LIBRARIES)  # 若已被赋值
  MESSAGE(STATUS "Found libdb libraries")
  INCLUDE_DIRECTORIES(${LIBDB_CXX_INCLUDE_DIR})
  MESSAGE( ${LIBDB_CXX_LIBRARIES} )
  TARGET_LINK_LIBRARIES(main ${LIBDB_CXX_LIBRARIES})
ENDIF (LIBDB_CXX_INCLUDE_DIR AND LIBDB_CXX_LIBRARIES)













