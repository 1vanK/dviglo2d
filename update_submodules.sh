#!/bin/sh

# Обновляет подмодули до последних версий

set -x # Включаем эхо

repo_dir=$(dirname "$0")

# Переключаем ветку SDL_mixer на новую
sm_path=engine/third_party/external/sdl_mixer/repo
sm_branch=dv_2024_11_06
git -C "$repo_dir" config -f .gitmodules submodule.$sm_path.branch $sm_branch
git -C "$repo_dir" submodule sync

git -C "$repo_dir" submodule update --remote --recursive
