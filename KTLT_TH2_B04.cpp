#include <stdio.h>

double tinhTienLai(double tienGui, double laiSuat, int soThang) {
    double tongTien = tienGui;

    for (int i = 1; i <= soThang; i++) {
        tongTien = tongTien + tongTien * (laiSuat / 100.0);
    }

    return tongTien;
}

int main() {
    double soTienGuiBanDau, laiSuatThang;
    int soThangGui;

    printf("Nhap so tien gui ban dau (VND): ");
    scanf("%lf", &soTienGuiBanDau);

    printf("Nhap lai suat moi thang (%%): ");
    scanf("%lf", &laiSuatThang);

    printf("Nhap tong so thang gui: ");
    scanf("%d", &soThangGui);

    if (soTienGuiBanDau <= 0 || laiSuatThang <= 0 || soThangGui <= 0) {
        printf("\nLoi: So tien, lai suat va so thang phai la so duong.\n");
        return 1;
    }

    double tongTienNhanDuoc = tinhTienLai(soTienGuiBanDau, laiSuatThang, soThangGui);

    printf("\n--------------------------------------------------\n");
    printf("So tien nhan duoc sau %d thang la: %.0f VND\n", soThangGui, tongTienNhanDuoc);
    printf("--------------------------------------------------\n");

    return 0;
}
