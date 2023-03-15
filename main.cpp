// Spring'22
// Instructor: Diba Mirza
// Student name: Vishal S. 
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>
#include <cstring>
#include <algorithm>
#include <limits.h>
#include <iomanip>
#include <set>
#include <queue>

#include "movies.h"

using namespace std;

bool parseLine(string &line, string &movieName, double &movieRating);

int main(int argc, char** argv){
    if (argc < 2){
        cerr << "Not enough arguments provided (need at least 1 argument)." << endl;
        cerr << "Usage: " << argv[ 0 ] << " filename prefix1 prefix2 ... prefix n " << endl;
        exit(1);
    }

    ifstream movieFile (argv[1]);
 
    if (movieFile.fail()){
        cerr << "Could not open file " << argv[1];
        exit(1);
    }
  
  // Create an object of a STL data-structure to store all the movies
  movies movieData;

  string line, movieName;
  double movieRating;
  // Read each file and store the name and rating
  while (getline (movieFile, line) && parseLine(line, movieName, movieRating)){
        movieData.addMovie(movieName, movieRating);
  }

  movieFile.close();

  if (argc == 2){
        //print all the movies in ascending alphabetical order of movie names
        movieData.printAlphabetically();
        return 0;
  }

  //  For each prefix,
  //  Find all movies that have that prefix and store them in an appropriate data structure
  //  If no movie with that prefix exists print the following message

    for(int i = 2; i < argc; i++)
    {
        movieData.printWithPrefix(argv[i], true);
        cout << endl; 
    }

  //  For each prefix,
  //  Print the highest rated movie with that prefix if it exists.

    for(int i = 2; i < argc; i++)
    {
        movieData.printWithPrefix(argv[i], false);
    }
}

/* Add your run time analysis for part 3 of the assignment here as commented block*/

bool parseLine(string &line, string &movieName, double &movieRating) {
    if (line.length() <= 0) return false;
    string tempRating = "";

    bool flag = false;
    movieName = tempRating = "", movieRating = 0.0, flag = false;

    for (int i = 0; i < line.length(); i++){
        if(flag) tempRating += line[i];
        else if(line[i]==','&& line[0]!='"') flag = true;
        else {
            if(i==0 && line[0]=='"') continue;
            if(line[i]=='"'){ i++; flag=true; continue;}
            movieName += line[i];
        }
    }
    
    movieRating = stod(tempRating);
    return true;
}



/*
    Space and Time Complexity Analyses

    Part 3a - Complexity Analyses


    Printing all entries with prefix: 

    m calls to printWithPrefix 

    Inside printWithPrefix
    first for loop - executes n times
        worst case, assume every entry has the prefix
        inner for loop - assuming rating is greater than all already inserted ratings - executes 1 additional time each outer for loop
        maximum execution is n times, when every entry is inserted into prefixMovies
        All other statements are constant time, can be ignored

    second for loop - executes m times (again, assuming worst case every entry is valid)

    O(m*((n*n)+m)) = O(m(n^2+m))

    Printing best entries: 

    m calls to printWithPrefix again

    Inside printWithPrefix
    First for loop is same as before

    Instead of second for loop, just prints out first entry to prefixMovies - constant time

    O(m*(n*n)+1) = O(m*(n^2))

    Putting both together
    O((m(n^2+m))(m*(n^2))) 
    = O((m*n^2)^2)+m^2) < ------- FINAL ANSWER



    Part 3b - Space Analysis

    Each call to printWithPrefix declares a new prefixMovies list of movieEntry structs to store data
    Each movieEntry has a double and a string - O(1) and O(n), respectively
    All other declared variables are constant size, so O(1)
    Thus, the printWithPrefix's space complexity is O(n)

    printWithPrefix is called again to print the top element, so the final space complexity is
    2O(n) = O(n) < --------- FINAL ANSWER


    Part 3c - Explore tradeoffs
    I designed my algorithm for a low space complexity. I believe I was able to reach this goal.
    The space complexity is O(n) - in other words, the amount of space used by the program is 
    directly proportional to the number of entries, which makes sense, since more space will be needed
    no matter what to store more data. There isn't really a way to reduce this, so I believe I was 
    able to acheive low space complexity. 

*/
