#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int laSoNguyenTo(int n) {
    if (n < 2) return 0;
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int laSoChinhPhuong(int n) {
    if (n < 0) return 0;
    int root = round(sqrt(n));
    return (root * root == n);
}

int laMangDoiXung(int arr[], int n) {
    for (int i = 0; i < n / 2; ++i) {
        if (arr[i] != arr[n - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int laMangSapXep(int arr[], int n) {
    int tang = 1;
    int giam = 1;
    for (int i = 0; i < n - 1; ++i) {
        if (arr[i] > arr[i + 1]) tang = 0;
        if (arr[i] < arr[i + 1]) giam = 0;
    }
    return tang || giam;
}

int soSanhSoNguyen(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    int arr[100];

    printf("Nhap n (0 < n < 100): ");
    scanf("%d", &n);

    printf("Nhap %d so nguyen duong: ", n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    printf("Mang vua nhap: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    printf("Cac so nguyen to: ");
    for (int i = 0; i < n; ++i) {
        if (laSoNguyenTo(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    printf("Cac so chinh phuong: ");
    for (int i = 0; i < n; ++i) {
        if (laSoChinhPhuong(arr[i])) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");

    if (laMangDoiXung(arr, n)) {
        printf("Mang doi xung.\n");
    } else {
        printf("Mang khong doi xung.\n");
    }

    if (laMangSapXep(arr, n)) {
        printf("Mang tang dan hoac giam dan.\n");
    } else {
        printf("Mang khong tang dan cung khong giam dan.\n");
    }

    int k;
    printf("Nhap so nguyen k: ");
    scanf("%d", &k);
    int timThay = 0;
    printf("Vi tri xuat hien cua %d: ", k);
    for (int i = 0; i < n; ++i) {
        if (arr[i] == k) {
            printf("%d ", i);
            timThay = 1;
        }
    }
    if (!timThay) {
        printf("Khong tim thay k trong mang.");
    }
    printf("\n");

    qsort(arr, n, sizeof(int), soSanhSoNguyen);
    printf("Mang sau khi sap xep tang dan: ");
    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

