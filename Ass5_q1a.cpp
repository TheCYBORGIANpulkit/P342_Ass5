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
    /*
    Hello
    after bisection
    c:2.69626
    f(c):-4.17233e-007
    Please find the attached csv file generated and the plot
    after false-positioning
    c:2.69626
    f(c):-1.78814e-007
    Please find the attached csv file generated and the plot
    after newton-raphson
    root:2.69627
    f(x): 9.98378e-006
    Please find the attached csv file generated and the plot
    */
}
