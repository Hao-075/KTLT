#include <stdio.h>
#include <string.h>

int main() {
    float diemHe10;
    float diemHe4;
    char diemChu[3];

    printf("Quy doi diem:\n");
    printf("Nhap vao diem mon hoc (thang diem 10): ");
    scanf("%f", &diemHe10);

    if (diemHe10 < 0.0 || diemHe10 > 10.0) {
        printf("\nLoi: Diem nhap vao khong hop le. Vui long nhap diem trong khoang tu 0.0 den 10.0.\n");
        return 1;
    }

    if (diemHe10 >= 9.0) {
        diemHe4 = 4.0;
        strcpy(diemChu, "A+");
    } else if (diemHe10 >= 8.0) {
        diemHe4 = 3.5;
        strcpy(diemChu, "A");
    } else if (diemHe10 >= 7.0) {
        diemHe4 = 3.0;
        strcpy(diemChu, "B+");
    } else if (diemHe10 >= 6.0) {
        diemHe4 = 2.5;
        strcpy(diemChu, "B");
    } else if (diemHe10 >= 5.0) {
        diemHe4 = 2.0;
        strcpy(diemChu, "C");
    } else if (diemHe10 >= 4.0) {
        diemHe4 = 1.5;
        strcpy(diemChu, "D");
    } else {
        diemHe4 = 1.0;
        strcpy(diemChu, "F");
    }

    printf("Ket qua quy doi:\n");
    printf("Diem he 10: \t%.2f\n", diemHe10);
    printf("Diem he 4: \t%.1f\n", diemHe4);
    printf("Diem chu: \t%s\n", diemChu);

    return 0;
}
