/*
 Justin Ngo
 jmn4fms
 4/21/20
 middleearth.h
 */
#include <iostream>
#include <vector>
#include <string>
#include <map>

#ifndef MIDDLEEARTH_H
#define MIDDLEEARTH_H

using namespace std;

// see the comments in the lab11 write-up, or in middleearth.cpp

class MiddleEarth {
private:
    /**
     Private variables that hold the places/ locations
     */
    /*!
     The number of cities and the size of the place
     */
    int num_city_names, xsize, ysize;
    /**
     Vector of floats containing the position of the cities
     */
    vector<float> xpos, ypos;
    /**
     Vector of strings containing all of the cities
     */
    vector<string> cities;
    /**
     Pointer to the distance of the cities
     */
    float *distances;
    /**
     Map containing the positions of the cities
     */
    map<string, int> indices;

public:
    /**
     * Constructor for MiddleEarth object
     */
    /*! @brief A constructor that builds MiddleEarth
      @param xsize The size of MiddleEarth from x
      @param ysize The size of MiddleEarth from y
      @param num_cities The number of cities in MiddleEarth
      @param seed The number of seeds
    */
    MiddleEarth (int xsize, int ysize, int numcities, int seed);
    
    /*!
     Destructor
    */
    ~MiddleEarth();
    
    /*!
     Prints the MiddleEarth object
    */
    void print();
    
    /*!
     Prints out separated distances
    */
    void printTable();
    
    /*! @brief Returns distance of two cities from each other
     @param city1 name of the first city
     @param city2 name of the second city
     @return Returns distance of cities from each other
    */
    float getDistance (string city1, string city2);
    
    /*!
     @param length
     @return Returns the vector of strings of the roadmap
    */
    vector<string> getItinerary(unsigned int length);
};

#endif
