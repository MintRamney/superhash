#include "my_hash.h"
#include "csv.h" 
#include "superhero.h"

int hash1 (std::string s){
        return 1;
    }

int hash2 (std::string s) {
        return 2;
    }

int hash3 (std::string s) {
        return 3;
    }

int main(int argc, char * argv[]) {
    io::CSVReader<12, io::trim_chars<' '>, io::double_quote_escape<',', "\""> > in("marvel-wikia-data.csv");

    my_hash<superhero>(hash1) hm1;
    my_hash<superhero>(hash2) hm2;
    my_hash<superhero>(hash3) hm3;
}
