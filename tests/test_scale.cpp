/**
 * @file test_scale.cpp
 * @author Sefik-Palazoglu
 * 
 * compilation:
 *      g++ -std=c++17 -I../include test_scale.cpp ../src/matrix.cpp -o test_scale.out -lgmp -lgmpxx
 * usage:
 *      ./test_scale.out data-1.txt
 * given that data-1.txt is formatted for the matrix class constructor
 * 
 * tests if we can scale a row of a given matrix
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
    matrix.scaleRow(1, 8);
    matrix.show(std::cout);

    return 0;
}