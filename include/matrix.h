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

    /**
     * @brief swaps two rows of the matrix
     * 
     * @param r1 first row
     * @param r2 second row
     */
    void swapRows(row_t &r1, row_t &r2);

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
     * augmented part of the matrix is displayed with a "| " prefix
     * 
     * @param out output stream to display matrix
     */
    void show(std::ostream &out) const;

    /**
     * @brief swaps two rows of the matrix by index
     * 
     * @param i1 first row's index
     * @param i2 second row's index
     */
    void swapRows(int i1, int i2);

    /**
     * @brief scale a row by a scalar
     * multiply the row with scalar
     * 
     * @param row index of the row
     * @param scalar the number to multiply with
     */
    void scaleRow(int row, num_type scalar);

    /**
     * @brief normalizes a row wrt row[col]
     * makes M[row][col] 1 by
     * multiplies all elements of the row with 1 / M[row][col]
     * 
     * Can fail if M[row][col] is 0,
     * in this case, return false and don't do anything
     * return true otherwise
     * 
     * @param row index of row to be normalized
     * @param col index of element to be respected
     * @returns Can fail if M[row][col] is 0,
     * in this case, return false and don't do anything
     * return true otherwise
     */
    bool normalizeRowWRTCol(int row, int col);

    //bool pivot(int )
};

#endif /* _MATRIX_H_ */