#include "main.h"
typedef std::chrono::duration<int, std::ratio<1,60>> frame_duration;
int width = 1000;
int height = 1000;
file* f;
sf::Vector2f offset(0,0);
std::string buffer;
int main(){
    sf::Color base = sf::Color(150,150,150);
    sf::RenderWindow window(sf::VideoMode(width, height), "prgm");
    sf::RectangleShape background(sf::Vector2f(width, height));
    background.setFillColor(base);
    auto start = std::chrono::steady_clock::now();
    auto end = start + frame_duration(1);
    centerCursor();
    window.display();
    setupText(&window); 
    f = nullptr; 
    loadDirectory();
    while (window.isOpen()) {
      start = std::chrono::steady_clock::now();
      end = start+frame_duration(1); 
      window.draw(background);
      offset+=speed /(float) 60;
      drawGrid(&window);
      renderCursor(&window);
      renderFiles();
      if(mode == 1){
        renderTextBox(&window);
      } 
      if (mode == 2) {
        if(f==nullptr){
          printf("terminal mode with no file\n");
          return 0;
        }
        renderTerminal(f, 100, 100, realPos,linePos);
      }

      window.display(); 

      sf::Event event;
      while (window.pollEvent(event)){
        switch(event.type){
          case(sf::Event::Closed):
            window.close();
            break;
        case(sf::Event::TextEntered):
        case(sf::Event::KeyPressed):
        case(sf::Event::KeyReleased):
            eventHandler(&event);
            break;
        }
      }
    }
    std::this_thread::sleep_until(end);

    return 0;
}

