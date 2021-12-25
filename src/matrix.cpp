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

void Matrix::scaleRow(int rowIndex, num_type scalar)
{
    // TODO(Sefik-Palazoglu) Add range check here
    for (int col = 0; col < maxCol_m; ++col)
        matrix_m[rowIndex][col] *= scalar;
}

bool Matrix::normalizeRowWRTCol(int row, int col)
{
    if (matrix_m[row][col] == 0)
        return false;
    
    scaleRow(row, 1 / matrix_m[row][col]);
}