#include<iostream>
#include<vector>
#include<random>

using namespace std;

class Polygon3D {
    protected:
        string name;

        vector<double> xCood;
        vector<double> yCood;
        vector<double> zCood;

        void showPolygon() {
            cout<<"\n**********\n" <<name <<"= polygon(";
            for (int i=0; i<xCood.size(); i++) {
                cout<<"("<<xCood[i]<< ","<<yCood[i]<<","<<zCood[i]<< ")";
            }
            cout<<")\n";                                    
        }

        // a display function to show the details of the polygon before and after the transformations :: DRY
        void displayDetails(vector<double> x, vector<double> y) {
            cout<<name <<"= polygon(";
            for (int i=0; i<x.size(); i++) {
                cout<<"("<<x[i]<< ","<<y[i]<< ")";
            }
            cout<<")\n";                                    
        }

    public:
        Polygon3D(string name, vector<double> xcood, vector<double> ycood, vector<double> zcood) {
            this->name = name;
            this->xCood = xcood;
            this->yCood = ycood;
            this->zCood = zcood;
            this->showPolygon();
        };

        virtual void translate(vector<double> t) = 0;

        virtual void rotate(double angle) = 0;
};

// Polygon_xy
class Polygon_xy: public Polygon3D {
    string name;
    public:
        Polygon_xy(string name, vector<double> xCood, vector<double> yCood, vector<double> zCood): Polygon3D(name, xCood, yCood, zCood) {
            this->name = name;
        }

        void translate(vector<double> tr) {
            // before translation
            cout<<"Before translation: \n";
            displayDetails(xCood, yCood);

            // translation of the polygon
            for (int k=0; k < xCood.size(); k++) {
                xCood[k] = xCood[k]+ tr[0];
                yCood[k] = yCood[k]+ tr[1];
            }

            // after translation
            cout<<"\nAfter translation: \n";
            displayDetails(xCood, yCood);
        }

        void rotate(double a) {
            int N = xCood.size();
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
            double rotMat [2][2] = {{cos(a), (0 - sin(a))}, {sin(a), cos(a)}};
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < 2; k++) {
                        mat[i][j] += (rotMat[i][k] * points[j][k]);
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

        Polygon_xy operator +(const Polygon_xy& p) {
            Polygon_xy px(name, xCood, yCood, zCood);
            for (int i = 0; i < 3; i++) {
                px.xCood[i] = p.xCood[i] + this->xCood[i];
                px.yCood[i] = p.yCood[i] + this->yCood[i];
                px.zCood[i] = p.zCood[i] + this->zCood[i];
            }
            return px;
        }
};

// Polygon_xz
class Polygon_xz: public Polygon3D {
    string name;
    public:
        Polygon_xz(string name, vector<double> xCood, vector<double> yCood, vector<double> zCood): Polygon3D(name, xCood, yCood, zCood) {
            this->name = name;
        }

        void translate(vector<double> tr) {
            // before translation
            cout<<"Before translation: \n";
            displayDetails(xCood, zCood);

            // translation of the polygon
            for (int k=0; k < xCood.size(); k++) {
                xCood[k] = xCood[k]+ tr[0];
                zCood[k] = zCood[k]+ tr[1];
            }

            // after translation
            cout<<"\nAfter translation: \n";
            displayDetails(xCood, zCood);
        }

        void rotate(double a) {
            int N = xCood.size();
            // before rotation
            cout<<"Before rotation: \n";
            displayDetails(xCood, zCood);

            // create points, an (x, y) matrix from vectors x and y
            double points[2][N];
            for (int i = 0; i < 1; i++) {
                for (int j = 0; j < N; j++) {
                    points[i][j] = xCood[j];
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
            cout<<"after rotation: \n";
            for (int i = 0; i < 1; i++) {
                for (int j = 0; j < N; j++) {
                    xCood[j] = mat[i][j];
                    zCood[j] = mat[i+1][j];
                }
            }
            displayDetails(xCood, zCood);
        }
};

//Polygon_yz
class Polygon_yz: public Polygon3D {
    string name;
    public:
        Polygon_yz(string name, vector<double> xCood, vector<double> yCood, vector<double> zCood): Polygon3D(name, xCood, yCood, zCood) {
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
            int N = xCood.size();
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
            cout<<"after rotation: \n";
            for (int i = 0; i < 1; i++) {
                for (int j = 0; j < N; j++) {
                    yCood[j] = mat[i][j];
                    zCood[j] = mat[i+1][j];
                }
            }
            displayDetails(yCood, zCood);
        }
};

// random  double generator
double random_point() {
    double f = (double)rand() / RAND_MAX;
    return 1 + f * (15 - 1);
}


int main(int argc, char const *argv[]) {
    //translation vector
    vector<double> t = {{2, 4}};
    vector<double> xcood;
    vector<double> ycood;
    vector<double> zcood;

    for (int i =0; i < 10; i++) {
        xcood.push_back(random_point());
        ycood.push_back(random_point());
        zcood.push_back(random_point());
    }

    // rotation angle
    double angle = 90.0;

    // xy polygon
    Polygon_xy tria("pxy_1", xcood, ycood, zcood);
    tria.translate(t);
    tria.rotate(angle);

    // xz polygon
    Polygon_xz sq("pxz_1", xcood, ycood, zcood);
    sq.translate(t);
    sq.rotate(angle);

    // yz polygon 
    Polygon_yz ng("pyz_1", xcood, ycood, zcood);
    ng.translate(t);
    ng.rotate(angle);

    return 0;
}
