#include <stdio.h>

int main() {
    int n;
    long long gt = 1; 
    int i;

    printf("Giai thua kep (n!!)\n");
    printf("Nhap vao mot so nguyen khong am n: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Loi: Khong the tinh giai thua kep cho so am.\n");
        return 1;
    }

    i = n;

    while (i > 1) {
        gt = gt * i;

        i = i - 2;
    }

    printf("\n=> Ket qua: %d!! = %lld\n", n, gt);

    return 0;
}
