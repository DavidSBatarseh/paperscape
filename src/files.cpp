#include "files.h"
#include "utils.h"
#include <string>
#include <tuple>
#include <vector>
char textInput[20];
int writeCur;

struct file{
  int posx;
  int posy;
  std::string name;
};

std::vector<file> fileSpaces;

void setupFile(){
  mode = 1; 
  writeCur = -1;
}

void createFile(){
  std::ofstream tempFiles(textInput);
  auto coords = getCursorCoords();
  tempFiles<< "(" + std::to_string(coords.x) + "," + std::to_string(coords.y) + ")" << std::endl;
  tempFiles.close();
  writeCur = 0;
  mode = 0;
  fileSpaces.push_back(file{ posx: coords.x, posy: coords.y, name : textInput});
}

void renderTextBox(sf::RenderWindow* window){
  sf::RectangleShape box(sf::Vector2f(width, 20));
  box.setPosition(10,height-20);
  box.setFillColor(sf::Color::White);
  window->draw(box);
  renderText(10, height-20, textInput, 10);
}
void renderFiles(){
  for(auto f : fileSpaces){
    drawInGridSquare(f.posx, f.posy);
  }
}
