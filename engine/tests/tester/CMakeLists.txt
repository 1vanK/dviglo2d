# Название таргета
set(target_name tester)

# Создаём список файлов
file(GLOB_RECURSE source_files *.cpp *.hpp)

# Создаём консольное приложение
add_executable(${target_name} ${source_files})

# Подключаем библиотеку
target_link_libraries(${target_name} PRIVATE dviglo)

# Копируем динамические библиотеки в папку с приложением
dv_copy_shared_libs_to_bin_dir(${target_name})

# Заставляем VS отображать дерево каталогов
source_group(TREE ${CMAKE_CURRENT_SOURCE_DIR} FILES ${source_files})

# Добавляем приложение в список тестируемых
add_test(NAME ${target_name} COMMAND ${target_name})
