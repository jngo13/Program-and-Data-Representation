//Justin Ngo, jmn4fms, 1/20/20, xToN.cpp
#include <iostream>
using namespace std;

int exp = 1;

int xton (int a, int b) {
    if(b == 0){
        return exp;
    }
    exp=exp*a;
    return xton(a,b-1);
}

int main () {
    int x, y, z;
    cout << "Type in the base: ";
    cin >> x;
    cout << "Type in the exponent: ";
    cin >> y;
    z = xton(x, y);
    cout << x << " ^ " << y << " = " << z << endl;
    return 0;
}
