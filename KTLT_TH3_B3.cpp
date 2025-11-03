#include <stdio.h>
#include <limits.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[50];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }

        int count = 0;
        int max_so_far = INT_MIN;

        for (int i = 0; i < n; ++i) {
            if (arr[i] >= max_so_far) {
                count++;
                max_so_far = arr[i];
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
