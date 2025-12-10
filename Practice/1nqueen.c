#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void nqueens(int n) {
    int *pos = calloc(n, sizeof(int)), count = 0;
    void solve(int c) {
        if (c == n) {
            printf("[");
            for (int i = 0; i < n; i++)
                printf("%d%s", pos[i], i < n - 1 ? ", " : "");
            printf("]\n");
            count++;
            return;
        }
        for (int r = 0; r < n; r++) {
            int ok = 1;
            for (int i = 0; i < c; i++)
                if (pos[i] == r || abs(pos[i] - r) == abs(i - c))
                    ok = 0;
            if (ok) { pos[c] = r; solve(c + 1); }
        }
    }
    solve(0);
    printf("Total: %d\n", count);
    free(pos);
}

int main() { nqueens(7); }
