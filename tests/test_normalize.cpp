/**
 * @file test_normalize.cpp
 * @author Sefik-Palazoglu
 * 
 * compilation:
 *      g++ -std=c++17 -I../include test_normalize.cpp ../src/matrix.cpp -o test_normalize.out -lgmp -lgmpxx
 * usage:
 *      ./test_normalize.out data-1.txt
 * given that data-1.txt is formatted for the matrix class constructor
 * 
 * tests if we can normalize a row with respect to an element of the row
 * a display test
 */

#include <fstream>
#include <iostream>
#include "matrix.h"

int main(int argc, char *argv[])
{
    std::ifstream in;
    in.open(argv[1]);

    Matrix matrix(in);
    matrix.show(std::cout);
    std::cout << std::endl;
    matrix.normalizeRowWRTCol(2, 1);
    matrix.show(std::cout);

    return 0;
}