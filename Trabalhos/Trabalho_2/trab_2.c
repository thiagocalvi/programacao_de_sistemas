#include <stdio.h>
#include <math.h>

#define EPSILON 1e-6
#define MAX_ITERATIONS 100

float newtonSqrt(float A) {
    if (A == 0) return 0;
    
    float x = A / 2.0f;  // Estimativa inicial
    float h;
    
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        h = (x + A / x) / 2.0f - x;
        
        if (fabsf(h) < EPSILON) {
            break;
        }
        
        x += h;
    }
    
    return x;
}

int main() {
    printf("   A   | Newton-Raphson |   sqrt()   | Diferença\n");
    printf("-------|----------------|------------|----------\n");

    for (float A = 50.0f; A <= 70.0f; A += 1.0f) {
        float newtonResult = newtonSqrt(A);
        float sqrtResult = sqrtf(A);
        float diff = fabsf(newtonResult - sqrtResult);

        printf("%6.2f |   %12.8f | %10.8f | %10.8f\n", A, newtonResult, sqrtResult, diff);
    }

    return 0;
}