/**
 * @file test_pivot.cpp
 * @author Sefik-Palazoglu
 * 
 * compilation:
 *      g++ -std=c++17 -I../include test_pivot.cpp ../src/matrix.cpp -o test_pivot.out -lgmp -lgmpxx
 * usage:
 *      ./test_pivot.out data-1.txt
 * given that data-1.txt is formatted for the matrix class constructor
 * 
 * tests if we can pivot at [row][col]
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

    in.close();
    in.open("./identity.txt");
    Matrix identity(in);

    matrix.show(std::cout);
    std::cout << "===========================\n";
    identity.show(std::cout);

    std::cout << std::endl;
    matrix.pivot(0, 0, identity);
    matrix.show(std::cout);
    std::cout << "===========================\n";
    identity.show(std::cout);

    std::cout << std::endl;
    matrix.pivot(1, 1, identity);
    matrix.show(std::cout);
    std::cout << "===========================\n";
    identity.show(std::cout);

    std::cout << std::endl;
    matrix.pivot(2, 2, identity);
    matrix.show(std::cout);
    std::cout << "===========================\n";
    identity.show(std::cout);
    std::cout << std::endl;

    return 0;
}