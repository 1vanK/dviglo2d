// Copyright (c) the Dviglo project
// License: MIT

#include <dv_force_assert.hpp>

#include <dv_locale.hpp>
#include <iostream>


void test_fs();

void run()
{
    test_fs();
}

int main(int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    assert(dviglo::set_utf8_locale());

    run();
    std::cout << "Все тесты пройдены успешно" << std::endl;

    return 0;
}
