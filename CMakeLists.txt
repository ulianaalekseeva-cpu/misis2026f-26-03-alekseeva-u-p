cmake_minimum_required(VERSION 3.20)
project(misis2026f-cpp)

set(CMAKE_CXX_STANDARD 20)

# Ищем все cpp файлы
file(GLOB_RECURSE ALL_SOURCES "*.cpp")

# Игнорируем мусорные папки
set(IGNORE_DIRS "out/*" ".vs/*" "build/*" "cmake-build-*/*")

foreach(src ${ALL_SOURCES})
    set(IS_IGNORED FALSE)
    foreach(ignore_dir ${IGNORE_DIRS})
        if(src MATCHES "${ignore_dir}")
            set(IS_IGNORED TRUE)
        endif()
    endforeach()

    if(NOT IS_IGNORED)
        # Берем ТОЛЬКО имя файла (без пути). Например: 0004A или lalala
        get_filename_component(target_name ${src} NAME_WE)
        
        # Если два файла называются одинаково (например, два main.cpp), 
        # добавляем к имени папку, чтобы CMake не ругался на дубликаты.
        if(TARGET ${target_name})
            get_filename_component(parent_dir ${src} DIRECTORY)
            get_filename_component(parent_name ${parent_dir} NAME)
            set(target_name "${parent_name}_${target_name}")
        endif()

        add_executable(${target_name} ${src})
    endif()
endforeach()