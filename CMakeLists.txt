cmake_minimum_required(VERSION 3.10)  # 指定CMake的最低版本要求

# 设置项目名称和版本
project(Fytinu VERSION 1.0)

# 指定C++标准
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 添加要编译的可执行文件
add_executable(${PROJECT_NAME} src/main.cpp)

# 如果有需要链接的库，在这里指定
# target_link_libraries(YourExecutableName SomeLibrary)