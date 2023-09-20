#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include "main.h"
#include "utils.h"
int gridThickness = 3;
int gridSize = 50;
void drawCoords(sf::RenderWindow*);
void drawGrid( sf::RenderWindow* window){
  sf::Color out(0,0,0); 
  sf::RectangleShape vertLine(sf::Vector2f(gridThickness,  width));
  sf::RectangleShape horiLine(sf::Vector2f(height, gridThickness));
  vertLine.setOutlineColor(out);
  vertLine.setOutlineThickness(1);
  horiLine.setOutlineColor(out);
  horiLine.setOutlineThickness(1);
  int h = (int)offset.x % gridSize;
  int v = (int)offset.y % gridSize;
  /*for(int i = -1; i < width/gridSize + 1; i++){
    vertLine.setPosition((i * gridSize) + h, 0);
    horiLine.setPosition( 0, (i * gridSize) + v);
    window->draw(vertLine);
    window->draw(horiLine);
  }*/
  vertLine.setSize(sf::Vector2f(1, width)); 
  horiLine.setSize(sf::Vector2f(height, 1));
  vertLine.setOutlineThickness(0);
  horiLine.setOutlineThickness(0);
  vertLine.setFillColor(sf::Color(100,100,100));
  horiLine.setFillColor(sf::Color(100,100,100));
  for(int j = -4; j < (width/gridSize) + 4; j++){
    vertLine.setPosition((j * gridSize) + h, 0);
    horiLine.setPosition( 0, (j * gridSize) + v);
    window->draw(vertLine);
    window->draw(horiLine);
  }
  drawCoords(window);
  return;
}

void drawCoords(sf::RenderWindow* window){
  for(int i = -1; i < (width)/(gridSize/4) + 1; i++){
      renderText(sf::Vector2f(i * gridSize + (int) offset.x % (gridSize), 5), std::to_string(i-((int)offset.x/(gridSize))), 20);
    }
}
