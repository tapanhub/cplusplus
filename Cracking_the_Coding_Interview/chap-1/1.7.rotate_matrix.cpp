/*****************************************************************************
 * Rotate matrix:
 * Given an image represented by an NxN matrix, where each pixel in the image
 * is 4 bytes, write a method to rotate the image by 90 degrees.
 * steps to compile:
 * g++ --std=c++11 1.7.rotate_matrix.cpp -o rotate_matrix
 * solution:
 * rotate right:  i,j  => n-j, n-i
 * rotate left:    i,j  => n-j, i
 ****************************************************************************/
#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;
class matrix {
    int **p = NULL; //to store 2d matrix pointer
    int rows = 0;
    int columns = 0;
public:
    matrix(int row, int column);
    matrix(int **,int row, int column);
    ~matrix();
    class matrix rotate_right(void);
    class matrix rotate_left(void);
    int **allocate_matrix(int row, int column);
    void free_matrix(int ***p);
    int fill(void);
    int show(void);
};

int ** matrix::allocate_matrix(int row, int column) {
    int **p = NULL;
    p = new int *[row];
    if(p) {
        for(int i=0; i< row; i++) {
            p[i]= new int[column];
        }
    }
    return p;
}

void matrix::free_matrix(int ***ptr) {
    int **p = *ptr;
    if(p) {
        for(int i=0; i< rows; i++) {
            delete [] p[i];
        }
        delete [] p;
    }
    *ptr = NULL;
}
matrix::matrix(int row, int col) {
    rows = row;
    columns = col;
    p = allocate_matrix(row, col);
}
matrix::matrix(int **ptr, int row, int col) {
    rows = row;
    columns = col;
    p = ptr;
}

matrix::~matrix(void) {
    if(p) {
        free_matrix(&p);
    }
    rows = 0;
    columns = 0;
}

int matrix::show(void) {
    cout << "matrix(" << rows << "," << columns << ")" << endl;
    for(int i=0; i < rows; i++) {
        for (int j=0; j < columns; j++) {
            cout << setw(3) << p[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}

int matrix::fill(void) {
    int s = 0;
    for(int i=0; i < rows; i++) {
        for (int j=0; j < columns; j++) {
            p[i][j] = s++;
        }
    }
    return 0;
}

class matrix matrix::rotate_right(void) {
    int **res = allocate_matrix(columns, rows);
    for(int i=0; i < rows; i++) {
        for (int j=0; j < columns; j++) {
            res[j][rows-i-1] = p[i][j];
        }
    }
    class matrix resultm(res, columns, rows);
    return resultm;
}

class matrix matrix::rotate_left(void) {
    int **res = allocate_matrix(columns, rows);
    for(int i=0; i < rows; i++) {
        for (int j=0; j < columns; j++) {
            res[columns-j-1][i] = p[i][j];
        }
    }
    class matrix resultm(res, columns, rows);
    return resultm;
}

int main()
{
    class matrix m(5,3);
    m.fill();
    m.show();
    class matrix rr = m.rotate_right();
    rr.show();
    class matrix rl = m.rotate_left();
    rl.show();
    rl.rotate_right().show();
    rr.rotate_left().show();
    return 0;
}
