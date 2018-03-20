#include <vector>
#include <string>
#include <sstream>
#include <functional>

template <typename T>

class my_hash {

public:
    my_hash (std::function< int(std::string) > hash_function) {
        this.hash_function = hash_function;
        data = std::vector<std::vector<T>>(INITIAL_SIZE);
        numCollisions = 0;
    }

    bool insert (const T & t) {
        bool collides = false;

        // Obtain string representation of t
        std::stringstream sstream;
        sstream << t;

        // Finds index to place element at
        int i = hash_function(sstream.str()) % INITIAL_SIZE;

        // Record collision
        if (!data[i].empty()){
            numCollisions++;
            collides = true;
        }

        auto it = data[i].begin();
        data.insert(it, t); // Insert element into front of inner vector

        return collides;
    }


    T & get (const std::string name) {
        int i = hash_function(name);
        for (T t: data[i]){
           // if (<<t)
        }
    }

    int getNumCollisions () {
        return numCollisions;
    }

private:
    /* Hash function of choice */
    std::function< int(std::string) > hash_function;
    /* Elements stored in a 2d vector */
    std::vector< std::vector<T> > data;
    /* Keeps track of collisions */
    int numCollisions;

    const int INITIAL_SIZE = 17011;
};
