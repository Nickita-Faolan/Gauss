#include "Vector.h"
#include "Matrix.h"
#include "Solver.h"
using namespace std;

int main() {
    try {

        int n = 3;
        double** matrix = new double* [n];
        for (int i = 0; i < n; ++i) {
            matrix[i] = new double[n];
        }
        double* vector = new double[n];
        double* xV = new double[n];
        matrix[0][0] = 2;
        matrix[0][1] = 3;
        matrix[0][2] = 5;
        matrix[1][0] = 3;
        matrix[1][1] = 5;
        matrix[1][2] = 2;
        matrix[2][0] = 5;
        matrix[2][1] = 2;
        matrix[2][2] = 3;
        vector[0] = 38;
        vector[1] = 31;
        vector[2] = 31;
        xV[0] = 2;
        xV[1] = 3;
        xV[2] = 5;


        Solver s;
        Matrix A(matrix, n, n);
        Vector b(vector, n), x(xV, n);

        s.generate();
        Vector res = s.solve();
        cout << endl << "###SOLVER###" << endl << res;
        cout << endl << "###CHECKER###" << endl << s.check();
    }
    catch (const char* exception) {
        cerr << exception;
    }

    return 0;
}