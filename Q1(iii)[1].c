#include <stdio.h>

int main() {
    int scores[2][2][2] = {
        { {65, 92}, {84, 72} },
        { {35, 70}, {59, 67} }
    };

    for (int i = 0; i < 2; i++) {
        printf("Matrix %d:\n", i + 1);
        for (int j = 0; j < 2; j++) {
            for (int k = 0; k < 2; k++) {
                printf("%d ", scores[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    return 0;
}