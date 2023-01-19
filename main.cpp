#include<stdlib.h>
#include<iostream>
#include"Polygon.cpp"
#include<random>
#include<vector>

using namespace std;

int main(int argc, char const *argv[])
{
    //translation vector
    vector<double> t = {{2, 4}};
    // // rotation angle
    double angle = 90.0;

    // // triangle
    Polygon tria("tr_1", 3, 3.4);
    tria.translate(t);
    tria.rotate(angle);

    // square
    Polygon sq("sq_1", 4, 2.4);
    sq.translate(t);
    sq.rotate(angle);

    // n-gon polygon (n > 4)
    Polygon ng("ng_1", 7, 2);
    ng.translate(t);
    ng.rotate(angle);

    return 0;
}
