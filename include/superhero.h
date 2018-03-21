#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <string>

class superhero {
public:
    superhero(int page_id, std::string name, std::string urlslug, std::string id, std::string alignment, std::string eye_color, std::string hair_color,
    char sex, std::string gsm, bool alive, int appearances, std::string first_appearance, int year);

private:
     int page_id;
     std::string name;
     std::string urlslug;
     std::string id;
     std::string alignment;
     std::string eye_color;
     std::string hair_color;
     char sex;
     std::string gsm;
     bool alive;
     int appearances;
     std::string first_appearance;
     int year;
};

#endif