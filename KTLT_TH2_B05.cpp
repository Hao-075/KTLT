#include <stdio.h>

long long tinhGiaiThuaKep(int n) {
    long long giaiThua = 1; 
    
    int i = n;
    
    while (i > 1) {
        giaiThua = giaiThua * i;
        i = i - 2;
    }
    
    return giaiThua;
}

int main() {
    int n;

    printf("Nhap vao so nguyen duong n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Loi: n phai la mot so nguyen duong.\n");
        return 1;
    }

    long long ketQua = tinhGiaiThuaKep(n);

    printf("Ket qua: %d!! = %lld\n", n, ketQua);

    return 0;
}
