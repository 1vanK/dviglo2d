# Указываем минимальную версию CMake
include(cmake/cmake_min_version.cmake)
cmake_minimum_required(VERSION ${dv_cmake_min_version})

# Название проекта
project(dviglo)

option(DV_APPS "Приложения для движка" FALSE)

include(cmake/common.cmake)

add_subdirectory(third_party)
add_subdirectory(dviglo)

if(DV_APPS)
    add_subdirectory(apps)
endif()
