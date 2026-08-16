#include <stdio.h>

int main() {
    int n, i, j;
    int arr[100], visited[100] = {0};

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\nFrequency of elements:\n");

    for (i = 0; i < n; i++) {
        int count = 1;

        if (visited[i])
            continue;

        for (j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }

        printf("%d -> %d times\n", arr[i], count);
    }

    return 0;
}
