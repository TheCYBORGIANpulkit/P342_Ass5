#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Library.cpp"
using namespace std;


float f(float x){
    return log10(x) - sin(x);
}

int main(){
    //float f(x) = log(x) - sin(x);
    cout << "Hello" << endl;
    //cout << "The product is" << Bracketing(1.5, 2.5) << endl;
    //*p = f(x);
    Bisection(f,1.5,3.25);
    False_position(f,1.5,3.25);
    Newton_Raphson(f,3);
    return 0;
}
