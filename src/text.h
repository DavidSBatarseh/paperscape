#ifndef TEXT_H
#define TEXT_H
#include <math.h>
#include <string>
#include <unistd.h>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics.hpp>
extern int realPos;
extern int linePos;
int alignCursor(std::string*, int);
int getOffset(sf::Font*, std::string*, int);
void textEventProcessor(sf::Event, std::string*);
#endif
