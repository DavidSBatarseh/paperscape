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
  text.setCharacterSize(size);
  window->draw(text);
}
void renderText(int x, int y, std::string val, int size){
  text.setString(static_cast<std::string>(val));
  text.setPosition(x, y);
  text.setCharacterSize(size);
  window->draw(text);
}
void drawInGridSquare(int x, int y){
  int drawX = (int)offset.x + x*gridSize;  
  int drawY = (int)offset.y + y*gridSize;  
  sf::RectangleShape square(sf::Vector2f(gridSize,  gridSize));
  square.setPosition(drawX,drawY);
  window->draw(square);
}

void drawInGridSquare(int x, int y, sf::Color c){
  int drawX = (int)offset.x + x*gridSize;  
  int drawY = (int)offset.y + y*gridSize;  
  sf::RectangleShape square(sf::Vector2f(gridSize,  gridSize));
  square.setPosition(drawX,drawY);
  square.setFillColor(c);
  window->draw(square);
}

void renderTerminal(file* f, int xSize, int ySize, int realPos, int cursPos) {
  sf::Sprite terminal;
  sf::RenderTexture box;
  box.create(800,800);
  terminal = sf::Sprite(box.getTexture());
  text.setPosition(0,0); 
  text.setCharacterSize(30);
  text.setString(f->buffer);
  sf::RectangleShape test(sf::Vector2f(800,800));
  box.draw(test);
  box.draw(text);
  terminal.setPosition(100,100);
  sf::RectangleShape curs(sf::Vector2f(5,30));
  extern int linePos;
  curs.setPosition(1+getOffset(&font, &f->buffer, realPos), (cursPos * font.getLineSpacing(30)));
  curs.setFillColor(sf::Color(255,0,0));
  box.draw(curs);
  box.display();
  window->draw(terminal);
}
