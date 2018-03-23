#include <iostream>
#include "superhero.h"

Superhero::Superhero(int page_id, std::string name, std::string urlslug, std::string id, 
    std::string alignment, std::string eye_color, std::string hair_color,
    char sex, std::string gsm, bool alive, int appearances, std::string first_appearance, int year){

        this->page_id = page_id;
        this->name = name;
        this->urlslug = urlslug;
        this->id = id;
        this->alignment = alignment;
        this->eye_color = eye_color;
        this->hair_color = hair_color;
        this->sex = sex;
        this->gsm = gsm;
        this->alive = alive;
        this->appearances = appearances;
        this->first_appearance = first_appearance;
        this->year = year;
    }


/**
 * Object is represented textually as the name of the hero 
 */
std::ostream& operator<<(std::ostream& os, const Superhero& sup) {
    os << sup.name;
    return os;
}


