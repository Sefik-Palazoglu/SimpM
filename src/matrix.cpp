/**
 * Matrix implementation for SimpM.
 * 
 * Copyright (C) 2021-2022 Sefik-Palazoglu.
 * 
 * This file is part of SimpM.
 * 
 * SimpM is free software; you can redistribute it and/or modify it under the
 * terms of the GNU General Public License as published by the Free Software
 * Foundation; either version 3 of the License, or (at your option) any later
 * version.
 * 
 * SimpM is distributed in the hope that it will be useful, but WITHOUT ANY
 * WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR
 * A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 * You should have received a copy of the GNU General Public License along with
 * this program. If not, see <http://www.gnu.org/licenses/>.
 */

/**
 * implement basic operations with matrices
 * including initialization, display, addition, multiplication...
 */

#include <iostream>
#include "matrix.h"

Matrix::Matrix(std::ifstream &in)
{
    in >> maxRow_m >> maxCol_m >> augmented_m;
    for (int row = 0; row < maxRow_m; ++row)
    {
        matrix_m.push_back(row_t(maxCol_m));
        for (size_t col = 0; col < maxCol_m; ++col)
        {
            in >> matrix_m[row][col];
            // all quotients must be canonicalized this is requested by gmp library
            matrix_m[row][col].canonicalize();
        }
    }

    /* TODO(Sefik-Palazoglu) make these asserts */
/*     if (maxRow_m != matrix_m.size())
        std::cerr << "Row numbers failure\n";
    if (maxCol_m != matrix_m[0].size())
        std::cerr << "Col numbers failure\n"; */
}

void Matrix::show(std::ostream &out) const
{
    for (int row = 0; row < maxRow_m; ++row)
    {
        for (int col = 0; col < maxCol_m; ++col)
        {
            if ((0 < augmented_m) && (col == maxCol_m - 1))
                // if at the last col and augmented, put |
                out << "| " << matrix_m[row][col] << '\t';
            else
                // else put normally
                out << matrix_m[row][col] << '\t';
        }
        out << "\n";
    }
}

void Matrix::swapRows(row_t &r1, row_t &r2)
{
    for (int col = 0; col < maxCol_m; col++)
        r1[col].swap(r2[col]);
}

void Matrix::swapRows(int i1, int i2)
{
    // TODO(Sefik-Palazoglu) Add range check here
    swapRows(matrix_m[i1], matrix_m[i2]);
}

void Matrix::scaleRow(row_t &row, num_type scalar) const
{
    // TODO(Sefik-Palazoglu) Add range check here
    for (int col = 0; col < maxCol_m; ++col)
        row[col] *= scalar;
}

void Matrix::scaleRow(int row, num_type scalar)
{
    scaleRow(matrix_m[row], scalar);
}

Matrix::row_t Matrix::scaleRowCopy(const row_t &row, num_type scalar) const
{
    row_t result{row};
    scaleRow(result, scalar);
    return result;
}

void Matrix::addRows(row_t &row1, const row_t &row2)
{
    for (int col = 0; col < maxCol_m; ++col)
        row1[col] += row2[col];
}

void Matrix::addRows(int row1, int row2)
{
    addRows(matrix_m[row1], matrix_m[row2]);
}

bool Matrix::normalizeRowWRTCol(int row, int col, Matrix &comatrix)
{
    // TODO(Sefik-Palazoglu) Add range check here
    if (matrix_m[row][col] == 0)
        return false;
    
    scaleRow(row, 1 / matrix_m[row][col]);
    comatrix.scaleRow(row, 1 / matrix_m[row][col]);
    std::cout << "in normalize\n";
    comatrix.show(std::cout);
    return true;
}

bool Matrix::normalizeRowWRTCol(int row, int col)
{
    // TODO(Sefik-Palazoglu) Add range check here
    if (matrix_m[row][col] == 0)
        return false;
    
    scaleRow(row, 1 / matrix_m[row][col]);
    return true;
}

bool Matrix::pivot(int row, int col)
{
    // TODO(Sefik-Palazoglu) Add range check here
    if (matrix_m[row][col] == 0)
        return false;
    
    this->normalizeRowWRTCol(row, col);
    for (int otherRow = 0; otherRow < maxRow_m; ++otherRow)
        if (otherRow != row)
            addRows(matrix_m[otherRow], scaleRowCopy(matrix_m[row], -matrix_m[otherRow][col]));
    
    return true;
}


bool Matrix::pivot(int row, int col, Matrix &comatrix)
{
    // TODO(Sefik-Palazoglu) Add range check here
    if (matrix_m[row][col] == 0)
        return false;
    
    this->normalizeRowWRTCol(row, col, comatrix);
    std::cout << "in pivot\n";
    comatrix.show(std::cout);
    for (int otherRow = 0; otherRow < maxRow_m; ++otherRow)
        if (otherRow != row)
        {
            addRows(matrix_m[otherRow], scaleRowCopy(matrix_m[row], -matrix_m[otherRow][col]));
            comatrix.addRows(comatrix.matrix_m[otherRow], scaleRowCopy(comatrix.matrix_m[row], -matrix_m[otherRow][col]));
        }
    
    return true;
}