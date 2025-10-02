#include <stdio.h>

void solve() {
    int giaSanPham, tienDua;
    int tienThoiLai;
    int soTo10, soTo5, soTo1;

    scanf("%d %d", &giaSanPham, &tienDua);

    tienThoiLai = tienDua - giaSanPham;

    soTo10 = tienThoiLai / 10;

    int tienLe = tienThoiLai % 10;

    if (tienLe >= 5) {
        soTo5 = 1;
        soTo1 = tienLe - 5;
    } else {
        soTo5 = 0;
        soTo1 = tienLe;
    }

    printf("%d = %d * 10 + %d * 5 + %d * 1\n", tienThoiLai, soTo10, soTo5, soTo1);
}


int main() {
    int soBoTest;
    scanf("%d", &soBoTest);

    while (soBoTest--) {
        solve();
    }

    return 0;
}
