#include <SFML/Graphics.hpp> 
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/System/Sleep.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <bits/types/time_t.h>
#include <iomanip>
#include <iostream>
#include <queue>
#include <string>
#include <thread>
#include <vector>
#include <ctime>
#include <chrono>
#include <tuple>
#include <cstdlib>
#include "grid.h"
int width = 1000;
int height = 1000;
sf::Vector2f offset(0, 0);
void sleepm(int sec) {
  std::this_thread::sleep_for(std::chrono::milliseconds(sec));
}
int main()
{
    sf::Color base = sf::Color(0,20,130);
    sf::RenderWindow window(sf::VideoMode(width, height), "prgm");
    sf::RectangleShape background(sf::Vector2f(width, height));
    background.setFillColor(base);
    window.display();
    while (window.isOpen()) {
      window.draw(background);
      drawGrid(50, offset, width, height, &window);
      window.display();
      sf::Event event;
      while (window.pollEvent(event)){
        switch(event.type){
          case(sf::Event::Closed):
            window.close();
            break;
          case(sf::Event::KeyPressed):
            if(event.key.code == sf::Keyboard::A){
              offset.x += 5;
            }
            if(event.key.code == sf::Keyboard::W){
              offset.y += 5;
            }
            break;
        }
      }

    }

    return 0;
}

