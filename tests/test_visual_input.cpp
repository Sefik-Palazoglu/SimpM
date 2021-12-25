/**
 * @file test_visual_input.cpp
 * @author Sefik-Palazoglu
 * 
 * compilation:
 *      g++ -std=c++17 -I../include test_visual_input.cpp ../src/matrix.cpp -o test_visual_input.out -lgmp -lgmpxx
 * usage:
 *      ./test_visual_input.out data-1.txt
 * given that data-1.txt is formatted for the matrix class constructor
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

    return 0;
}