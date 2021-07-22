#include <stdio.h>
#include <stdlib.h>

void matrix_mult(size_t n, size_t k, size_t m,
		double C[n][m],
		double A[n][k],
		double B[k][m]) {
	for (size_t i = 0; i < n; ++i) {
		for (size_t j = 0; j < m; ++j) {
			C[i][j] = 0.0;
			for(size_t l = 0; l < k; ++l) {
				C[i][j] += A[i][l] * B[l][j];
			}
		}
	}
}
			
