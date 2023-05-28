#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
int gridThickness = 3;
void drawGrid(int gridSize, sf::Vector2f offset, int width, int height, sf::RenderWindow* window){
  
  sf::Vector2f center(width/2, height/2);
  sf::RectangleShape vertLine(sf::Vector2f(gridThickness,  width));
  sf::RectangleShape horiLine(sf::Vector2f(height, gridThickness));
  int h = (int)offset.x % gridSize;
  int v = (int)offset.y % gridSize;
  for(int i = center.x + gridSize/2 + h; i < width; i+=gridSize){
    vertLine.setPosition(i, 0);
    window->draw(vertLine);
  }
  for(int i = center.x - gridSize/2 + h; i>0; i-=gridSize){
      vertLine.setPosition(i, 0);
      window->draw(vertLine);
    }
  for(int i = center.y + gridSize/2 + v; i < height; i+=gridSize){
    horiLine.setPosition(0, i);
    window->draw(horiLine);
  }
  for(int i = center.y - gridSize/2 + v; i>0; i-=gridSize){
      horiLine.setPosition(0, i);
      window->draw(horiLine);
    }
  return;
  }
