#include <stdio.h>

float chuyenDiemThang4(float diemHe10) {
    if (diemHe10 >= 9.0) {
        return 4.0;
    } else if (diemHe10 >= 8.0) {
        return 3.5;
    } else if (diemHe10 >= 7.0) {
        return 3.0;
    } else if (diemHe10 >= 6.0) {
        return 2.5;
    } else if (diemHe10 >= 5.0) {
        return 2.0;
    } else if (diemHe10 >= 4.0) {
        return 1.5;
    } else {
        return 1.0;
    }
}

const char* chuyenDiemChu(float diemHe10) {
    if (diemHe10 >= 9.0) {
        return "A+";
    } else if (diemHe10 >= 8.0) {
        return "A";
    } else if (diemHe10 >= 7.0) {
        return "B+";
    } else if (diemHe10 >= 6.0) {
        return "B";
    } else if (diemHe10 >= 5.0) {
        return "C";
    } else if (diemHe10 >= 4.0) {
        return "D";
    } else {
        return "F";
    }
}

int main() {
    float diemHe10;

    printf("Nhap vao diem he 10: ");
    scanf("%f", &diemHe10);

    if (diemHe10 < 0 || diemHe10 > 10) {
        printf("Loi: Diem so phai nam trong khoang tu 0 den 10.\n");
        return 1;
    }

    float diemHe4 = chuyenDiemThang4(diemHe10);
    const char* diemChu = chuyenDiemChu(diemHe10);

    printf("Ket qua quy doi:\n");
    printf("Diem he 10:   %.2f\n", diemHe10);
    printf("Diem he 4:    %.1f\n", diemHe4);
    printf("Diem chu:     %s\n", diemChu);
    printf("-----------------------\n");

    return 0;
}
