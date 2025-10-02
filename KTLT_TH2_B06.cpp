#include <stdio.h>

int tinhSoThangGui(double tienBanDau, double tienCanCo, double laiSuatThang) {
    int soThang = 0;
    double tienHienTai = tienBanDau;

    while (tienHienTai < tienCanCo) {
        double tienLai = tienHienTai * (laiSuatThang / 100.0);
        
        tienHienTai += tienLai;
        
        soThang++;
    }

    return soThang;
}

int main() {
    double soTienBanDau, soTienCanCo, laiSuat;

    printf("Nhap so tien ban dau: ");
    scanf("%lf", &soTienBanDau);

    printf("Nhap so tien can co (muc tieu): ");
    scanf("%lf", &soTienCanCo);

    printf("Nhap lai suat hang thang (%%): ");
    scanf("%lf", &laiSuat);

    if (soTienBanDau <= 0 || laiSuat <= 0) {
        printf("\nLoi: So tien ban dau va lai suat phai la so duong.\n");
        return 1;
    }
    if (soTienCanCo <= soTienBanDau) {
        printf("\nLoi: So tien can co phai lon hon so tien ban dau.\n");
        return 1;
    }

    int soThangItNhat = tinhSoThangGui(soTienBanDau, soTienCanCo, laiSuat);

    printf("\n------------------------------------------------------\n");
    printf("=> Can gui it nhat %d thang de dat duoc muc tieu.\n", soThangItNhat);
    printf("------------------------------------------------------\n");

    return 0;
}
