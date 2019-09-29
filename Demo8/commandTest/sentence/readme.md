<!--
 * @Description: 
* @Copyright(c) 2019 enst.org.cn. All rights reserved.
 * @version: 1.0.0.1
* @Filename:
 * @Author: lihualong
 * @Date: 2019-09-26 14:27:38
 * @LastEditors: lihualong
 * @LastEditTime: 2019-09-27 19:07:31
 -->

# target_link_libraries(<target>
#                      <PRIVATE|PUBLIC|INTERFACE> <item>...
#                     [<PRIVATE|PUBLIC|INTERFACE> <item>...]...)
1. If you are creating a shared library and your source cpp files #include the headers of another library (Say, QtNetwork for example), but your header files don't include QtNetwork headers, then QtNetwork is a PRIVATE dependency.
2. If your source files and your headers include the headers of another library, then it is a PUBLIC dependency.
3. If your header files but not your source files include the headers of another library, then it is an INTERFACE dependency.
4. Other build properties of PUBLIC and INTERFACE dependencies are propagated to consuming libraries. http://www.cmake.org/cmake/help/v3.0/manual/cmake-buildsystem.7.html#transitive-usage-requirements



1. include_directories(x/y) affects directory scope. All targets in this CMakeList, as well as those in all subdirectories added after the point of its call, will have the path x/y added to their include path.
2. target_include_directories(t x/y) has target scope—it adds x/y to the include path for target t.
3. You want the former one if all of your targets use the include directories in question. You want the latter one if the path is specific to a target, or if you want finer control of the path's visibility. The latter comes from the fact that target_include_directories() supports the PRIVATE, PUBLIC, and INTERFACE qualifiers.
* target_include_directories(<target> [SYSTEM] [BEFORE]
  <INTERFACE|PUBLIC|PRIVATE> [items1...]
  [<INTERFACE|PUBLIC|PRIVATE> [items2...] ...])
    * INTERFACE|PUBLIC|PRIVATE : 指定 items* 的参数作用域
    * PRIVATE和PUBLIC项会填充targe目标文件的INCLUDE_DIRECTORIES属性
    * PUBLIC和INTERFACE项会填充target目标文件的INTERFACE_INCLUDE_DIRECTORIES属性

#set_target_properties(Thirdlib PROPERTIES IMPORTED_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/jniLibs/libThirdlib.so)
1. use & import 3rd lib 


# add_subdirectory(lib) # 指定一个编译输出位置，build/lib
# add_subdirectory(lib lib_new) # build/lib_new
