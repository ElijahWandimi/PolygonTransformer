#include<iostream>
#include<vector>
#include<math.h>
#include<random>

using namespace std;


class Polygon {
    private:
        string name;
        double r;
        int N;

        vector<double> xCood;
        vector<double> yCood;

        
        /* utility functions to reduce code repetitions */

        // a display function to show the details of the polygon before and after the transformations
        void displayDetails(vector<double> x, vector<double> y) {
            cout<<name <<"= polygon(";
            for (int i=0; i<x.size(); i++) {
                cout<<"("<<x[i]<< ","<<y[i] << ")";
            }
            cout<<")\n";                                    
        }

        // random  double generator
        double random_point() {
                double f = (double)rand() / RAND_MAX;
                return 1 + f * (15 - 1);
            }

    public:
        Polygon(string name, int N, double r) {
            this->name = name;
            this->r = r;
            this->N = N;
            // initialize the polygon
            for (int i =0; i < this->N; i++) {
                xCood.push_back(random_point()+r);
                yCood.push_back(random_point()+r);
            }
            showPolygon();
        };

        // function to show the initialized polygon before any transformation is undertaken
        void showPolygon() {
            cout<<"\n**********\n" <<name <<"= polygon(";
            for (int i=0; i<this->N; i++) {
                cout<<"("<<xCood[i]<<","<< yCood[i] << ")";
            }
            cout<<")\n";                                    
        }

        // translate function to translate the polygon along the axis
        void translate(vector<double> t) {
            // before translation
            cout<<"Before translation: \n";
            displayDetails(this->xCood, this->yCood);

            // translation of the polygon
            for (int k=0; k < xCood.size(); k++) {
                xCood[k] = xCood[k]+ t[0];
                yCood[k] = yCood[k]+ t[1];
            }

            // after translation
            cout<<"\nAfter translation: \n";
            displayDetails(xCood, yCood);
        }

        // rotation function for the polygon about origin
        void rotate(double angle) {
            // before rotation
            cout<<"Before rotation: \n";
            displayDetails(xCood, yCood);

            // create points, an (x, y) matrix from vectors x and y
            double points[2][N];
            for (int i = 0; i < 1; i++) {
                for (int j = 0; j < N; j++) {
                    points[i][j] = xCood[j];
                    points[i+1][j] = yCood[j];
                }
            }

            // create a multiplication matrix 
            double mat[2][N];
            // initialize the matrix to 0
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < N; j++) {
                    mat[i][j] = 0;
                }
            }

            // rotation by A degrees
            double rotMat [2][2] = {{cos(angle), (0 - sin(angle))}, {sin(angle), cos(angle)}};
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < 2; k++) {
                        mat[i][j] += (rotMat[i][k] * points[k][j]);
                    }
                }
            }             

            // after rotation
            cout<<"after rotation: \n";
            for (int i = 0; i < 1; i++) {
                for (int j = 0; j < N; j++) {
                    xCood[j] = mat[i][j];
                    yCood[j] = mat[i+1][j];
                }
            }
            displayDetails(xCood, yCood);
        }
};


int main(int argc, char const *argv[])
{
    //translation vector
    vector<double> t = {{2, 4}};

    // rotation angle
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
