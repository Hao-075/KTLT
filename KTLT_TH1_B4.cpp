#include <stdio.h>
#include <string.h>

int main() {
    char hoTen[100];
    float diemToan, diemVan, diemTin;
    float dtb;

    printf("Xep loai hoc tap:\n");

    printf("Nhap ho va ten: ");
    fgets(hoTen, sizeof(hoTen), stdin);
    hoTen[strcspn(hoTen, "\n")] = 0;

    printf("Nhap diem toan: ");
    scanf("%f", &diemToan);
    printf("Nhap diem van: ");
    scanf("%f", &diemVan);
    printf("Nhap diem tin hoc: ");
    scanf("%f", &diemTin);


    dtb = (diemToan + diemVan + diemTin) / 3.0;

    printf("\n--- KET QUA HOC TAP ---\n");
    printf("Ho va ten: \t%s\n", hoTen);
    printf("Diem trung binh: \t%.2f\n", dtb);
    printf("Xep loai: \t");

    if (dtb >= 8) {
        printf("Gioi\n");
    } else if (dtb >= 7) {
        printf("Kha\n");
    } else if (dtb >= 5) {
        printf("Trung binh\n");
    } else {
        printf("Yeu\n");
    }

    return 0;
}
