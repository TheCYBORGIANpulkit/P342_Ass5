#include <iostream>  //declaring variables
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cmath>
using namespace std;

float Polynomial(float* coeff, float x, int n){
	float val = 0;
	for (int i = 0; i <= n; i++){
		float prod = 1;
		for (int j = i; j < n; j++)
			prod = prod * x;
		val = val + (coeff[i] * prod);
	}
	return val;
}

float* derivative(float* arr, int n){
	int a = n - 1;
	float der[n];
	float* dx = der;
	for (int i = 0; i <= n - 1; i++){
		der[i] = arr[i]*(n-i);
	}
	return dx;
}
float laguerre(float* coeff, float x, int n){
	int Count = 0;
	float f, g, a;
	float h = 0.000001;
	float* der1 = derivative(&coeff[0], n);
	float* der2 = derivative(&der1[0], n-1);

	do{
		f = Polynomial(&coeff[0], x, n);
		g = Polynomial(&der1[0], x, n - 1);
		h = Polynomial(&der2[0], x, n - 2);
		float G = g / f;
		float H = pow(G,2) - (h / f);
		float F = sqrt((n - 1) * (n * H - G * G));
		if (abs(g + f) > abs(g - f))a = n / (G + F);
		else a = n / (G - F);
		x = x - a;
		Count++;
	}
	while (f > h && Count < 200 && a > h);
	return x;
}

float* deflate(float* arr, float x, int n){
    float r[n];
	float* rem = r;
	r[0] = arr[0];
	for (int i = 1; i <= n; i++){
		r[i] = (r[i - 1] * x) + arr[i];
	}
	return &rem[0];
}


int main(){
    float coeff[5] = {1,-3,-7,27,-18};
    float x = 0;
    x = int(laguerre(&coeff[0], 4.2, 4));

    cout << "1st root: " << x << endl;
    float* temp = deflate(&coeff[0], x, 4);

    for (int i = 1; i < 3; i++){
        x =int(laguerre(temp, x, 4 - i));

        cout << i+1 << "th root is: " << int(x) << endl;
        temp = deflate(temp, x, 4);
        //cout << temp
    }
    float c = 0 - temp[1];
    cout << 4 <<  " th Root is:" << int(c) << endl;
    return 0;
    /*
    1st root: 3
    2th root is: 2
    3th root is: -2147483648
    4 th Root is:0
    */
}
