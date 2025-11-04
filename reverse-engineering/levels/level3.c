// level3.c - rol + xor encrypted flag (decryption included)
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

/* Encrypted bytes (rol + xor key_base=0x5A) */
uint8_t enc3[] = {
    0x09, 0x91, 0xD5, 0xF2, 0x79, 0x36, 0x80, 0xC8, 0xF1, 0x64, 0x15, 0xCD,
    0x73, 0xF5, 0xE3, 0x39, 0x80, 0x36, 0xD1, 0x5F, 0x2A, 0xF1, 0xED, 0x66,
    0x04, 0x2B, 0x92, 0x3C, 0x25, 0x11, 0x21, 0xFB, 0x96, 0x32, 0xAF
};
static const size_t n_enc3 = 35;
static const uint8_t key_base = 0x5A;

static inline uint8_t ror8(uint8_t v, unsigned int r) {
    r &= 7;
    if (r == 0) return v;
    return (uint8_t)((v >> r) | (v << (8 - r)));
}

int main(void) {
    char *out = malloc(n_enc3 + 1);
    if (!out) return 1;
    for (size_t i = 0; i < n_enc3; ++i) {
        uint8_t rotated = (uint8_t)(enc3[i] ^ (key_base ^ (i & 0xFF))); // undo XOR
        unsigned int shift = (unsigned int)(i % 5);
        uint8_t v = ror8(rotated, shift); // undo rol (rotate right)
        out[i] = (char)(v & 0xFF);
    }
    out[n_enc3] = '\0';
    printf("Decrypted flag: %s\n", out);
    free(out);
    return 0;
}

