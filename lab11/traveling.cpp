// Justin Ngo
// jmn4fms
// 4/24/20
// traveling.cpp

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include "middleearth.h"

using namespace std;

float computeDistance (MiddleEarth &me, string start, vector<string> dests);
void printRoute (string start, vector<string> dests);

/**
 *program runs and calculates traveling salesperson problem
 *from the 5 paramters passed in from the hobbits world.
 *The program has a vector that has all the destinations and
 *is then sort from the second destination to the last. The
 *program then goes through all the permuatations by using the other
 *methods and finds the shortest path and the shows the shortest path.
 */
int main (int argc, char **argv) {
    // check the number of parameters
    if ( argc != 6 ) {
        cout << "Usage: " << argv[0] << " <world_height> <world_width> "
        << "<num_cities> <random_seed> <cities_to_visit>" << endl;
        exit(0);
    }
    // we'll assume the parameters are all well-formed
    //int width, height, num_cities, rand_seed, cities_to_visit;
    
    int width = stoi(argv[1]);
    int height = stoi(argv[2]);
    int num_cities = stoi(argv[3]);
    int rand_seed = stoi(argv[4]);
    int cities_to_visit = stoi(argv[5]);
     
    // Create the world, and select your itinerary
    MiddleEarth me(width, height, num_cities, rand_seed);
    vector<string> dests = me.getItinerary(cities_to_visit);
  
    // TODO: YOUR CODE HERE
    sort(dests.begin()+1, dests.end());
    
    string firstDest = dests.at(0);
    vector<string> print = dests;
    float smallestDistance = computeDistance(me,firstDest,dests);
    
    while(next_permutation(dests.begin()+1, dests.end())){
        float distTemp = computeDistance(me, firstDest, dests);
        bool test = distTemp < smallestDistance;
        if(test == true){
            print = dests;
            smallestDistance = distTemp;
        }
    }
    
    firstDest = print.at(0);
    cout<< "Minimum path has a distance " << smallestDistance << ": ";
    printRoute(firstDest, print);
    
    return 0;
    }

/**
 * This method will compute the full distance of the cycle that starts
 * at the 'start' parameter, goes to each of the cities in the dests
  * vector IN ORDER, and ends back at the 'start' parameter.
 *@param me The world
 *@param start The starting city of the cycle
 *@param dests The cities to be visited
 *@return The float distance it takes to travel the cities
 */
float computeDistance (MiddleEarth &me, string start, vector<string> dests) {
    float distance = 0.0;
    string begin = start;
    string last = dests.back();
    
    int i = 0;
    bool test = i < dests.size();
    
    while(test){
        distance += me.getDistance(begin,dests.at(i));
        begin = dests.at(i);
        i++;
        if(i >= dests.size()){
            test = false;
        }
    }
    
    distance += me.getDistance(dests.at(0),last);
    return distance;
}

/**
 * This method will print the entire route, starting and ending at the
 * 'start' parameter.  The output should be of the form:
 * Erebor -> Khazad-dum -> Michel Delving -> Bree -> Cirith Ungol -> Erebor
 * @param start The start of the route
 * @param dests The end of the route
 */
void printRoute (string start, vector<string> dests) {
    int i = 0;
    while(i < dests.size()){
        cout<< dests.at(i)<<" -> ";
        i++;
    }
    cout << start << endl;
}
