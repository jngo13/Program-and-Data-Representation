// Justin Ngo
// jmn4fms
// 3/30/20
// mathfun.cpp

#include <iostream>
#include <time.h>
#include <cstdlib>

using namespace std;

extern "C" int product (int, int);
extern "C" int power (int, int);

/*Purpose: The file will contain two subroutines, a product function and a power function
;          The product function is implemented iteratively with addition
;          The power function is implemented recursively with multiplication
*/

int main () {
    int param1, param2;

    cout << "Please enter a positive integer: ";
    cin >> param1;
    cout << "Please enter another positive integer: ";
    cin >> param2;

    if (param1 < 0 || param2 < 0){
        cerr << "Integers must be greater than zero. \n";
        return 1;
    }

    int prod = product(param1, param2);
    int expo = power(param1, param2);

    cout << param1 << " x " << param2 << " = "  << prod << endl;
    cout << param1 << " ^ " << param2 << " = " << expo << endl;

    return 0;
}
