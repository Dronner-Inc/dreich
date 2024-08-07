#include "game/worlds.hpp"

int main(int argc, char** argv) {
#ifndef NDEBUG
  spdlog::set_level(spdlog::level::debug);
  spdlog::debug("----Debug configuration!----");
#endif

  AssetManager::loadBundle("res/Ultralight.bundle");
  AssetManager::loadBundle("res/Main.bundle");

  Window::init([](Window::Config* self) {
    self->title = "Tic Tac Toe";
    self->fullScreen = false;
    self->size = {600, 600};
    self->vSync = true;
  });

  InputSystem::createTriggersFromFile("main/configs/triggers.yml");

  AssetManager::preload<Texture>("main/art/crosses_0.png");
  AssetManager::preload<Texture>("main/art/crosses_1.png");
  AssetManager::preload<Texture>("main/art/crosses_2.png");

  AssetManager::preload<Texture>("main/art/toes_0.png");
  AssetManager::preload<Texture>("main/art/toes_1.png");
  AssetManager::preload<Texture>("main/art/toes_2.png");

  World* world = loadGameWorld();

  while (Window::update()) {
    world->update();
    Window::show();
  }

  delete world;
  Window::destroy();

  return EXIT_SUCCESS;
}
