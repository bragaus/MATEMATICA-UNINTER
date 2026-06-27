#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>

#define DIM 1024  /* dimensao embedding */

typedef float vec[DIM];
typedef float mat[DIM][DIM];

/* ---- ativacao: ReLU ---- */
float relu(float x) {
    return x > 0 ? x : 0;
}

/* ---- produto escalar ---- */
float dot(vec u, vec v) {
    float sum = 0;
    for (int i = 0; i < DIM; i++) {
        sum += u[i] * v[i];
    }
    return sum;
}

/* ---- matriz-vetor tradicional: O(N^2) ---- */
void forward_dense(mat W, vec x, vec b, vec out) {
    for (int i = 0; i < DIM; i++) {
        float sum = b[i];
        for (int j = 0; j < DIM; j++) {
            sum += W[i][j] * x[j];
        }
        out[i] = relu(sum);
    }
}

/* ---- rank-1 forward: W = u⊗v, calcula u(v·x) : O(N) ---- */
void forward_rank1(vec u, vec v, vec x, vec b, vec out) {
    float vdotx = dot(v, x);  /* v·x: O(N) */
    for (int i = 0; i < DIM; i++) {
        out[i] = relu(u[i] * vdotx + b[i]);  /* u_i * scalar: O(N) */
    }
}

/* ---- reconstroi W = u⊗v pra verificacao ---- */
void outer_product(vec u, vec v, mat W) {
    for (int i = 0; i < DIM; i++) {
        for (int j = 0; j < DIM; j++) {
            W[i][j] = u[i] * v[j];
        }
    }
}

int main(void) {
    mat W;
    vec u, v, x, b, out_dense, out_rank1;

    /* inicializa vetores */
    for (int i = 0; i < DIM; i++) {
        u[i] = 1.0f + 0.1f * sinf(i);
        v[i] = 0.5f + 0.05f * cosf(i);
        x[i] = 0.1f * (i % 10);
        b[i] = 0.01f;
    }

    /* reconstroi W = u⊗v */
    outer_product(u, v, W);

    printf("========== FORWARD PASS LLM ==========\n");
    printf("Dimensao: %d\n", DIM);
    printf("Neuronio: y = ReLU(W·x + b)\n\n");

    /* ---- DENSE ---- */
    printf("1. Multiplicacao DENSA (O(N^2))\n");
    clock_t t0 = clock();
    for (int rep = 0; rep < 10000; rep++) {
        forward_dense(W, x, b, out_dense);
    }
    clock_t t1 = clock();
    double time_dense = (double)(t1 - t0) / CLOCKS_PER_SEC * 1000;  /* ms */
    printf("   Tempo: %.2f ms (10000 reps)\n", time_dense);

    /* ---- RANK-1 ---- */
    printf("\n2. Multiplicacao RANK-1 (O(N))\n");
    t0 = clock();
    for (int rep = 0; rep < 10000; rep++) {
        forward_rank1(u, v, x, b, out_rank1);
    }
    t1 = clock();
    double time_rank1 = (double)(t1 - t0) / CLOCKS_PER_SEC * 1000;  /* ms */
    printf("   Tempo: %.2f ms (10000 reps)\n", time_rank1);

    /* ---- COMPARACAO ---- */
    printf("\n========== RESULTADO ==========\n");
    printf("Speedup: %.2fx mais rapido\n", time_dense / time_rank1);
    printf("Economia: %.1f%% tempo\n", (1 - time_rank1 / time_dense) * 100);

    /* verifica corretude */
    float max_diff = 0;
    for (int i = 0; i < DIM; i++) {
        float diff = fabsf(out_dense[i] - out_rank1[i]);
        if (diff > max_diff) max_diff = diff;
    }
    printf("Max diferenca saida: %.6f (numerica)\n", max_diff);

    printf("\n========== APLICACAO LLM ==========\n");
    printf("Engrenagem = peso rank-1 em transformer\n");
    printf("Self-attention: Q·K^T pode ser aproximado rank-1\n");
    printf("FFN: camada pode usar W=u⊗v ao inves de densa\n");
    printf("Economia: %d params vs %d (%.1f%% reducao)\n",
        2 * DIM, DIM * DIM,
        (1 - (float)(2*DIM)/(DIM*DIM)) * 100);

    return 0;
}
