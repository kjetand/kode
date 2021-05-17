#include "gui.hpp"

int main() {
  sf::RenderWindow window(sf::VideoMode(800, 800), "", sf::Style::None);
  window.setVerticalSyncEnabled(true);
  ImGui::SFML::Init(window, true);

  sf::Event event{};
  sf::Clock delta_clock{};

  while (window.isOpen()) {
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      } else {
        ImGui::SFML::ProcessEvent(event);
      }
    }
    ImGui::SFML::Update(window, delta_clock.restart());

    window.clear();

    // TODO: Render text editor here

    ImGui::Begin("Hello, world!");

    if (ImGui::Button("Press me!")) {
      std::puts("Hello, world!");
    }
    ImGui::End();
    ImGui::SFML::Render(window);

    window.display();
    sf::sleep(sf::milliseconds(10));
  }
  ImGui::SFML::Shutdown();
}
