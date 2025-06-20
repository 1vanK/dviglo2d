// Copyright (c) the Dviglo project
// License: MIT

#include <dv_force_assert.hpp>

#include <dv_locale.hpp>

#include <iostream>

using namespace std;


void test_common_primitive_types();
void test_math_math();
void test_res_freetype_utils();
void test_std_utils_flags();
void test_std_utils_fs();
void test_std_utils_string();

void run()
{
    test_common_primitive_types();
    test_math_math();
    test_res_freetype_utils();
    test_std_utils_flags();
    test_std_utils_fs();
    test_std_utils_string();
}

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    assert(dviglo::set_utf8_locale());

    run();
    cout << "Все тесты пройдены успешно" << endl;

    return 0;
}
