#ifndef MY_HASH_H
#define MY_HASH_H

#include <vector>
#include <string>
#include <sstream>
#include <functional>
#include <iostream>

template <typename T>

/**
 * Generic hash map with size of 17011. 
 */ 
class my_hash {

public:
 
    /**
     * @param hashing function for use in inserting elements
     */ 
    my_hash (std::function< int(std::string) > hash) {
        hash_function = hash;
        data = std::vector<std::vector<T>>(INITIAL_SIZE);
    }

    /**
     * Inserts element into hashmap
     * 
     * @param t Element to insert
     * @return True on collision
     */
    bool insert (const T & t) {
        bool collides = false;

        // Obtain string representation of t
        std::stringstream sstream;
        sstream << t;

        // Finds index to place element at
        int i = hash_function(sstream.str()) % INITIAL_SIZE;

        // Record collision
        collides = !data[i].empty();
        // Insert element into front of inner vector
        data[i].insert(data[i].begin(), t); 
        
        return collides;
    }

    /**
     * Fetches element stored by the same name
     * 
     * @param name Name of the element to find 
     * @return requested element. NULL if not found
     */
    T & get (const std::string name) {
        int i = hash_function(name);

        for (T t: data[i]){ // iterate inner vector
            // write element's name to buffer
           std::stringstream buffer;
           buffer << t << std::endl;

           if (name == buffer.str())
               return t;
           
        }
        return NULL; // element not found
    }


private:
    /* Hashing function */
    std::function< unsigned(std::string) > hash_function;
    /* Elements stored in a 2d vector */
    std::vector< std::vector<T> > data;

    const int INITIAL_SIZE = 17011;
};

#endif