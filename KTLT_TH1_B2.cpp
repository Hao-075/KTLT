#include <stdio.h>
#include <string.h>

int main() {
    char tenKhachHang[100];
    int chiSoCu, chiSoMoi;
    int soLuongTieuThu;
    double thanhTien;

    printf("Tinh tien dien:\n");

    printf("Nhap ten khach hang: ");
    fgets(tenKhachHang, sizeof(tenKhachHang), stdin);
    tenKhachHang[strcspn(tenKhachHang, "\n")] = 0;

    printf("Nhap chi so dien cu: ");
    scanf("%d", &chiSoCu);
    printf("Nhap chi so dien moi: ");
    scanf("%d", &chiSoMoi);

    if (chiSoMoi < chiSoCu) {
        printf("\nLoi: Chi so moi phai lon hon hoac bang chi so cu!\n");
        return 1;
    }

    soLuongTieuThu = chiSoMoi - chiSoCu;

    if (soLuongTieuThu <= 100) {
        thanhTien = (double)soLuongTieuThu * 1418;
    } else if (soLuongTieuThu <= 150) {
        thanhTien = 100 * 1418 + (double)(soLuongTieuThu - 100) * 1622;
    } else if (soLuongTieuThu <= 200) {
        thanhTien = 100 * 1418 + 50 * 1622 + (double)(soLuongTieuThu - 150) * 2044;
    } else if (soLuongTieuThu <= 300) {
        thanhTien = 100 * 1418 + 50 * 1622 + 50 * 2044 + (double)(soLuongTieuThu - 200) * 2210;
    } else if (soLuongTieuThu <= 400) {
        thanhTien = 100 * 1418 + 50 * 1622 + 50 * 2044 + 100 * 2210 + (double)(soLuongTieuThu - 300) * 2361;
    } else {
        thanhTien = 100 * 1418 + 50 * 1622 + 50 * 2044 + 100 * 2210 + 100 * 2361 + (double)(soLuongTieuThu - 400) * 2420;
    }

    printf("Hoa don tien dien:\n");
    printf("Khach hang: \t\t%s\n", tenKhachHang);
    printf("So kW tieu thu: \t%d kWh\n", soLuongTieuThu);
    printf("Thanh tien: \t\t%.0f VND\n", thanhTien);

    return 0;
}
