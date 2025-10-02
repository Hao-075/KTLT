#include <stdio.h>

int main() {
    double tienGui;
    double tienNhan;
    float laiSuat;
    int thang = 0;

    printf("So thang tiet kiem toi thieu:\n");

    printf("Nhap so tien gui ban dau (VND): ");
    scanf("%lf", &tienGui);

    printf("Nhap so tien muc tieu can dat duoc (VND): ");
    scanf("%lf", &tienNhan);

    printf("Nhap lai suat mot thang (%%): ");
    scanf("%f", &laiSuat);

    if (laiSuat <= 0 && tienGui < tienNhan) {
        printf("\nLoi: Voi lai suat khong duong, ban se khong bao gio dat duoc muc tieu.\n");
        return 1;
    }

    while (tienGui < tienNhan) {
        thang++;

        tienGui = tienGui + tienGui * (laiSuat / 100.0);
    }

    printf("\n----------------------------------------------------------------\n");
    printf("=> De dat duoc so tien %.0f VND, ban can gui it nhat: %d thang.\n", tienNhan, thang);
    printf("   So tien thuc te ban nhan duoc sau thoi gian do la: %.0f VND.\n", tienGui);

    return 0;
}
