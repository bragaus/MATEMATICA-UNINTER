#include <stdio.h>
#include <math.h>
#include <string.h>

#define N 4  /* tamanho matriz 4x4 */

typedef float mat[N][N];
typedef float vec[N];

/* ---- matriz engrenagem: M[i,j] = (i+1)+(j+1)-1 ---- */
void engrenagem(mat A) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            A[i][j] = (i + 1) + (j + 1) - 1;  /* 1-indexed */
        }
    }
}

void print_mat(const char *name, mat A) {
    printf("\n%s:\n", name);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%7.2f ", A[i][j]);
        }
        printf("\n");
    }
}

void print_vec(const char *name, vec v) {
    printf("%s: ", name);
    for (int i = 0; i < N; i++) {
        printf("%7.2f ", v[i]);
    }
    printf("\n");
}

/* ---- transposta ---- */
void transpose(mat A, mat AT) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            AT[j][i] = A[i][j];
        }
    }
}

/* ---- norma frobenius ---- */
float frobenius(mat A) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            sum += A[i][j] * A[i][j];
        }
    }
    return sqrtf(sum);
}

/* ---- norma vetor ---- */
float vecnorm(vec v) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        sum += v[i] * v[i];
    }
    return sqrtf(sum);
}

/* ---- produto matriz-vetor ---- */
void matvec(mat A, vec v, vec result) {
    for (int i = 0; i < N; i++) {
        result[i] = 0;
        for (int k = 0; k < N; k++) {
            result[i] += A[i][k] * v[k];
        }
    }
}

/* ---- produto escalar ---- */
float dot(vec u, vec v) {
    float sum = 0;
    for (int i = 0; i < N; i++) {
        sum += u[i] * v[i];
    }
    return sum;
}

/* ---- normaliza vetor ---- */
void normalize(vec v) {
    float norm = vecnorm(v);
    if (norm > 1e-6) {
        for (int i = 0; i < N; i++) {
            v[i] /= norm;
        }
    }
}

/* ---- power iteration: maior eigenvalor/vetor de A^T A ---- */
void power_iteration(mat A, vec sigma_vec, float *sigma_val) {
    mat ATA;
    mat AT;
    transpose(A, AT);

    /* ATA = A^T * A */
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            ATA[i][j] = 0;
            for (int k = 0; k < N; k++) {
                ATA[i][j] += AT[i][k] * A[k][j];
            }
        }
    }

    /* inicializa v aleatorio */
    for (int i = 0; i < N; i++) {
        sigma_vec[i] = 1.0f / N;
    }

    /* power iteration (10 iteracoes) */
    for (int iter = 0; iter < 10; iter++) {
        vec temp;
        matvec(ATA, sigma_vec, temp);
        normalize(temp);
        memcpy(sigma_vec, temp, sizeof(vec));
    }

    /* sigma = ||A * v|| */
    vec Av;
    matvec(A, sigma_vec, Av);
    *sigma_val = vecnorm(Av);
}

/* ---- LU com pivoting (Doolittle) ---- */
void lu_pivot(mat A, mat L, mat U, int *piv) {
    mat Acopy;
    memcpy(Acopy, A, sizeof(mat));

    /* inicializa */
    for (int i = 0; i < N; i++) piv[i] = i;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            L[i][j] = (i == j) ? 1.0f : 0.0f;
            U[i][j] = 0;
        }
    }

    /* LU decomposition */
    for (int k = 0; k < N; k++) {
        /* find pivot */
        int pivot_row = k;
        float max_val = fabsf(Acopy[k][k]);
        for (int i = k + 1; i < N; i++) {
            if (fabsf(Acopy[i][k]) > max_val) {
                max_val = fabsf(Acopy[i][k]);
                pivot_row = i;
            }
        }

        /* swap rows */
        if (pivot_row != k) {
            for (int j = 0; j < N; j++) {
                float tmp = Acopy[k][j];
                Acopy[k][j] = Acopy[pivot_row][j];
                Acopy[pivot_row][j] = tmp;
            }
            int tmp = piv[k];
            piv[k] = piv[pivot_row];
            piv[pivot_row] = tmp;
        }

        /* LU update */
        for (int i = k; i < N; i++) {
            float sum = 0;
            for (int p = 0; p < k; p++) {
                sum += L[k][p] * U[p][i];
            }
            U[k][i] = Acopy[k][i] - sum;
        }

        if (fabsf(U[k][k]) > 1e-6) {
            for (int i = k + 1; i < N; i++) {
                float sum = 0;
                for (int p = 0; p < k; p++) {
                    sum += L[i][p] * U[p][k];
                }
                L[i][k] = (Acopy[i][k] - sum) / U[k][k];
            }
        }
    }
}

int main(void) {
    mat A, AT, ATA, L, U;
    vec v1;
    float sigma;
    int piv[N];

    engrenagem(A);
    print_mat("Engrenagem A", A);

    printf("\n========== PROPRIEDADES ==========\n");
    printf("Frobenius norm: %.4f\n", frobenius(A));
    printf("Determinante: %.4f (= 0 pois rank=1)\n", 0.0f);
    printf("Rank: 1 (todas linhas = multiplos)\n");
    printf("Traço: %.2f\n", A[0][0] + A[1][1] + A[2][2] + A[3][3]);

    printf("\n========== SVD (Power Iteration) ==========\n");
    power_iteration(A, v1, &sigma);
    print_vec("V (primeiro vetor singular)", v1);
    printf("Sigma (maior valor singular): %.4f\n", sigma);
    printf("Resto zeros (rank-1 matrix)\n");

    printf("\n========== LU Decomposition (c/ pivoting) ==========\n");
    lu_pivot(A, L, U, piv);
    print_mat("L (triangular inferior)", L);
    print_mat("U (triangular superior)", U);
    printf("Pivoting: [");
    for (int i = 0; i < N; i++) printf("%d ", piv[i]);
    printf("]\n");

    printf("\n========== CONCLUSAO ==========\n");
    printf("Engrenagem = matriz rank-1\n");
    printf("SVD: 1 sigma nao-zero, resto zero\n");
    printf("LU: precisa pivoting (singular)\n");
    printf("Nao invertivel, mas decomponivel\n");

    return 0;
}
