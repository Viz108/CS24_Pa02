#include <iostream>
#include <iomanip>

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
        cout << elem.name << ", " << fixed << setprecision(1) << elem.rating << endl; 
    }
}

void movies :: printWithPrefix(string prefix, bool printAll)
{
    list<movieEntry> prefixMovies; 
    for(auto elem : movieList)
    {
        string currPrefix = elem.name.substr(0, prefix.size()); 
        if(currPrefix.compare(prefix) == 0)
        {
            list<movieEntry>::iterator tempIt = prefixMovies.begin();
            bool inserted = false; 
            for(tempIt; tempIt != prefixMovies.end(); ++tempIt)
            {
                movieEntry tempElem = *tempIt; 
                if(tempElem.rating < elem.rating)
                {
                    prefixMovies.insert(tempIt, elem);
                    inserted = true; 
                    break; 
                }
            }
            if(!inserted)
            {
                prefixMovies.push_back(elem);
            }
        }
    }

    if(printAll)
    {
        if(prefixMovies.empty())
        {
            cout << endl; 
            cout << "No movies found with prefix "<< prefix << endl;
        }
        else
        {
            for(auto elem : prefixMovies)
            {
                cout << elem.name << ", " << fixed << setprecision(1) << elem.rating<< endl; 
            }
        }
    }
    else
    {
        if(prefixMovies.empty())
        {
            //Do nothing
        }
        else
        {
            movieEntry bestMovie = *(prefixMovies.begin()); 
            cout << "Best movie with prefix " << prefix << " is: " << bestMovie.name << " with rating " << fixed << setprecision(1) << bestMovie.rating << endl;
        }
    }
    
}