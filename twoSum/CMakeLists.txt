cmake_minimum_required(VERSION 3.28)
project(main)
set(CMAKE_CXX_STANDARD 23)


# Определение целей для компиляции файлов модулей
add_library(TestModule_interface OBJECT TestModule_interface.cxx)
add_library(TestModule_implementation OBJECT TestModule_implementation.cxx)

# Определение цели для компиляции main.cpp
add_executable(main main.cpp)

# Установка флагов компиляции для модулей
set_target_properties(TestModule_interface PROPERTIES
        COMPILE_FLAGS "-std=c++23 -fmodules-ts"
)
set_target_properties(TestModule_implementation PROPERTIES
        COMPILE_FLAGS "-std=c++23 -fmodules-ts"
)

# Установка флагов компиляции для основной цели
set_target_properties(main PROPERTIES
        COMPILE_FLAGS "-std=c++23"
)

# Установка зависимостей между целями сборки
add_dependencies(main TestModule_interface TestModule_implementation)

# Линковка всех целей вместе
target_link_libraries(main TestModule_interface TestModule_implementation)

