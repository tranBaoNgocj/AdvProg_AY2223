#include <iostream>
#include <string>
#include <cmath>
#include "calculus.h"

using std::string;
using std::cout;
using std::endl;
using std::stod;

const string PREFIX = "lib_";

double callFunction(string func, double x);
double mySin(double x);
double myCos(double x);
double mySqrt(double x);

int main(int argc, char* argv[])
{
    if (argc != 3) {
        cout << "Invalid arguments" << endl;
        return 1;
    }

    string func = argv[1];
    double x = stod(argv[2]);
    cout << "Computed by this program:  " << callFunction(func, x) << endl;
    cout << "Computed by C/C++ library: " << callFunction(PREFIX + func, x) << endl;
    
    return 0;
}

double callFunction(string func, double x)
{
    if (func == "cos") {
        return myCos(x);
    } else if (func == "sin") {
        return mySin(x);
    } else if (func == "sqrt") {
        return mySqrt(x);
    } else if (func == PREFIX + "cos") {
        return cos(x);
    } else if (func == PREFIX + "sin") {
        return sin(x);
    } else if (func == PREFIX + "sqrt") {
        return sqrt(x);
    } else {
        cout << "Invalid function" << endl;
        exit(1);
    }
}

//Calculator sin
double mySin(double x)
{
    int cnt=1;
    double sin=x, oldsin =0;
    //each Number to Plus in
    double eachNumberSin = x;
    while(sin-oldsin){
        oldsin = sin;
        eachNumberSin*=(pow(x,2))/((cnt*2+1)*(cnt*2));
        //Taylor expantion
        sin+=eachNumberSin*pow(-1,cnt); 
        ++cnt;
    }
    return sin;
}

//Calculator cos
double myCos(double x){
    int cnt=1;
    double cos=1, oldCos =0;
    //each number to Plus in
    double eachNumberCos = 1;
    while(cos-oldCos){
        oldCos = cos;
        //Taylor expantion
        eachNumberCos*=(pow(x,2))/((cnt*2-1)*(cnt*2));
        cos+=eachNumberCos*pow(-1,cnt); 
        ++cnt;
    }
    return cos;
}

//calculation Sqrt
double mySqrt(double x){
    double sqrtX=x,oldSqrtX=1;
    if(x==0){
        return 0;
    }
    else{
    while(sqrtX-oldSqrtX){
        oldSqrtX=sqrtX;
        sqrtX= (oldSqrtX+(x/oldSqrtX))/2;
    }
    return sqrtX;
    }
}