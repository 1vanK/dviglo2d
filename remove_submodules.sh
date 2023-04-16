#!/bin/sh

set -x # Включаем эхо

repo_dir=$(dirname "$0")

remove_submodule()
{
    git -C "$repo_dir" submodule deinit -f $1
    git -C "$repo_dir" rm -f $1
    rm -rf "$repo_dir/.git/modules/$1"
}

remove_submodule engine/third_party/external/glm/repo
remove_submodule engine/third_party/external/pugixml/repo
remove_submodule engine/third_party/external/sdl/repo
remove_submodule engine/third_party/external/sdl_mixer/repo
remove_submodule engine/third_party/external/stb/repo
remove_submodule third_party/external/entt/repo
