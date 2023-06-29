#include "utils.h"
#include <iostream>
sf::Font font;
sf::Text text;
sf::RenderWindow *window;
extern int width;
extern int height;
extern sf::Vector2f offset;
void setupText(sf::RenderWindow *win){
  if(!font.loadFromFile("rsc/Roboto-Regular.ttf")){
    //idk just work fuck off
    std::cout<< "font not loaded" << "\n";
  }
  window = win;
  text.setFont(font);
  text.setCharacterSize(20);
  text.setFillColor(sf::Color::Black);
}

void renderText(sf::Vector2f pos, std::string val, int size){
  text.setString(val);
  text.setPosition(pos);
  window->draw(text);
}
void renderText(int x, int y, std::string val, int size){
  text.setString(static_cast<std::string>(val));
  text.setPosition(x, y);
  window->draw(text);
}
void drawInGridSquare(int x, int y){
  int drawX = (int)offset.x + x*gridSize;  
  int drawY = (int)offset.y + y*gridSize;  
  sf::RectangleShape square(sf::Vector2f(gridSize,  gridSize));
  square.setPosition(drawX,drawY);
  window->draw(square);
}
