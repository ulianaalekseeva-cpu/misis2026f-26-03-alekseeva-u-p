cmake_minimum_required(VERSION 3.20)
project(misis2026f-cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==========================================
# 1. ОБЫЧНЫЕ БИБЛИОТЕКИ (complex и rational)
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

# ==========================================
# 2. ШАБЛОННЫЕ БИБЛИОТЕКИ (стек на массиве, стек на списке, очередь)
# ==========================================
# Делаем их обычными библиотеками, так как у нас есть .cpp файлы
# с явной инстанциацией (template class ...;) в конце.

# Стек на массиве (папка stacka)
add_library(stacka
    prj.labs/stacka/stacka.cpp
    prj.labs/stacka/stacka.hpp
)
target_include_directories(stacka PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/prj.labs/stacka)

# Стек на списке (папка stackl)
add_library(stackl
    prj.labs/stackl/stackl.cpp
    prj.labs/stackl/stackl.hpp
)
target_include_directories(stackl PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/prj.labs/stackl)

# Очередь (папка queuea)
add_library(queuea
    prj.labs/queuea/queuea.cpp
    prj.labs/queuea/queuea.hpp
)
target_include_directories(queuea PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/prj.labs/queuea)

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
        
        # Умная линковка: смотрим, что тестируем, и линкуем только нужное
        if(target_name MATCHES "complex")
            target_link_libraries(test_${target_name} PRIVATE complex)
        elseif(target_name MATCHES "rational")
            target_link_libraries(test_${target_name} PRIVATE rational)
        elseif(target_name MATCHES "stacka")
            target_link_libraries(test_${target_name} PRIVATE stacka)
        elseif(target_name MATCHES "stackl")
            target_link_libraries(test_${target_name} PRIVATE stackl)
        elseif(target_name MATCHES "queuea")
            target_link_libraries(test_${target_name} PRIVATE queuea)
        else()
            # Если название теста не подошло, линкуем всё (на всякий случай)
            target_link_libraries(test_${target_name} PRIVATE complex rational stacka stackl queuea)
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