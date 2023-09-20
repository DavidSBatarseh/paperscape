#include "files.h"
#include "keyboard.h"
#include <cwchar>
#include <filesystem>
std::string textInput;
std::string path = "~/.config/Paperscape";
int writeCur;
bool collision;
extern file* f;
extern int realPos;
extern int linePos;
std::vector<file> fileSpaces;
void setupFile(){
  mode = 1; 
  writeCur = -1;
}

void createFile(){
  std::ofstream tempFiles(path + "/" +  textInput + ".txt");
  auto coords = getCursorCoords();
  tempFiles<< "(" + std::to_string(coords.x) + "," + std::to_string(coords.y) + ")\n" << std::endl;
  tempFiles.close();
  writeCur = 0;
  mode = 0;
  fileSpaces.push_back(file{name : textInput, buffer : "", posx: coords.x, posy: coords.y });
}

void renderTextBox(sf::RenderWindow* window){
  sf::RectangleShape box(sf::Vector2f(width-20, 23));
  box.setPosition(10,height-30);
  box.setFillColor(sf::Color::White);
  window->draw(box);
  renderText(10, height-30, textInput, 20);
}

void renderFiles(){
  collision = false;
  auto c = getCursorCoords();
  for(auto f : fileSpaces){
    if(f.posx == c.x && f.posy == c.y){
      collision = true;
      renderText(20, 20, f.name, 20);
      drawInGridSquare(f.posx, f.posy, sf::Color(0,0,255));
    } else{
      drawInGridSquare(f.posx, f.posy);
    }
  }
}

bool openFile(int posx, int posy) {
  for(auto it = fileSpaces.begin();it != fileSpaces.end();it++){
    if(it->posx == posx && it->posy == posy){
      f = &*it;
      linePos = 0;
      realPos = 0;
      return true;
    }
  } 
  return false;
}

void saveFile() {
  std::ofstream temp(path + "/" + f->name);
  temp<< "(" + std::to_string(f->posx) + "," + std::to_string(f->posy) + ")" << std::endl;
  temp<<f->buffer<<std::endl;
  temp.close();
}

void loadDirectory() {
  std::cout<<"first"<<std::endl;
  std::error_code err;
  err.clear();
  const char *homedir = getenv("HOME");
  path = std::string() + homedir + "/.config/paperscape";
  std::filesystem::create_directory(path);
  for(const auto & entry : std::filesystem::directory_iterator(path)){
    std::string tmp = entry.path();
    std::cout<<tmp<<std::endl;
      parseFile(std::fstream(entry.path()), tmp.substr(tmp.find_last_of('/')));
  }
}
//attempts to add file to filedir
void parseFile(std::fstream curfile, std::string filename){
  int tposx;
  int tposy;
  std::string contents;
  try{
    getline(curfile, contents);
    if(contents[0] == '('){
      tposx = std::stoi(contents.substr(1,contents.find_first_of(',')));
      tposy = std::stoi(contents.substr(contents.find_first_of(',')+1, contents.find_first_of(')')));
      }
  } catch(...){
    std::cout<<"not"<<std::endl;
    return;
  }
  std::string tempbuffer;
  for(std::string line; getline(curfile, line);){
    tempbuffer+=line + "\n";
  }
  fileSpaces.push_back(file{name : filename, buffer : tempbuffer, posx : tposx, posy : tposy});
}
