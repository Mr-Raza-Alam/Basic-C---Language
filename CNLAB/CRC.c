#include <stdio.h>
#include <string.h>

// Perform modulo-2 division: dividend[] is modified in place
void crc_division(int dividend[], int dividend_len,
                  int divisor[], int divisor_len) {
    int i, j;

    // Slide the window over dividend
    for (i = 0; i <= dividend_len - divisor_len; i++) {
        // Only divide (XOR) when the current bit is 1
        if (dividend[i] == 1) {
            for (j = 0; j < divisor_len; j++) {
                dividend[i + j] ^= divisor[j];  // XOR
            }
        }
    }
}

// Compute CRC and append it to data bits
void compute_crc(int data[], int data_len,
                 int divisor[], int divisor_len,
                 int codeword[]) {
    int i;
    int crc_len = divisor_len - 1;
    int dividend_len = data_len + crc_len;

    // Build dividend: data bits + (divisor_len - 1) zeros
    int dividend[64];  // adjust size as needed
    for (i = 0; i < data_len; i++) {
        dividend[i] = data[i];
    }
    for (i = data_len; i < dividend_len; i++) {
        dividend[i] = 0;
    }

    // Do modulo-2 division
    crc_division(dividend, dividend_len, divisor, divisor_len);

    // Remainder is the last (divisor_len - 1) bits
    // Build codeword = original data + remainder
    for (i = 0; i < data_len; i++) {
        codeword[i] = data[i];
    }
    for (i = 0; i < crc_len; i++) {
        codeword[data_len + i] = dividend[data_len + i];
    }
}

// Check received codeword: return 1 if no error, 0 if error
int check_crc(int codeword[], int codeword_len,
              int divisor[], int divisor_len) {
    int i;
    int temp[64];  // working copy

    for (i = 0; i < codeword_len; i++) {
        temp[i] = codeword[i];
    }

    // Divide codeword by same divisor
    crc_division(temp, codeword_len, divisor, divisor_len);

    // Check remainder (last divisor_len - 1 bits) are all zero
    for (i = codeword_len - (divisor_len - 1); i < codeword_len; i++) {
        if (temp[i] != 0) {
            return 0;  // error
        }
    }
    return 1;  // no error
}

int main() {
    // Example: data bits and divisor (generator polynomial)
    // Data: 1 0 1 1
    int data[] = {1,0,1,0,1,0,1,1, 1, 1,1,1,0,1};
    int data_len = 14;

    // Example divisor (generator): x^3 + x + 1 -> 1 0 1 1
    int divisor[] = {1,0,1, 1,0};
    int divisor_len = 5;

    int crc_len = divisor_len - 1;
    int codeword[64];
    int codeword_len = data_len + crc_len;

    int i;

    // Sender side: compute CRC and build codeword
    compute_crc(data, data_len, divisor, divisor_len, codeword);

    printf("Codeword (data + CRC): ");
    for (i = 0; i < codeword_len; i++) {
        printf("%d", codeword[i]);
    }
    printf("\n");

    // Simulate transmission: you can flip a bit to test error detection
    // Example: introduce an error
    // codeword[2] ^= 1;

    // Receiver side: check CRC
    if (check_crc(codeword, codeword_len, divisor, divisor_len)) {
        printf("No error detected (remainder = 0).\n");
    } else {
        printf("Error detected (remainder != 0).\n");
    }

    return 0;
}

