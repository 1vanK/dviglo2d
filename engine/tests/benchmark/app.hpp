// Copyright (c) the Dviglo project
// License: MIT

#pragma once

#include <dviglo/graphics/sprite_batch.hpp>
#include <dviglo/main/application.hpp>

using namespace dviglo;
using namespace std;


class App : public Application
{
private:
    shared_ptr<Texture> texture_;
    unique_ptr<SpriteBatch> sprite_batch_;
    unique_ptr<SpriteFont> font_;

public:
    App(const vector<StrUtf8>& args);
    ~App() override;

    void setup() override;
    void start() override;
    void handle_sdl_event(const SDL_Event& event) override;
    void update(i64 ns) override;
    void draw() override;

    void on_key(const SDL_KeyboardEvent& event_data);
};
