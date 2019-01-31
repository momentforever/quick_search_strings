#include <stdio.h>
#include <stdlib.h>

/* 1.0
 * Kmp algorithm-based optimization algorithm for text analysis.
 * However, not very perfect
 */
int main(int argc, char** argv) {
    char message[20] = "aacdabaabcdabdbcdabd";
    char key[7] = "abcdabd";
    printf("%d\n", kmp(message, key, 20, 7));
}

int kmp(char *message, char *key, int message_size, int key_size) {
    //    int next[7]={};
    int next[80] = {};
    list(key, key_size, next);
    int x = message_size - key_size, y = 0;
    while (x >= 0 || y != 0) {
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

        int same = 0;
        for(int i=1;i!=key_size;i++){
            if(key[0]==key[i]){
                same=i;
                break;
            }
        }
        next[num+1]=same; 
    
    }
    
    next[0]=key_size-1;
   
    for(int num=0;num!=key_size;num++){
        next[num]=key_size+num-next[num];
    }
    return;
}
