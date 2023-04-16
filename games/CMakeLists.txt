# Папка для экзешников
set(result_dir "${CMAKE_BINARY_DIR}/result")

# Создаём папку result
file(MAKE_DIRECTORY ${result_dir})

# Указываем папку для следующих скомпилированных экзешников
dv_set_bin_dir(${result_dir})

dv_add_all_subdirs()
