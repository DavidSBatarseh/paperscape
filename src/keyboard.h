#ifndef KEYBOARD_H
#define KEYBOARD_H
#include <SFML/Window/Event.hpp>
#include "text.h"
#include "cursor.h"
#include "files.h"
#include "grid.h"
#include "utils.h"
#include <SFML/System.hpp>
#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Window/Keyboard.hpp>
#include <cstddef>
#include <SFML/System/Vector2.hpp>
extern sf::Vector2f speed;
extern int mode;
void eventHandler(sf::Event* event);
#endif 
