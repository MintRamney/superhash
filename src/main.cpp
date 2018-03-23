#include <iostream>
#include "my_hash.h"
#include "csv.h" 
#include "superhero.h"

int hash1 (std::string s){
    int hashAddress = 0;

    for (int counter = 0; s[counter]!='\0'; counter++){
        hashAddress = s[counter] + (hashAddress << 6) + (hashAddress << 16) - hashAddress;
    }    
    return hashAddress;
}

int hash2 (std::string s) {
        return 2;
}

int hash3 (std::string s) {
        return 3;
}

int main(int argc, char * argv[]) {
    int collisions1 = 0;
    int collisions2 = 0;
    int collisions3 = 0;


    io::CSVReader<13, io::trim_chars<' '>, io::double_quote_escape<',', '\"'> > in("marvel-wikia-data.csv");

    my_hash<superhero> hm1 = my_hash<superhero>(hash1);
    my_hash<superhero> hm2 = my_hash<superhero>(hash2);
    my_hash<superhero> hm3 = my_hash<superhero>(hash3);

    in.read_header(io::ignore_missing_column, "page_id", "name", "urlslug", "ID","ALIGN", "EYE", "HAIR", "SEX", "GSM", "ALIVE", "APPEARANCES", "FIRST APPEARANCE", "Year");
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

    while (in.read_row(page_id,name,urlslug,id,alignment,eye_color,hair_color,sexString,gsm, aliveString, appearances,first_appearance,year)){
            sex = sexString[0];
            alive = (aliveString == "Living Characters");

            hero = new superhero(page_id,name,urlslug,id,alignment,eye_color,hair_color,sex,gsm,alive,appearances,first_appearance,year);

            if (hm1.insert(*hero))
                collisions1++;

            //if (hm2.insert(*hero))
            //    collisions2++;

            //if (hm3.insert(*hero))
            //    collisions3++;
    }

    std::cout << "Collisions in hash map 1: " << collisions1 << std::endl;
    std::cout << "Collisions in hash map 2: " << collisions2 << std::endl;
    std::cout << "Collisions in hash map 3: " << collisions3 << std::endl;
}
