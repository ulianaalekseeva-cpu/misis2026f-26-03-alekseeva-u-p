cmake_minimum_required(VERSION 3.20)
project(misis2026f-cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==========================================
# 1. БИБЛИОТЕКИ ДЛЯ ПРОВЕРКИ (complex и rational)
# ==========================================

add_library(complex
    prj.labs/complex/complex.cpp
    prj.labs/complex/complex.hpp
)
target_include_directories(complex PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/prj.labs/complex)

add_library(rational
    prj.labs/rational/rational.cpp
    prj.labs/rational/rational.hpp
)
target_include_directories(rational PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/prj.labs/rational)

# --- ИСПРАВЛЕННЫЙ БЛОК ДЛЯ STACK ---
# Стек шаблонный, поэтому делаем его header-only (INTERFACE)
add_library(stack INTERFACE)
target_include_directories(stack INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/prj.labs/stack)
target_sources(stack INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}/prj.labs/stack/stack.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/prj.labs/stack/stack.cpp
)
# ----------------------------------

# ==========================================
# 2. ТВОИ ЛИЧНЫЕ ПРОГРАММЫ (Для запуска вручную)
# ==========================================


# ==========================================
# 3. АВТОСБОРКА КОДФОРСЕСА
# ==========================================

file(GLOB CODEFORCES_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/prj.codeforces/*.cpp")

foreach(src ${CODEFORCES_SOURCES})
    get_filename_component(target_name ${src} NAME_WE)
    add_executable(cf_${target_name} ${src})
endforeach()

# ==========================================
# 4. АВТОСБОРКА ТЕСТОВ
# ==========================================

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/prj.tests")
    file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/prj.tests/*.cpp")
    foreach(src ${TEST_SOURCES})
        get_filename_component(target_name ${src} NAME_WE)
        add_executable(test_${target_name} ${src})
        
        if(target_name MATCHES "complex")
            target_link_libraries(test_${target_name} PRIVATE complex)
        elseif(target_name MATCHES "rational")
            target_link_libraries(test_${target_name} PRIVATE rational)
		elseif(target_name MATCHES "stack")
            target_link_libraries(test_${target_name} PRIVATE stack)
        else()
            target_link_libraries(test_${target_name} PRIVATE complex rational stack)
        endif()
    endforeach()
endif()

enable_testing()
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/prj.tests")
    file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/prj.tests/*.cpp")
    foreach(src ${TEST_SOURCES})
        get_filename_component(target_name ${src} NAME_WE)
        add_test(NAME ${target_name} COMMAND test_${target_name})
    endforeach()
endif()