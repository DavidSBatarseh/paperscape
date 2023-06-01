#include <SFML/Graphics.hpp> 
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <bits/chrono.h>
#include <bits/types/time_t.h>
#include <iomanip>
#include <iostream>
#include <queue>
#include <ratio>
#include <string>
#include <thread>
#include <vector>
#include <ctime>
#include <chrono>
#include <tuple>
#include <cstdlib>
#include "grid.h"
#include "keyboard.h"
typedef std::chrono::duration<int, std::ratio<1,60>> frame_duration;
extern int width = 1000;
extern int height = 1000;
extern sf::Vector2f offset(20, 20);

void sleepm(int sec) {
  std::this_thread::sleep_for(std::chrono::milliseconds(sec));
}
int main()
{
    sf::Color base = sf::Color(150,53,27);
    sf::RenderWindow window(sf::VideoMode(width, height), "prgm");
    sf::RectangleShape background(sf::Vector2f(width, height));
    background.setFillColor(base);
    auto start = std::chrono::steady_clock::now();
    auto end = start + frame_duration(1);
    window.display();
    while (window.isOpen()) {
      start = std::chrono::steady_clock::now();
      end = start+frame_duration(1); 
      window.draw(background);
      offset+=speed /(float) 60;
      drawGrid(190, &window);
      window.display();
      sf::Event event;
      while (window.pollEvent(event)){
        switch(event.type){
          case(sf::Event::Closed):
            window.close();
            break;
        case(sf::Event::KeyPressed):
        case(sf::Event::KeyReleased):
            eventHandler(&event);
            break;
        }
      }
    }
    std::this_thread::sleep_until(end);

    return 0;
}

