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
            in >> matrix_m[row][col];
    }

    /* TODO(Sefik-Palazoglu) make these asserts */
/*     if (maxRow_m != matrix_m.size())
        std::cerr << "Row numbers failure\n";
    if (maxCol_m != matrix_m[0].size())
        std::cerr << "Col numbers failure\n"; */
}

void Matrix::show(std::ostream &out) const
{
    for (int row = 0; row < matrix_m.size(); ++row)
    {
        for (int col = 0; col < matrix_m[0].size(); ++col)
        {
            if ((0 < augmented_m) && (col == maxCol_m - 1))
                out << "| " << matrix_m[row][col] << '\t';
            else
                out << matrix_m[row][col] << '\t';
        }
        out << "\n";
    }
}