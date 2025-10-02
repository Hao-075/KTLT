#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int isStrongPassword(char *pw) {
    int doDai = strlen(pw);

    if (doDai < 8) {
        return 0;
    }

    bool coChuHoa = false;
    bool coChuThuong = false;
    bool coChuSo = false;

    for (int i = 0; i < doDai; i++) {
        if (isupper(pw[i])) {
            coChuHoa = true;
        } else if (islower(pw[i])) {
            coChuThuong = true;
        } else if (isdigit(pw[i])) {
            coChuSo = true;
        }
    }

    if (coChuHoa && coChuThuong && coChuSo) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    char password[100];

    printf("Nhap mat khau de kiem tra: ");
    fgets(password, sizeof(password), stdin);
    
    password[strcspn(password, "\n")] = 0;


    if (isStrongPassword(password)) {
        printf("=> Day la mot mat khau MANH! ??\n");
    } else {
        printf("=> Day la mot mat khau YEU! ??\n");
        printf("   (Goi y: Mat khau can dai >= 8 ky tu, co it nhat 1 chu hoa, 1 chu thuong, 1 chu so.)\n");
    }

    return 0;
}
