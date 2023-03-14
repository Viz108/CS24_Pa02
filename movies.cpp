#include <iostream>

#include "movies.h"


using namespace std; 

movies :: movies()
{

}

void movies :: addMovie(string movieName, double movieRating) 
{
    movieEntry newMovie;
    newMovie.name = movieName; 
    newMovie.rating = movieRating; 

    if(movieList.empty())
    {
        movieList.push_back(newMovie);
    }
    else
    {
        list<movieEntry>::iterator currMovie = movieList.begin(); 
        bool inserted = false; 
        while(currMovie != movieList.end())
        {
            if(currMovie -> name.compare(newMovie.name) > 0) //First movie alphabetically greater than new movie
            {
                movieList.insert(currMovie, newMovie);
                inserted = true; 
                break;
            }
            currMovie++;
        }
        if(!inserted)
        {
            movieList.push_back(newMovie);
        }
    }
}

void movies :: printAlphabetically()
{
    for(auto elem : movieList)
    {
        cout << elem.name << ", " << elem.rating << endl; 
    }
}