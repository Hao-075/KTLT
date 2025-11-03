#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[100];
        int freq[30001];
        
        memset(freq, 0, sizeof(freq)); 

        int max_freq = 0;
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
            freq[arr[i]]++;
            if (freq[arr[i]] > max_freq) {
                max_freq = freq[arr[i]];
            }
        }

        for (int i = 0; i < n; ++i) {
            if (freq[arr[i]] == max_freq) {
                printf("%d ", arr[i]);
                freq[arr[i]] = 0;
            }
        }
        printf("\n");
    }
    return 0;
}
