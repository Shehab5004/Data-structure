#include <stdio.h>
#include <string.h>

int minimum_scarecrows_needed(int n, char field[]) {
    int count = 0;
    int i = 0;

    while (i < n) {
        if (field[i] == '.') {
            count++;
            i += 3;
        } else {
            i++;
        }
    }

    return count;
}

int main() {
    int t;
    scanf("%d", &t);
    for (int case_number = 1; case_number <= t; case_number++) {
        int n;
        scanf("%d", &n);

        char field[n + 1];
        scanf("%s", field);
        int result = minimum_scarecrows_needed(n, field);
        printf("Case %d: %d\n", case_number, result);
    }

    return 0;
}

