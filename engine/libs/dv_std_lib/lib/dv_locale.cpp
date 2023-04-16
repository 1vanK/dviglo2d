// Copyright (c) the Dviglo project
// License: MIT

#include "dv_locale.hpp"

#include "dv_platform.hpp"

#if DV_WINDOWS
    #include <cassert>
    #include <filesystem> // std::filesystem::path
#endif

#include <iostream>


namespace dviglo
{

bool set_utf8_locale()
{
#if DV_WINDOWS
    char* val = std::setlocale(LC_CTYPE, ".UTF-8");
    assert(val && std::filesystem::path("тест").native() == L"тест");
#elif DV_LINUX
    char* val = std::setlocale(LC_CTYPE, "C.UTF-8");
#endif

    return static_cast<bool>(val);
}

} // namespace dviglo
