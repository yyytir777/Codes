#include <stdio.h>
#include <string.h>

int main() {
    char hex[] = { 0x54, 0x58, 0x6b, 0x64, 0x58, 0x75, 0x4f, 0x7b, 0x21, 0x5c, 0x7c, 0x75, 0x42, 0x4f, 0x21, 0x63, 0x4f, 0x74, 0x42, 0x75, 0x51, 0x7d, 0x6d };
    int hex_size = sizeof(hex) / sizeof(char);

    for(int i = 1; i < 255; i++) {
        for(int j = 0; j < hex_size; j++) {
            printf("%c", hex[j] ^ i);
        }
    }
    printf("\n");
} 