#include <stdio.h>
#include <math.h>

int main() {
    double tienNhan;
    double tienGui;
    int    soThang;
    float  laiSuatThang;

    printf("Tinh so tien can gui ban dau:\n");

    printf("Nhap so tien muc tieu ban muon co (VND): ");
    scanf("%lf", &tienNhan);

    printf("Nhap tong so thang se gui: ");
    scanf("%d", &soThang);

    printf("Nhap lai suat mot thang (%%): ");
    scanf("%f", &laiSuatThang);

    if (tienNhan <= 0 || soThang <= 0 || laiSuatThang <= 0) {
        printf("\nLoi: So tien, so thang va lai suat phai la so duong.\n");
        return 1;
    }

    double mauSo = pow((1 + laiSuatThang / 100.0), soThang);

    tienGui = tienNhan / mauSo;

    printf("\n--------------------------------------------------------------\n");
    printf("=> De nhan duoc %.0f VND sau %d thang voi lai suat %.2f%%/thang,\n", tienNhan, soThang, laiSuatThang);
    printf("   ban can gui so tien ban dau it nhat la: %.0f VND.\n", tienGui);

    return 0;
}
