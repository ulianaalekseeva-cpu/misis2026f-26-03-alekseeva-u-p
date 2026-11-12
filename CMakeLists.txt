cmake_minimum_required(VERSION 3.20)
project(misis2026f-cpp)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ==========================================
# 1. БИБЛИОТЕКИ ДЛЯ ПРОВЕРКИ (complex и rational)
# ==========================================

add_library(complex
    prj.labs/complex/complex.cpp
    prj.labs/complex/complex.h
)
target_include_directories(complex PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/prj.labs/complex)

add_library(rational
    prj.labs/rational/rational.cpp
    prj.labs/rational/rational.h
)
target_include_directories(rational PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/prj.labs/rational)

# ==========================================
# 2. ТВОИ ЛИЧНЫЕ ПРОГРАММЫ (Для запуска вручную)
# ==========================================

# Проверяем, существует ли main.cpp, чтобы не было ошибки, если ты его удалишь
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/prj.labs/complex/main.cpp")
    add_executable(my_complex_main prj.labs/complex/main.cpp)
    target_link_libraries(my_complex_main PRIVATE complex)
endif()

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/prj.labs/rational/main.cpp")
    add_executable(my_rational_main prj.labs/rational/main.cpp)
    target_link_libraries(my_rational_main PRIVATE rational)
endif()

# ==========================================
# 3. АВТОСБОРКА КОДФОРСЕСА
# ==========================================

# Ищем только .cpp файлы в папке prj.codeforces (не заходя в другие папки)
file(GLOB CODEFORCES_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/prj.codeforces/*.cpp")

foreach(src ${CODEFORCES_SOURCES})
    get_filename_component(target_name ${src} NAME_WE)
    # Добавляем префикс cf_, чтобы имена не пересекались
    add_executable(cf_${target_name} ${src})
endforeach()

# ==========================================
# 4. АВТОСБОРКА ТЕСТОВ (ИСПРАВЛЕНО prj.tests вместо prj.test)
# ==========================================

# Если папка с тестами существует, мы её обрабатываем
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/prj.tests")
    file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/prj.tests/*.cpp")
    foreach(src ${TEST_SOURCES})
        get_filename_component(target_name ${src} NAME_WE)
        add_executable(test_${target_name} ${src})
        
        # Тесты должны линковаться с твоими библиотеками
        # Обычно тесты требуют и complex, и rational, но можно добавить проверку по имени
        if(target_name MATCHES "complex")
            target_link_libraries(test_${target_name} PRIVATE complex)
        elseif(target_name MATCHES "rational")
            target_link_libraries(test_${target_name} PRIVATE rational)
        else()
            target_link_libraries(test_${target_name} PRIVATE complex rational)
        endif()
    endforeach()
endif()

# В некоторых системах проверки требуется добавить тесты через CTest
enable_testing()
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/prj.tests")
    file(GLOB TEST_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/prj.tests/*.cpp")
    foreach(src ${TEST_SOURCES})
        get_filename_component(target_name ${src} NAME_WE)
        add_test(NAME ${target_name} COMMAND test_${target_name})
    endforeach()
endif()