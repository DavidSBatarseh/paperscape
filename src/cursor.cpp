#include "grid.h"
#include "main.h"
#include "utils.h"
#include "cursor.h"
sf::Vector2f cursorPos;
sf::Vector2i cursorCoords;
extern int width;
extern int height;
extern sf::Vector2f offset;
//How to calculate the position of the cursor? 
//we can get offset + gridsize (global variables)
//cursor pos can be relative to the screen (i.e a real coordinate position, calculate closest box
//add +gridsize on cursorMovement
//this way cursor should never be off screen as well
void renderCursor(sf::RenderWindow* window){
  sf::RectangleShape cursor(sf::Vector2f(gridSize, gridSize)); 	
  int x = ((int)offset.x % (gridSize)) + gridSize * ((int) cursorPos.x / (gridSize));
  int y = ((int)offset.y % (gridSize)) + gridSize * ((int) cursorPos.y / (gridSize));
  cursor.setPosition(x,y);
  cursorCoords = getCursorCoords();
  window->draw(cursor);
  printPos();
}

void centerCursor(){
	cursorPos = sf::Vector2f(width/2,height/2);
}

void printPos(){
  renderText(900,900,std::to_string(cursorCoords.x) + ", " + std::to_string(cursorCoords.y), 10);
}

sf::Vector2i getCursorCoords(){
  int x = -((int)offset.x / gridSize) +  ((int) cursorPos.x/gridSize); 
  int y = -((int)offset.y / gridSize) +  ((int) cursorPos.y/gridSize);
  return sf::Vector2i( x, y); 
}
