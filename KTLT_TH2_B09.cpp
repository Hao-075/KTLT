#include <stdio.h>
#include <string.h>

void daoNguocChuoi(char *str) {
    int trai = 0;
    int phai = strlen(str) - 1;

    while (trai < phai) {
        char temp = str[trai];
        str[trai] = str[phai];
        str[phai] = temp;

        trai++;
        phai--;
    }
}

int main() {
    char chuoi[100];

    printf("Nhap vao mot chuoi bat ky: ");
    fgets(chuoi, sizeof(chuoi), stdin);

    chuoi[strcspn(chuoi, "\n")] = 0;

    printf("Chuoi ban dau : \"%s\"\n", chuoi);

    daoNguocChuoi(chuoi);

    printf("Chuoi dao nguoc: \"%s\"\n", chuoi);

    return 0;
}
