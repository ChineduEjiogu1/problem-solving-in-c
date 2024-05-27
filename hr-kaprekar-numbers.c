#include <stdio.h>
#include <math.h>

void kaprekarNumbers(int p, int q) {
    int found = 0;
    for (int i = p; i <= q; i++) {
        long long square = (long long)i * i;
        int numDigits = (int)log10(i) + 1;
        long long divisor = pow(10, numDigits);

        long long left = square / divisor;
        long long right = square % divisor;

        if (left + right == i) {
            printf("%d ", i);
            found = 1;
        }
    }
    if (!found) {
        printf("INVALID RANGE");
    }
    printf("\n");
}

int main() {
    int p = 1;
    int q = 100;

    kaprekarNumbers(p, q);

    return 0;
}
