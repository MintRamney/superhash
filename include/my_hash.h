#import <vector.h>
#import <string>
#import "superhero.h"

template <typename T>

class my_hash {

public:
    my_hash (std::function< int(std::string) > hash_function) {
        this.hash_function = hash_function;
        data = vector(17011);
    }

    bool insert (const Superhero & s) {
        
    }


    Superhero & get (const std::string name) {
        
    }

private:
    int *(*hash_function)(int *);
    vector<vector<T>> data;
};
