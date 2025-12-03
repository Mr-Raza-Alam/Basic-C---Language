#include <stdio.h>
#include <math.h>

// Count parity bits needed for m data bits
int countParityBits(int m) {
    int r = 0;
    while ((1 << r) < (m + r + 1)) {
        r++;
    }
    return r;
}

// Print array
void printBits(int arr[], int n, const char *msg) {
    printf("%s: ", msg);
    for (int i = 1; i <= n; i++) printf("%d", arr[i]);
    printf("\n");
}

int main() {

    int m;
    printf("Enter number of data bits: ");
    scanf("%d", &m);

    int data[m+1];
    printf("Enter %d data bits (0/1): ", m);
    for (int i = 1; i <= m; i++) scanf("%d", &data[i]);

    // Step 1: Calculate required parity bits
    int r = countParityBits(m);
    int n = m + r;     // Total code length

    printf("\nNumber of parity bits required = %d\n", r);
    printf("Total Hamming code length = %d\n", n);

    int code[n+1];

    // Step 2: Insert data bits at non-parity positions
    int j = 1;
    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) == 0)
            code[i] = 0;  // parity bit placeholder
        else
            code[i] = data[j++];
    }

    printBits(code, n, "\nAfter placing data bits (parity=0)");

    // Step 3: Calculate parity bits (even parity)
    for (int p = 0; p < r; p++) {
        int pos = 1 << p;     // parity bit position: 1,2,4,8,...
        int parity = 0;

        printf("\nParity bit P%d (position %d) checks positions: ", pos, pos);

        for (int i = 1; i <= n; i++) {
            if (i & pos) {
                printf("%d ", i);
                parity ^= code[i];
            }
        }
        
        code[pos] = parity;
        printf("\nCalculated parity for P%d = %d\n", pos, code[pos]);
    }

    printBits(code, n, "\nFinal Hamming code");

    // Step 4: Introduce 1-bit error
    int rec[n+1];
    for (int i = 1; i <= n; i++) rec[i] = code[i];

    int errPos;
    printf("\nEnter error position to flip (0 for no error): ");
    scanf("%d", &errPos);

    if (errPos != 0 && errPos <= n) {
        rec[errPos] ^= 1;
        printf("Error introduced at position %d\n", errPos);
    }

    printBits(rec, n, "Received code");

    // Step 5: Syndrome calculation
    int syndrome = 0;

    printf("\n--- Syndrome Calculation ---\n");
    
    for (int p = 0; p < r; p++) {
        int pos = 1 << p;
        int parity = 0;

        printf("Check P%d: positions ", pos);
        
        for (int i = 1; i <= n; i++) {
            if (i & pos) {
                printf("%d ", i);
                parity ^= rec[i];
            }
        }

        printf(" => parity = %d\n", parity);

        if (parity)
            syndrome += pos;
    }

    printf("\nSyndrome = %d\n", syndrome);

    // Step 6: Correct the error if any
    if (syndrome != 0) {
        printf("Error detected at position %d. Correcting...\n", syndrome);
        rec[syndrome] ^= 1;
    } else {
        printf("No error detected.\n");
    }

    printBits(rec, n, "\nCorrected code");

    return 0;
}
