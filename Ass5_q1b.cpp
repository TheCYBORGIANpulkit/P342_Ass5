#include <iostream>
#include <cmath>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include "Library.cpp"
using namespace std;

float f(float x){
    return -x - cos(x);
}

int main(){
    Bisection(f, -1, 0);
    Newton_Raphson(f, -0.8);
    return 0;
}
