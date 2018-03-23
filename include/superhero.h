#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <string>
#include <iostream>
#include <vector>

/**
 * Data object to store a Marvel Wikia character database entry
 * 
 * @author Ryan Jones
 */ 
class Superhero {
public:
    Superhero(int page_id, std::string name, std::string urlslug, std::string id, std::string alignment, std::string eye_color, std::string hair_color,
    char sex, std::string gsm, bool alive, int appearances, std::string first_appearance, int year);


    friend std::ostream& operator<<(std::ostream& os, const Superhero& sup);

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
