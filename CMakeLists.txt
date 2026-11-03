cmake_minimum_required(VERSION 3.20)
project(misis2026f-cpp)

set(CMAKE_CXX_STANDARD 20)
# ==========================================
# 1. Старые лабы из папки prj.codeforces
# ==========================================
file(GLOB CODEFORCES_SOURCES "prj.codeforces/*.cpp")

set(INDEX 0)
foreach(src ${CODEFORCES_SOURCES})
    get_filename_component(target_name ${src} NAME_WE)

    # Создаем отдельный исполняемый файл для каждого .cpp
    add_executable(${target_name} ${src})
    
    math(EXPR INDEX "${INDEX} + 1")
endforeach()
# ==========================================
# 2. Лаба с комплексными числами (complex)
# ==========================================
add_library(complex_lib 
    prj.labs/complex/complex.cpp 
    prj.labs/complex/complex.hpp
)
target_include_directories(complex_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/prj.labs/complex)

# Собираем main.cpp для комплексных чисел как отдельный exe
add_executable(complex_main prj.labs/complex/main.cpp)
target_link_libraries(complex_main PRIVATE complex_lib)

# ==========================================
# 3. Лаба с рациональными числами (rational)
# ==========================================
add_library(rational_lib 
    prj.labs/rational/rational.cpp 
    prj.labs/rational/rational.h
)
target_include_directories(rational_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/prj.labs/rational)

# Собираем main.cpp для рациональных чисел как отдельный exe
add_executable(rational_main prj.labs/rational/main.cpp)
target_link_libraries(rational_main PRIVATE rational_lib)