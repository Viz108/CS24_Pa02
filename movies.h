
#ifndef MOVIES_H
#define MOVIES_H

#include <string>
#include <iostream>
#include <list>

using namespace std; 

class movies
{
    private: 
        struct movieEntry
        {
            string name; 
            double rating; 
        };


        list<movieEntry> movieList; 

    public: 
        movies(); 
        void addMovie(string movieName, double movieRating); 
        void printAlphabetically(); 
        void printWithPrefix(string prefix);
        void printHighestWithPrefix(); 
};

#endif