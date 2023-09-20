#ifndef CURSOR_H
#define CURSOR_H
#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>
#include <string>
extern sf::Vector2f cursorPos;
void renderCursor(sf::RenderWindow* window);
void centerCursor();
void printPos();
sf::Vector2i getCursorCoords();
#endif 
