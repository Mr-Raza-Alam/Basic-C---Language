#include <stdio.h>
#include <string.h>

int main() {
    char payload[32], flag[8], stream[32]; // Output buffer
    printf("Enter the byte stream here: ");
    fgets(payload, sizeof(payload), stdin);
    printf("Enter the flag stream: ");
    fgets(flag, sizeof(flag), stdin);

    // Remove newline characters
    payload[strcspn(payload, "\n")] = 0;
    flag[strcspn(flag, "\n")] = 0;

    printf("The payload: %s\n", payload);
    printf("The flag: %s\n", flag);

    int plen = strlen(payload);
    int flen = strlen(flag);
    int k = 0; // index for stream

    for (int i = 0; i < plen; i++) {
        int match = 1;
        if (i + flen <= plen) {
            // Check if flag matches at this position
            for (int j = 0; j < flen; j++) {
                // Copy the payload bit to stream
                stream[k++] = payload[i+j];
                if (payload[i + j] != flag[j]) {
                    match = 0;
                    break;
                }
            }
        } else {
            match = 0; 
        }


        if (match) {
            // Insert stuffing byte (8 zeros) after flag
            for (int z = 0; z < 8; z++) {
                stream[k++] = '0';
            }
            i += flen - 1; // skip the flag bits already processed
        }
    }

    stream[k] = '\0'; // null-terminate output string

    printf("After byte stuffing, the stream: %s\n", stream);

    return 0;
}

