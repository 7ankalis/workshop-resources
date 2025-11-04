// level1.c - simple compare
#include <stdio.h>
#include <string.h>

int check_flag(const char *input) {
    const char flag[] = "SecurinetsENIT{l3alam_noumrou_wehed}";
    size_t i;
    for (i = 0; i < sizeof(flag)-1; ++i) {
        if (input[i] != flag[i]) {
            return (int)i+1;
        }
    }
    return 0;
}

int main(void) {
    char buf[256];
    printf("Enter flag: ");
    if (!fgets(buf, sizeof(buf), stdin)) return 1;
    buf[strcspn(buf, "\n")] = '\0';
    int r = check_flag(buf);
    if (r == 0) {
        puts("Correct! 🎉");
    } else {
        printf("Wrong at byte %d\n", r);
    }
    return 0;
}

