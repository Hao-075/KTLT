#include <stdio.h>

const int KHO_LOAI_1 = 145;
const int KHO_LOAI_2 = 55;
const int KHO_LOAI_3 = 800;

void solve() {
    int N, M, K;
    scanf("%d %d %d", &N, &M, &K);

    if (N <= KHO_LOAI_1 && M <= KHO_LOAI_2 && K <= KHO_LOAI_3) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        solve();
    }

    return 0;
}
