#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Sach {
    char maSach[20];
    char tenSach[100];
    char tacGia[100];
    int soLuong;
};

void xoa_xuong_dong_sach(char s[]) {
    s[strcspn(s, "\n")] = '\0';
}

void nhapSach(struct Sach *s) {
    char buffer[10];

    printf("Nhap ma sach: ");
    fgets(s->maSach, 20, stdin);
    xoa_xuong_dong_sach(s->maSach);

    printf("Nhap ten sach: ");
    fgets(s->tenSach, 100, stdin);
    xoa_xuong_dong_sach(s->tenSach);

    printf("Nhap tac gia: ");
    fgets(s->tacGia, 100, stdin);
    xoa_xuong_dong_sach(s->tacGia);

    printf("Nhap so luong: ");
    fgets(buffer, 10, stdin);
    sscanf(buffer, "%d", &s->soLuong);
}

void xuatSach(struct Sach s) {
    printf("Ma: %s, Ten: %s, Tac gia: %s, SL: %d\n",
           s.maSach, s.tenSach, s.tacGia, s.soLuong);
}

int main() {
    int n;
    struct Sach thuVien[100];
    char buffer[10];
    
    printf("Nhap so luong dau sach (toi da 100): ");
    fgets(buffer, 10, stdin);
    sscanf(buffer, "%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("--- Nhap dau sach thu %d ---\n", i + 1);
        nhapSach(&thuVien[i]);
    }

    char tenTim[100];
    printf("\nNhap ten sach can tim: ");
    fgets(tenTim, 100, stdin);
    xoa_xuong_dong_sach(tenTim);
    
    int foundTen = 0;
    printf("--- Ket qua tim theo ten ---\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(thuVien[i].tenSach, tenTim) == 0) {
            xuatSach(thuVien[i]);
            foundTen = 1;
        }
    }
    if (!foundTen) {
        printf("Khong Tim Thay.\n");
    }

    char tacGiaTim[100];
    printf("\nNhap ten tac gia can tim: ");
    fgets(tacGiaTim, 100, stdin);
    xoa_xuong_dong_sach(tacGiaTim);
    
    int foundTG = 0;
    printf("--- Ket qua tim theo tac gia ---\n");
    for (int i = 0; i < n; i++) {
        if (strcmp(thuVien[i].tacGia, tacGiaTim) == 0) {
            xuatSach(thuVien[i]);
            foundTG = 1;
        }
    }
    if (!foundTG) {
        printf("Khong co sach cua tac gia nay.\n");
    }

    int tongSoSach = 0;
    for (int i = 0; i < n; i++) {
        tongSoSach += thuVien[i].soLuong;
    }
    printf("\nTong so sach trong thu vien: %d\n", tongSoSach);

    return 0;
}
