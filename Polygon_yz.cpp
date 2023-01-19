#include<math.h>
#include"Polygon3D.cpp"

class Polygon_yz: public Polygon3D {
    string name;
    public:
        Polygon_yz(): Polygon3D(name) {
            this->name = name;
        }

        void translate(vector<double> tr) {
            // before translation
            cout<<"Before translation: \n";
            displayDetails(yCood, zCood);

            // translation of the polygon
            for (int k=0; k < yCood.size(); k++) {
                yCood[k] = yCood[k]+ tr[0];
                zCood[k] = zCood[k]+ tr[1];
            }

            // after translation
            cout<<"\nAfter translation: \n";
            displayDetails(yCood, zCood);
        }

        void rotate(double a) {
            // before rotation
            cout<<"Before rotation: \n";
            displayDetails(yCood, zCood);

            // create points, an (x, y) matrix from vectors x and y
            double points[2][N];
            for (int i = 0; i < 1; i++) {
                for (int j = 0; j < N; j++) {
                    points[i][j] = yCood[j];
                    points[i+1][j] = zCood[j];
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
            double rotMat [2][2] = {{cos(a), (0 - sin(a))}, {sin(a), cos(a)}};
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < 2; k++) {
                        mat[i][j] += (rotMat[i][k] * points[j][k]);
                    }
                }
            }             

            // after rotation
            for (int i = 0; i < 1; i++) {
                for (int j = 0; j < N; j++) {
                    yCood[j] = mat[i][j];
                    zCood[j] = mat[i+1][j];
                }
            }
            displayDetails(yCood, zCood);
        }
};