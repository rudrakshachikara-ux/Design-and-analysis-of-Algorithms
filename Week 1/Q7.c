#include <stdio.h>

void reverse(int arr[], int start, int end) {
    int temp;

    while (start < end) {
        temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;

        start++;
        end--;
    }
}

int main() {
    int arr[100];
    int n, k, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter K: ");
    scanf("%d", &k);

    if (n > 0) {
        k = k % n;

        /* Reverse entire array */
        reverse(arr, 0, n - 1);

        /* Reverse first K elements */
        reverse(arr, 0, k - 1);

        /* Reverse remaining elements */
        reverse(arr, k, n - 1);
    }

    printf("\nArray after right rotation:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");

    return 0;
}
