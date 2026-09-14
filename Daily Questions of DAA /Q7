#include <stdio.h>

int main() {
    int n, i;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int nums[n];

    printf("Enter sorted array elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int left = 0;
    int right = n - 1;

    while (left < right) {
        int mid = left + (right - left) / 2;

        // Make mid even
        if (mid % 2 == 1) {
            mid--;
        }

        // If the pair is correct, single element is on the right
        if (nums[mid] == nums[mid + 1]) {
            left = mid + 2;
        } 
        else {
            // Single element is on the left, including mid
            right = mid;
        }
    }

    printf("Single element: %d\n", nums[left]);

    return 0;
}
