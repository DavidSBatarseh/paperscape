#include "text.h"
#include <iostream>
int realPos;
int linePos;
int alignCursor(std::string* text, int realPos){
  int returnVal = 0;
  while(--realPos >= 0 && text->at(realPos) != '\n'){
    returnVal++;
  }
  return returnVal;
}



int getOffset(sf::Font* font, std::string* text, int realPos){
  sf::Text imp;
  imp.setFont(*font);
  imp.setCharacterSize(30);
  int c = alignCursor(text, realPos);
  imp.setString(text->substr(realPos-c,c));
  return imp.getLocalBounds().width;
}
//Lot of pointer accesses due to pulling out of other project
//TODO : process events, simply update realPos and linePos at the end.
void textEventProcessor(sf::Event event, std::string* test) {
      if (event.type == sf::Event::TextEntered){
        if(event.text.unicode == 8 && realPos > 0){
          if(test->at(realPos-1) == '\n'){
            (linePos)--;
        }
          test->erase(--realPos, 1);
          
        }
        if(event.text.unicode == 13){
        test->insert((realPos)++, 1, '\n');
        (linePos)++;
      }
        if(event.text.unicode < 128 && event.text.unicode > 31){
          test->insert((realPos)++, 1, char(event.text.unicode)); 
        }
      }
      if(event.type == sf::Event::KeyPressed){
        if(event.key.code == sf::Keyboard::Right && realPos < test->length()){
          if(test->at((realPos)++) == '\n'){
          (linePos)++;
        }
      }
        if(event.key.code == sf::Keyboard::Left && realPos > 0){
        (realPos)--;
        if(test->at(realPos) == '\n'){
          (linePos)--;
        }
      }
        if(event.key.code == sf::Keyboard::Down){
          int tempC = alignCursor(test, realPos);
          while(realPos < test->size() && test->at(realPos) != '\n'){
          (realPos)++;
          }
          if(realPos != test->size()){
            (linePos)++;
            (realPos)++;
            while(realPos < test->size() && test->at(realPos) != '\n' && tempC > 0){
            (realPos)++;
            tempC--;
          }
          }
        }
        if(event.key.code == sf::Keyboard::Up){
        if(linePos != 0){
          int tempCurs = alignCursor(test, realPos);
          while(test->at(--realPos) != '\n'){}
          (linePos)--;
          int temp = alignCursor(test, realPos);
          realPos = realPos - temp + fmin(tempCurs, temp);
        } else {
          realPos = 0;
        }
      }
      }
}
//TODO: add left and right ( inline)
