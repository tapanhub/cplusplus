/*****************************************************************************
 * Write an algorithm such that if an element in an MxN matrix is 0, its
 * entire row and column are set to 0.
 * command to compile:
 * g++ --std=c++11 1.8.zero_matrix.cpp -o zero_matrix
 ****************************************************************************/

#include <iostream>
#include <cstdio>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;
class matrix {
    int **p = NULL; //to store 2d matrix pointer
    int rows = 0;
    int columns = 0;
public:
    matrix(int row, int column);
    matrix(int **,int row, int column);
    ~matrix();
    int **allocate_matrix(int row, int column);
    void free_matrix(int ***p);
    int fill(void);
    int fill(int);
    int mzero(void);
    int show(void);
    int set(int row, int col, int val);
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

int matrix::fill(int start) {
    int s = start;
    for(int i=0; i < rows; i++) {
        for (int j=0; j < columns; j++) {
            p[i][j] = s++;
        }
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

int matrix::set(int row, int col, int val) {
    if(row >=0 && row < rows && col >=0 && col < columns)
        p[row][col] = val;
    else
        cout << "Invalid  " << row << "x" << col << endl;
        return -1;
    return 0;
}


int matrix::mzero(void) {
    int s = 0;
    unordered_set<int>  row_set;
    unordered_set<int>  col_set;
    for(int i=0; i < rows; i++) {
        for (int j=0; j < columns; j++) {
            if (p[i][j] == 0) {
                row_set.insert(i);
                col_set.insert(j);
            }
        }
    }
    for(auto row: row_set) {
        for(int c=0; c < columns; c++)
            p[row][c] = 0;
    }

    for(auto col: col_set) {
        for(int r=0; r < rows; r++)
            p[r][col] = 0;
    }
    return 0;
}


int main()
{
    class matrix m = matrix(5,6);
    m.fill(1);
    m.show();
    m.set(3,4,0);
    m.set(2,1,0);
    m.set(4,3,0);
    m.show();
    m.mzero();
    m.show();
    return 0;
}


