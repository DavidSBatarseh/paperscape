#ifndef UTILS_H
#define UTILS_H
#include <string>
#include "text.h"
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include "grid.h"
#include <iostream>
#include <iostream>
struct file{
  std::string name;
  std::string buffer;
  int posx;
  int posy;
};
void setupText(sf::RenderWindow*);
void renderText(sf::Vector2f, std::string, int);
void renderText(int, int, std::string, int);
void drawInGridSquare(int, int);
void drawInGridSquare(int, int, sf::Color);
void setupTerminal();
void renderTerminal(file*, int, int, int, int);
#endif 
