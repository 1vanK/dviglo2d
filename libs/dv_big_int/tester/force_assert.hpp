// Copyright (c) the Dviglo project
// License: MIT

// Этот файл нужно подключать вместо/перед <cassert>

#pragma once

#ifdef assert
    #error "Don't include <cassert>"
#endif

// Макрос NDEBUG определён в конфигурациях Release, RelWithDebInfo, MinSizeRel
// и не определён в конфигурации Debug.
// Макрос NDEBUG отключает assert(): https://en.cppreference.com/w/cpp/error/assert
// Нам же нужно, чтобы assert() был доступен даже в релизных конфигурациях
#undef NDEBUG

#include <cassert>
