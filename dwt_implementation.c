#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform Discrete Wavelet Transform
void dwt(double *input, double *output, int length) {
    // Assuming input length is even
    for (int i = 0; i < length / 2; i++) {
        output[i] = (input[2 * i] + input[2 * i + 1]) / sqrt(2); // Approximation
        output[length / 2 + i] = (input[2 * i] - input[2 * i + 1]) / sqrt(2); // Detail
    }
}

// Example usage
int main() {
    double input[] = {1, 2, 3, 4, 5, 6, 7, 8}; // Sample input data
    int length = sizeof(input) / sizeof(input[0]);
    double *output = malloc(length * sizeof(double));

    dwt(input, output, length);

    printf("DWT Output:\n");
    for (int i = 0; i < length; i++) {
        printf("%f ", output[i]);
    }
    printf("\n");

    free(output);
    return 0;
}