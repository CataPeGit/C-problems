#include <stdio.h>
#include <stdlib.h>

int main() {

    int ms = 24;
    short c1, c2, c3, c4;
    for(c1 = 9; c1 >= 3; c1--) {
        for(c2 = 9; c2 >= 3; c2--) {
            for(c3 = 9; c3 >= 3; c3--) {
                c4 = ms - c1 - c2 - c3;
                if(c4 < c3 && c4 >= 0) {
                    printf("%d%d%d%d", c1, c2, c3, c4);
                    printf("\n");
                }
            }
        }
    }

}