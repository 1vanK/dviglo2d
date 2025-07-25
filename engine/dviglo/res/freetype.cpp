// Copyright (c) the Dviglo project
// License: MIT

#include "freetype.hpp"

#include <dv_log.hpp>


namespace dviglo
{

FreeType::FreeType()
{
    assert(!instance_);

    FT_Error error = FT_Init_FreeType(&library_);
    if (error)
        Log::writef_error("{} | FT_Init_FreeType(...) error {}", DV_FUNC_SIG, error);

    instance_ = this;
    Log::write_debug("FreeType constructed");
}

FreeType::~FreeType()
{
    instance_ = nullptr;

    if (library_)
    {
        FT_Error error = FT_Done_FreeType(library_);
        if (error)
            Log::writef_error("{} | FT_Done_FreeType(...) error {}", DV_FUNC_SIG, error);
    }

    Log::write_debug("FreeType destructed");
}

} // namespace dviglo
