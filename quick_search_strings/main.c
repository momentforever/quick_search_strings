#include <stdio.h>
#include <stdlib.h>

/*
 *  optimal kmp.
 *  change bad chararters list number to -1
 */
int main(int argc, char** argv) {
    char message[20] = "abcdabaaaaaaaabcdabd";
    char key[7] = "aaaaaaa";
    printf("%d\n", kmp(message, key, 20, 7));
}

int kmp(char *message, char *key, int message_size, int key_size) {
    int next[80] = {};
    list(key, key_size, next);
    int x = 0, y = 0;
    while (x <= message_size - key_size || y != 0) {
        if (y == key_size)
            return x - y;
        if (message[x] == key[y]) {
            x++;
            y++;
        } else {
            x = x - next[y];
            y = 0;
        }
    }
    return -1;
}

void list(char *key, int key_size, int *next) {
    for (int num = 0; num != key_size; num++) {
        for (int x = 0, y = 1; y <= num - 1; y++) {
            if (next[num ] != 0 && key[y] != key[x]) {
                x = 0;
                y = y - next[num] + 1;
                next[num ] = 0;
            }
            if (key[y] == key[x]) {
                x++;
                next[num]++;
            }
        }
        if (key[num] == key[0])
            next[num] = -1;
    }
    return;
}
