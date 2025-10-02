#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool kiemTraSoNguyenTo(int n) {
    if (n < 2) {
        return false;
    }
    if (n == 2) {
        return true;
    }
    if (n % 2 == 0) {
        return false;
    }
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int demSoNguyenToTrongDoan(int m, int n) {
    int dem = 0;
    for (int i = m; i <= n; i++) {
        if (kiemTraSoNguyenTo(i)) {
            dem++;
        }
    }
    return dem;
}

int main() {
    int count1, count2, count3;

    count1 = demSoNguyenToTrongDoan(1, 10);
    count2 = demSoNguyenToTrongDoan(1, 1000);
    count3 = demSoNguyenToTrongDoan(1001, 100000);

    printf("Ket qua dem so nguyen to:\n");
    printf("Trong doan [1, 10] co: %d so nguyen to.\n", count1);
    printf("Trong doan [1, 1000] co: %d so nguyen to.\n", count2);
    printf("Trong doan [1001, 100000] co: %d so nguyen to.\n", count3);
    printf("--------------------------------\n");

    return 0;
}
