/**
 * needs gmp bignum library to be installed on your system
 */

#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <gmp.h>
#include <gmpxx.h>
#include <vector>
#include <fstream>
using std::vector;

class Matrix
{
private:
    using num_type = mpq_class;
    using row_t = vector<num_type>;
    using matrix_t = vector<row_t>; 
    /* data */
    int maxRow_m;
    int maxCol_m;
    bool augmented_m;
    matrix_t matrix_m;

public:
    /**
     * @brief Read from external file and construct the matrix
     * ifstream reads token by token.
     * First token is row count
     * Second token is col count
     * third token tells if matrix is augmented or not
     * 0 means not augmented, otherwise augmented
     * 
     * @param in input stream from which you read numbers
     */
    Matrix(std::ifstream &in);

    /**
     * @brief display matrix on given output stream
     * 
     * @param out output stream to display matrix
     */
    void show(std::ostream &out) const;
};

#endif /* _MATRIX_H_ */