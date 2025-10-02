#include <stdio.h>

int main() {
    double tienGui;
    int soThang;
    float laiSuatThang;
    int i;

    printf("Tinh lai suat kep (Lai nhap goc)\n");

    printf("Nhap so tien gui ban dau (VND): ");
    scanf("%lf", &tienGui);

    printf("Nhap so thang gui: ");
    scanf("%d", &soThang);

    printf("Nhap lai suat mot thang (%%): ");
    scanf("%f", &laiSuatThang);

    for (i = 1; i <= soThang; i++) {
        tienGui = tienGui + tienGui * (laiSuatThang / 100);
    }

    printf("\n------------------------------------------\n");
    printf("=> Sau %d thang, tong so tien ban nhan duoc la: %.0f VND\n", soThang, tienGui);

    return 0;
}
