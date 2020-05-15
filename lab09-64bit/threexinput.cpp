/*
 Justin Ngo
 jmn4fms
 4/7/20
 threexinput.cpp
 */

#include <iostream>
#include "timer.h"
#include <cstdlib>

using namespace std;

extern "C" int threexplusone(int);

int main() {
    timer t;
    int x; //positive integer to pass to the subroutine
    int n; // number of times to call the subroutine

    cout << "Positive integer : " << endl;
    cin >> x;
    cout << "Number of times to call the subroutine: " << endl;
    cin >> n;
    
    t.start();
    for (int i = 0; i < n; i++) {
        threexplusone(x);
    }
    t.stop();

    double averageTime = (t.getTime()*1000)/n;

    cout << "Result: " << threexplusone(x) << endl;
    cout << "Average Time: " << averageTime << " milliseconds" << endl;
    
    return 0;
}
