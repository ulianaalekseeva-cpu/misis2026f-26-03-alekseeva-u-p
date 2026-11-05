cmake_minimum_required(VERSION 3.20)
project(misis2026f-cpp)

set(CMAKE_CXX_STANDARD 20)

# ==========================================
# 1. БИБЛИОТЕКИ ДЛЯ ПРОВЕРКИ (Обязательно!)
# ==========================================
# Проверяющая система ищет библиотеки с именами "complex" и "rational".
# Поэтому мы собираем их СТРОГО как библиотеки, а не как программы.

add_library(complex 
    prj.labs/complex/complex.cpp 
    prj.labs/complex/complex.hpp
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
# Теперь, чтобы ты могла запустить свои main.cpp, мы делаем для них отдельные exe.
# Называем их с префиксом "my_", чтобы не конфликтовать с проверкой.

add_executable(my_complex_main prj.labs/complex/main.cpp)
target_link_libraries(my_complex_main PRIVATE complex)

add_executable(my_rational_main prj.labs/rational/main.cpp)
target_link_libraries(my_rational_main PRIVATE rational)

# ==========================================
# 3. АВТОСБОРКА КОДФОРСЕСА (Только папка prj.codeforces)
# ==========================================
# Мы УБРАЛИ GLOB_RECURSE по всему проекту! Теперь он смотрит только в prj.codeforces.
# Иначе он залезет в prj.check и сломает всё.

file(GLOB CODEFORCES_SOURCES "prj.codeforces/*.cpp")

foreach(src ${CODEFORCES_SOURCES})
    get_filename_component(target_name ${src} NAME_WE)
    # Добавляем префикс cf_, чтобы имена точно не пересеклись
    add_executable(cf_${target_name} ${src})
endforeach()