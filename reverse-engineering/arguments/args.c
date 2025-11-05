#include <stdio.h>

// Function with 2 arguments (will likely use RDI and RSI)
int func_two_args(int a, int b) {
    int result = a + b;
    printf("Two args: %d + %d = %d\n", a, b, result);
    return result;
}

// Function with 7 arguments (will use RDI to R9, and the 7th arg will be on the stack)
int func_seven_args(long a, long b, long c, long d, long e, long f, long g) {
    long result = a + b + c + d + e + f + g;
    printf("Seven args: Sum = %ld\n", result);
    return (int)result;
}

int main() {
    // Test case 1: 2 arguments
    int result_2 = func_two_args(10, 20);
    
    // Test case 2: 7 arguments
    // Use 'long' type to match 64-bit register size for clarity in assembly
    int result_7 = func_seven_args(1, 2, 3, 4, 5, 6, 7);

    // Return the sum of the results (for compiler optimization prevention)
    return result_2 + result_7;
}
