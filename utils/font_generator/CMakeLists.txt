# Название таргета
set(target_name font_generator)

# Создаём список файлов
file(GLOB_RECURSE source_files src/*.cpp src/*.hpp)

# Создаём приложение
add_executable(${target_name} ${source_files})

if(NOT DV_WIN32_CONSOLE)
    # Используем точку входа WinMain()
    set_property(TARGET ${target_name} PROPERTY WIN32_EXECUTABLE TRUE)
endif()

# Выводим больше предупреждений
if(MSVC)
    target_compile_options(${target_name} PRIVATE /W4)
else()
    target_compile_options(${target_name} PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Подключаем библиотеки
target_link_libraries(${target_name} PRIVATE dviglo dv_imgui)

# Копируем динамические библиотеки в папку с приложением
dv_copy_shared_libs_to_bin_dir(${target_name})

# Копируем папки с ресурсами движка в result, если нужно
set(dir_names engine_data engine_test_data)
foreach(dir_name ${dir_names})
    dv_create_dir_link(${engine_dir}/result/${dir_name} ${dv_bin_dir}/${dir_name})
endforeach()

# Копируем папки с ресурсами приложения в result, если нужно
#set(dir_names font_generator_data)
#foreach(dir_name ${dir_names})
#    dv_create_dir_link(${CMAKE_CURRENT_SOURCE_DIR}/${dir_name} ${dv_bin_dir}/${dir_name})
#endforeach()

# Добавляем приложение в список тестируемых
add_test(NAME ${target_name} COMMAND ${target_name} -duration 5)

# Заставляем VS отображать дерево каталогов
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR}/src FILES ${source_files})
