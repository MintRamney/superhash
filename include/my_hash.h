#import <vector.h>

template <typename T>

class my_hash {

public:
    my_hash (std::function<int()> hash_function) {
        this.hash_function = hash_function;
        data = vector(17011);
    }

    boolean insert (const Superhero & s) {
        
    }


    Superhero & get (const std::string name) {
        
    }

private:
    int *(*hash_function)(int *);
    vector<vector<T>> data;
}
