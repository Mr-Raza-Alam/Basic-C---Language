#include <stdio.h>
#include <string.h>

int main() {
    char payload[32], stream[32]; // output buffer doubled
    printf("Enter the bit stream here: ");
    fgets(payload, sizeof(payload), stdin);
    payload[strcspn(payload, "\n")] = 0; // Remove newline character
    printf("The payload: %s\n", payload);
    printf("The length of payload: %d\n", (int)strlen(payload));
    
    int count = 0, k = 0;
    for (int i = 0; i < strlen(payload); i++) {
        stream[k++] = payload[i];
        if (payload[i] == '1') {
            count++;
            if (count == 5) {
                stream[k++] = '0'; // bit stuffing
                count = 0;
            }
        } else {
            count = 0;
        }
    }
    stream[k] = '\0'; // Null terminate the output
    printf("After bit stuffing\nNew bit stream: %s\n", stream);
    return 0;
}

