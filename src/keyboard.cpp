#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <iostream>
sf::Vector2f speed;
void eventHandler(sf::Event* event){
	switch(event->type){
    case(sf::Event::KeyPressed):
			switch(event->key.code){
        case(sf::Keyboard::A):
          speed.x = 5;
          break;
        case(sf::Keyboard::W):
          speed.y = 5;
          break;
        case(sf::Keyboard::S):
          speed.y = -5;
          break;
        case(sf::Keyboard::D):
          speed.x = -5;
          break;
			}
    break;
    case(sf::Event::KeyReleased):
      switch(event->key.code){
        case(sf::Keyboard::A):
          speed.x = 0;
          break;
        case(sf::Keyboard::W):
          speed.y = 0;
          break;
        case(sf::Keyboard::S):
          speed.y = 0;
          break;
        case(sf::Keyboard::D):
          speed.x = 0;
          break;
        }
          
  }
}


