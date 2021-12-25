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

    /**
     * @brief add row2 to row1
     * row2 does not change
     * row1 becomes itself + row2
     * 
     * @param r1 first row
     * @param r2 second row
     */
    void addRows(row_t &row1, const row_t &row2);

    /**
     * @brief scale a row by a scalar
     * multiply the row with scalar
     * 
     * @param row row to be scaled
     * @param scalar the number to multiply with
     */
    void scaleRow(row_t &row, num_type scalar) const;

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
     * @param row1 first row's index
     * @param row2 second row's index
     */
    void swapRows(int row1, int row2);

    /**
     * @brief add row2 to row1
     * row2 does not change
     * row1 becomes itself + row2
     * 
     * @param row1 index of the row
     * @param row2 the number to multiply with
     */
    void addRows(int row1, int row2);

    /**
     * @brief scale a row by a scalar
     * multiply the row with scalar
     * 
     * @param row index of the row
     * @param scalar the number to multiply with
     */
    void scaleRow(int row, num_type scalar);

    /**
     * @brief scale a row by a scalar
     * multiply the row with scalar
     * 
     * @param row index of the row
     * @param scalar the number to multiply with
     * @returns copy of the row scaled
     */
    row_t scaleRowCopy(const row_t &row, num_type scalar) const;

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
     * @returns fails if M[row][col] is 0,
     * in this case, return false and don't do anything
     * return true otherwise
     */
    bool normalizeRowWRTCol(int row, int col);

    /**
     * @brief try to pivot at M[row][col]
     * normalize M[row] wrt col,
     * make M[x][col] 0 for all x except row 
     * by subtracting row from other rows
     * 
     * @param row index of row where pivot is
     * @param col index of col where pivot is
     * @returns fails if M[row][col] is 0,
     * in this case, return false and don't do anything
     * return true otherwise
     */
    bool pivot(int row, int col);

    /**
     * @brief comatrix version of pivot,
     * do every operation with same scalars to comatrix
     * start comatrix as identity to find inverse etc.
     * 
     * @param row index of row where pivot is
     * @param col index of col where pivot is
     * @returns fails if M[row][col] is 0,
     * in this case, return false and don't do anything
     * return true otherwise
     */
    bool pivot(int row, int col, Matrix &comatrix);
};

#endif /* _MATRIX_H_ */