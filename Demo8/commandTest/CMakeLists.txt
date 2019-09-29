
project(use_lib)

set(var_from_commandTest 1)
message(STATUS "    var_from_commandTest : ${var_from_commandTest}")


add_subdirectory(library)
#add_subdirectory(library lib)   # .so store in build/commandTest/lib
add_subdirectory(sentence)
add_subdirectory(variable)

aux_source_directory(. SRCS)

message(STATUS "    ${CMAKE_CURRENT_LIST_FILE} INCLUDE_DIRECTORIES : ${INCLUDE_DIRECTORIES}")
message(STATUS "    ${CMAKE_CURRENT_LIST_FILE} INTERFACE_INCLUDE_DIRECTORIES : ${INTERFACE_INCLUDE_DIRECTORIES}")


#include_directories("${CMAKE_CURRENT_SOURCE_DIR}/library") # instead of find_path
message(STATUS "    ${CMAKE_CURRENT_LIST_FILE} CMAKE_INCLUDE_PATH : ${CMAKE_INCLUDE_PATH}")
find_path(CMAKE_INCLUDE_PATH NAMES hello.h PATHS ${CMAKE_CURRENT_SOURCE_DIR}/library /usr/local/include/hello)
if(CMAKE_INCLUDE_PATH)
    #include_directories("${CMAKE_INCLUDE_PATH}")
    target_include_directories(${PROJECT_NAME} INTERFACE ${CMAKE_INCLUDE_PATH})
endif(CMAKE_INCLUDE_PATH)
message(STATUS "    ${CMAKE_CURRENT_LIST_FILE} CMAKE_INCLUDE_PATH : ${CMAKE_INCLUDE_PATH}")

message(STATUS "    ${CMAKE_CURRENT_LIST_FILE} INCLUDE_DIRECTORIES : ${INCLUDE_DIRECTORIES}")
message(STATUS "    ${CMAKE_CURRENT_LIST_FILE} INTERFACE_INCLUDE_DIRECTORIES : ${INTERFACE_INCLUDE_DIRECTORIES}")


add_executable(${PROJECT_NAME} ${SRCS})
target_link_libraries(${PROJECT_NAME} hello)    # ldd use_lib


# make VERBOSE=1



