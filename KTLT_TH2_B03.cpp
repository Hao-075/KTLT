#include <stdio.h>

#define GIA_BAC_1 1418
#define GIA_BAC_2 1622
#define GIA_BAC_3 2044
#define GIA_BAC_4 2210
#define GIA_BAC_5 2361
#define GIA_BAC_6 2420

#define NGUONG_BAC_1 100
#define NGUONG_BAC_2 150
#define NGUONG_BAC_3 200
#define NGUONG_BAC_4 300
#define NGUONG_BAC_5 400

long tinhTienDien(int soKwhTong) {
    long tongTien = 0;
    int soKwh = soKwhTong;

    if (soKwh > NGUONG_BAC_5) {
        tongTien += (soKwh - NGUONG_BAC_5) * GIA_BAC_6;
        soKwh = NGUONG_BAC_5;
    }

    if (soKwh > NGUONG_BAC_4) {
        tongTien += (soKwh - NGUONG_BAC_4) * GIA_BAC_5;
        soKwh = NGUONG_BAC_4;
    }

    if (soKwh > NGUONG_BAC_3) {
        tongTien += (soKwh - NGUONG_BAC_3) * GIA_BAC_4;
        soKwh = NGUONG_BAC_3;
    }

    if (soKwh > NGUONG_BAC_2) {
        tongTien += (soKwh - NGUONG_BAC_2) * GIA_BAC_3;
        soKwh = NGUONG_BAC_2;
    }

    if (soKwh > NGUONG_BAC_1) {
        tongTien += (soKwh - NGUONG_BAC_1) * GIA_BAC_2;
        soKwh = NGUONG_BAC_1;
    }

    tongTien += soKwh * GIA_BAC_1;

    return tongTien;
}

int main() {
    int chiSoCu, chiSoMoi;

    printf("Nhap chi so dien thang truoc: ");
    scanf("%d", &chiSoCu);
    printf("Nhap chi so dien thang nay: ");
    scanf("%d", &chiSoMoi);

    if (chiSoMoi < chiSoCu) {
        printf("\nLoi: Chi so moi phai lon hon hoac bang chi so cu.\n");
        return 1;
    }

    int soKwhTieuThu = chiSoMoi - chiSoCu;
    long tienDien = tinhTienDien(soKwhTieuThu);

    printf("Hoa don tien dien:\n");
    printf("So kWh tieu thu: %d kWh\n", soKwhTieuThu);
    printf("Tong so tien phai tra: %ld VND\n", tienDien);
    printf("-------------------------\n");

    return 0;
}
