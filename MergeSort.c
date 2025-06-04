#include <stdio.h>

int main() {
    int arr[20], n, i, j, mid, left, right, temp[20];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int size = 1; size < n; size = 2 * size) {
        for (left = 0; left < n - size; left += 2 * size) {
            right = ((left + 2 * size - 1) < (n - 1)) ? (left + 2 * size - 1) : (n - 1);
            mid = (left + right) / 2;
            int i1 = left, i2 = mid + 1, k = left;

            while (i1 <= mid && i2 <= right) {
                if (arr[i1] <= arr[i2]) {
                    temp[k] = arr[i1];
                    i1++;
                } else {
                    temp[k] = arr[i2];
                    i2++;
                }
                k++;
            }

            while (i1 <= mid) {
                temp[k] = arr[i1];
                i1++;
                k++;
            }

            while (i2 <= right) {
                temp[k] = arr[i2];
                i2++;
                k++;
            }

            for (i = left; i <= right; i++) {
                arr[i] = temp[i];
            }
        }
    }

    printf("Sorted array: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
