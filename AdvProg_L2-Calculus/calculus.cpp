#include <iostream>
#include <string>
#include <cmath>

using std::string;
using std::cout;
using std::endl;
using std::stod;


double mySin(double x);
double myCos(double x);
double mySqrt(double x);

/***
    Args:
        x (double): a number
    Returns:
        double: cosine of x
***/
double myCos(double x) 
{
    return cos(x);
}

/***
    Args:
        x (double): a number
    Returns:
        double: sine of x
***/
double mySin(double x)
{
    return sin(x);
}


/***
    Args:
        x (double): a number
    Returns:
        double: square root of x
***/
double mySqrt(double x) {
    double ErrorNumber =0.0001;
    if (x < 0) {
        cout << "Invalid argument" << endl;
        exit(1);
    }
    else{
    double sqrtX=x, oldSqrtX=1;
    while(sqrtX- oldSqrtX>ErrorNumber){
        oldSqrtX= sqrtX;
        sqrtX = (oldSqrtX+(x/oldSqrtX))/2;
    }
    return sqrtX;
    }
}