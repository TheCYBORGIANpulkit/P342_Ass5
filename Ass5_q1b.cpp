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
    False_position(f,-1,0);
    Newton_Raphson(f,-1);
    return 0;
    /*RESULT:
    after bisection
    c:-0.739085
    f(c):-7.15256e-007
    Please find the attached csv file generated and the plot
    after false-positioning
    c:-0.739085
    f(c):-5.96046e-007
    Please find the attached csv file generated and the plot
    after newton-raphson
    root:-0.739113
    f(x): 4.60148e-005
    Please find the attached csv file generated and the plot
    */
}
