#include <iostream>
#include "my_hash.h"
#include "csv.h" 
#include "superhero.h"

/**
 * Defines sample hash functions and prints their collision performance when
 * used to feed hash map the superhero database
 */ 

/** Credit: http://www.cse.yorku.ca/~oz/hash.html */
unsigned djb2 (std::string s){
    unsigned hashAddress = 5381;
    for (size_t i = 0; i < s.length(); i++){
        hashAddress = ((hashAddress << 5) + hashAddress) + s[i];
        
    }
    return hashAddress;
}

/** Credit: https://stackoverflow.com/questions/8317508/hash-function-for-a-string */
unsigned bezouts_identity (std::string s) {
    unsigned h = 37;
    for (size_t i = 0; i < s.length(); i++){
        h = (h * 54059) ^ (s[i] * 76963);
    }
    return h;
}

/** Implementation of hashCode in the Java String class according to
 *  Brendan Long on Stack Overflow
 */
unsigned java_string (std::string s) {
    unsigned address = 0;
    for(size_t i = 0; i < s.length(); ++i) {
        address += s[i] * i ^ 31;
    }
    return address;
}

int main(int argc, char * argv[]) {
    int collisions1 = 0;
    int collisions2 = 0;
    int collisions3 = 0;

    io::CSVReader<13, io::trim_chars<' '>, io::double_quote_escape<',', '\"'> > in("marvel-wikia-data.csv");

    my_hash<superhero> * hm1 = new my_hash<superhero>(djb2);
    my_hash<superhero> hm2 = my_hash<superhero>(bezouts_identity);
    my_hash<superhero> hm3 = my_hash<superhero>(java_string);

    in.read_header(io::ignore_missing_column, "page_id", "name", "urlslug", "ID","ALIGN", "EYE", "HAIR",
         "SEX", "GSM", "ALIVE", "APPEARANCES", "FIRST APPEARANCE", "Year");

    // Temporary variables to hold fields
    int page_id; 
    std::string name; 
    std::string urlslug; 
    std::string id; 
    std::string alignment; 
    std::string eye_color; 
    std::string hair_color;
    std::string sexString;  // Stored in csv as string, converted to char
    char sex;
    std::string gsm = "N/A"; 
    std::string aliveString; // Stored in csv as string, will be converted to bool
    bool alive;
    int appearances; 
    std::string first_appearance; 
    int year;

    superhero* hero;

    // While there are still rows left in the .csv
    while (in.read_row(page_id,name,urlslug,id,alignment,eye_color,hair_color,sexString,gsm, aliveString, appearances,first_appearance,year)){
            sex = sexString[0];
            alive = (aliveString == "Living Characters");

            hero = new superhero(page_id,name,urlslug,id,alignment,eye_color,hair_color,sex,gsm,alive,appearances,first_appearance,year);

            if (hm1->insert(*hero))
                collisions1++;

            if (hm2.insert(*hero))
                collisions2++;

            if (hm3.insert(*hero))
                collisions3++;
    }

    std::cout << "Collisions in hash map 1: " << collisions1 << std::endl;
    std::cout << "Collisions in hash map 2: " << collisions2 << std::endl;
    std::cout << "Collisions in hash map 3: " << collisions3 << std::endl;
}
