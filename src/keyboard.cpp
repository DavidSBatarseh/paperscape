
#include "keyboard.h"
#include <iostream>
sf::Vector2f speed;
int mode = 0;
extern file* f;
extern bool collision;
void eventHandler(sf::Event* event){
  if(mode == 0){
	switch(event->type){
    case(sf::Event::KeyPressed):
			switch(event->key.code){
        case(sf::Keyboard::A):
          speed.x = 20;
          break;
        case(sf::Keyboard::W):
          speed.y = 20;
          break;
        case(sf::Keyboard::S):
          speed.y = -20;
          break;
        case(sf::Keyboard::D):
          speed.x = -20;
          break;
        case(sf::Keyboard::R):
          centerCursor();
          break;
        case(sf::Keyboard::J):
          cursorPos.x -= gridSize;
          break;
        case(sf::Keyboard::K):
          cursorPos.y +=gridSize;
          break;
        case(sf::Keyboard::L):
          cursorPos.x += gridSize;
          break;
        case(sf::Keyboard::I):
          cursorPos.y -=gridSize;
          break;
        case(sf::Keyboard::N):
          if(!collision){
            setupFile();
          }
          break;
        case(sf::Keyboard::O):
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
          auto temp = getCursorCoords();
          if(openFile(temp.x, temp.y)){
            mode = 2;
          }
          return;
          }
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
   } else if(mode == 1){
      speed.x = 0;
      speed.y = 0;
      if(event->type == sf::Event::TextEntered){
          if(writeCur >= 0){
            if(event->text.unicode != '\b'){
              char c = static_cast<char>(event->text.unicode);
              textInput.insert(writeCur, 1, c);
            } else {
              if(writeCur >0){
                textInput.erase(--writeCur, 1);
              }
              writeCur--;
            }
          }
          writeCur++;
        }
        if(event->type == sf::Event::KeyPressed && event->key.code == sf::Keyboard::Enter){
          createFile();
        }
      } else if (mode == 2){
          if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)){
            if(event->type == sf::Event::KeyPressed) {
            switch(event->key.code){
              case(sf::Keyboard::S):
                saveFile();
              break; 
              case(sf::Keyboard::Q):
                mode = 0; 
              break; 
            }
            }
          } else {
        textEventProcessor(*event, &(f->buffer));
        }
      }
    }
