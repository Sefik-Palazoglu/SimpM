/**
 * @file test_pivot.cpp
 * @author Sefik-Palazoglu
 * 
 * compilation:
 *      g++ -std=c++17 -I../include prompt.cpp ./matrix.cpp -o prompt.out -lgmp -lgmpxx
 * usage:
 *      ./prompt.out data1.txt
 * given that data-1.txt is formatted for the matrix class constructor
 * 
 * tests if we can pivot at [row][col]
 * a display test
 */

#include <iostream>
#include <fstream>
#include "matrix.h"

int main(int argc, char *argv[])
{
    std::ifstream in;
    in.open(argv[1]);
    Matrix matrix(in);
    matrix.show(std::cout);

    in.close();

    while (true)
    {
        int row, col;
        std::cout << "enter col and row to pivot: ";
        std::cin >> row >> col;
        matrix.pivot(row, col);
        std::cout << "=============================\n";
        matrix.show(std::cout);
    }

}