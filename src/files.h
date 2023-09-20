#ifndef FILES_H
#define FILES_H
#include <iostream>
#include <string>
#include <tuple>
#include <vector>
#include "text.h"
#include <fstream>
#include <string>
#include "cursor.h"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/System/Vector2.hpp>
#include "utils.h"
#include <cstring>
#include <ostream>
#include <string>
extern std::string textInput;
extern int writeCur;
extern int width;
extern int height;
bool openFile(int posx, int posy);
void setupFile();
void createFile();
void renderTextBox(sf::RenderWindow*);
void renderFiles();
void saveFile();
void loadDirectory();
void parseFile(std::fstream, std::string);
#endif
