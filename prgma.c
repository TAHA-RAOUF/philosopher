#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define N 100000000

int main() {
    double start, end;
    long long sum;

    sum = 0;
    start = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        sum += i; // هذا خطير!
    }
    end = omp_get_wtime();
    printf("Without protection (wrong result): %lld in %f seconds\n", sum, end - start);

    sum = 0;
    start = omp_get_wtime();
    #pragma omp parallel for
    for (int i = 0; i < N; i++) {
        #pragma omp atomic
        sum += i;
    }
    end = omp_get_wtime();
    printf("With atomic: %lld in %f seconds\n", sum, end - start);

    sum = 0;
    start = omp_get_wtime();
    #pragma omp parallel for reduction(+:sum)
    for (int i = 0; i < N; i++) {
        sum += i;
    }
    end = omp_get_wtime();
    printf("With reduction: %lld in %f seconds\n", sum, end - start);

    return 0;
}