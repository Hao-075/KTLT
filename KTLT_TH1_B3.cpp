#include <stdio.h>

int main() {
    int thang, nam;
    int soNgay = 0;

    printf("Tim so ngay cua thang:\n");
    printf("Nhap vao thang (1-12): ");
    scanf("%d", &thang);
    printf("Nhap vao nam: ");
    scanf("%d", &nam);

    switch (thang) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            soNgay = 31;
            break;

        case 4:
        case 6:
        case 9:
        case 11:
            soNgay = 30;
            break;

        case 2:

            if ((nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0)) {
                soNgay = 29;
            } else {
                soNgay = 28;
            }
            break;

        default:
            soNgay = 0;
            break;
    }

    if (soNgay == 0) {
        printf("\nLoi: Thang ban nhap (%d) khong hop le!\n", thang);
    } else {
        printf("\n=> Thang %d nam %d co %d ngay.\n", thang, nam, soNgay);
    }

    return 0;
}
