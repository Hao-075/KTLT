#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int main() {
    int n;
    int i;
    bool laSNT;

    printf("Kiem tra so nguyen to:\n");
    printf("Nhap vao mot so nguyen n: ");
    scanf("%d", &n);

    if (n < 2) {
        laSNT = false;
    } else {
        laSNT = true;

        for (i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                laSNT = false;
                break;
            }
        }
    }

    printf("\n=> Ket luan: ");
    if (laSNT) {
        printf("%d LA so nguyen to.\n", n);
    } else {
        printf("%d KHONG PHAI la so nguyen to.\n", n);
    }

    return 0;
}
