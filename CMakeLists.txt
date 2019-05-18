# CMakeList.txt: memory_revise 的 CMake 项目，在此处包括源代码并定义
# 项目特定的逻辑。

#要求CMake的最低版本为2.8
cmake_minimum_required (VERSION 3.8)

# 将源代码添加到此项目的可执行文件。
add_executable (win_main
"src/main.cpp"
"src/win_dlg.h"
"src/win_dlg.cpp"
"src/main_dlg.h"
"src/main_dlg.cpp"
)

#设置版本号
set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
 
#设置宏定义
add_definitions(-DDEBUG)

#设置输出目录
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin/)
#增加子项目目录
#ADD_SUBDIRECTORY(lib)

IF (WIN32)

message(STATUS "current platform: win32 ")
#添加头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include F:/cplusplus/shared/include)
#添加库文件搜索路径
link_directories(${PROJECT_SOURCE_DIR}/lib F:/cplusplus/shared/lib)

#SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} /Od /W3 /std:c++latest")
#SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} /O2 /W3 /std:c++latest")

ELSEIF (UNIX)

message(STATUS "current platform: Linux ")
#SET(CMAKE_CXX_COMPILER /usr/local/bin/g++)
#添加头文件搜索路径
include_directories(${PROJECT_SOURCE_DIR}/include /opt/boost)
#添加库文件搜索路径
link_directories(${PROJECT_SOURCE_DIR}/lib /opt/boost/lib)

SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -O0 -Wall -g2")
SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -O3 -Wall -g2")

ENDIF ()
 
include(CheckIncludeFiles)
check_include_files(unistd.h HAVE_INCLUDE_UNISTD)
IF (NOT HAVE_INCLUDE_UNISTD)
message(STATUS "unistd.h: not found")
ENDIF()
 
#INCLUDE (CheckFunctionExists)
#CHECK_FUNCTION_EXISTS()
#INCLUDE(CheckLibraryExists)
#CHECK_LIBRARY_EXISTS(volmgt volmgt_running "" HAVE_VOLMGT)
#CONFIGURE_FILE("${PROJECT_SOURCE_DIR}/config.h.in" "${PROJECT_BINARY_DIR}/src/config.h")
  
#用于将当前目录下的所有源文件的名字保存在变量 DIR_SRCS 中
#AUX_SOURCE_DIRECTORY(./src/ DIR_SRCS)
  
#用于指定从一组源文件 source1 source2 … sourceN(在变量DIR_SRCS中定义)
#编译出一个可执行文件且命名为CMake_Tutorial1 
#ADD_EXECUTABLE(${TARGET} ${DIR_SRCS})

#添加动态库  
#ADD_LIBRARY(${TARGET}_shared SHARED ${DIR_SRCS})  
#添加静态库  
#ADD_LIBRARY(${TARGET}_static STATIC ${DIR_SRCS})
 
#添加编译可执行程序所需要的链接库、如果有多个中间用空格隔开
#第一个参数是可执行程序名称，第二个开始是依赖库 
#在这里根据名字boost_thread去寻找libboost_thread.a文件
#TARGET_LINK_LIBRARIES(memory_revise)

#SET(CMAKE_BUILD_TYPE "Debug") 
SET(CMAKE_EXE_LINKER_FLAGS "/Od /W3 /std:c++latest") 
