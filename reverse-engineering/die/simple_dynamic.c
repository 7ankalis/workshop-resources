/* decrypt.c
   Simple XOR decryption that loads the flag into memory.
   Compile: gcc -g -O0 -o decrypt decrypt.c
   Run: ./decrypt
   Set a breakpoint at the line with the comment "breakpoint here" to inspect `flag` in memory.
*/

#include <stdio.h>
#include <stdint.h>
#include <string.h>

int main(void) {
    /* Encrypted bytes = original_bytes XOR 0x5A */
    const uint8_t enc[] = {
        9, 63, 57, 47, 40, 51, 52, 63, 46, 41, 31, 20, 19, 14, 33,
        48, 59, 40, 62, 5, 60, 54, 59, 61, 39
    };
    const size_t n = sizeof(enc) / sizeof(enc[0]);
    const uint8_t key = 0x5A;

    /* static to ensure the buffer is placed in writable global/static memory */
    static char flag[64]; /* big enough to hold the flag + NUL */

    for (size_t i = 0; i < n; ++i) {
        flag[i] = (char)(enc[i] ^ key);
    }
    flag[n] = '\0';

    /* Volatile pointer to avoid unwanted compiler optimizations */
    volatile char *ptr = flag;

    /* === Set a breakpoint on the next line ("breakpoint here") and inspect `flag` (or `ptr`) in memory === */
    (void)ptr; /* breakpoint here */

    /* Uncomment the next line to print the flag (if you want to reveal it automatically) */
    /* printf("Flag: %s\n", (char *)ptr); */

    /* Pause so the program doesn't exit immediately (so you can attach debugger / inspect memory).
       If you prefer not to pause, remove the getchar() line. */
    getchar();

    return 0;
}

