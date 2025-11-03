#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SV 100
#define MAX_LEN 50


struct SinhVien {
    char hoTen[MAX_LEN];
    char ngaySinh[12];
    char gioiTinh[10];
    double diemTB;
};

void xoa_xuong_dong(char s[]) {
    s[strcspn(s, "\n")] = '\0';
}

void nhapThongTin(struct SinhVien *sv) {
    char buffer[10];

    printf("Nhap ho ten: ");
    fgets(sv->hoTen, MAX_LEN, stdin);
    xoa_xuong_dong(sv->hoTen);

    printf("Nhap ngay sinh (dd/mm/yyyy): ");
    fgets(sv->ngaySinh, 12, stdin);
    xoa_xuong_dong(sv->ngaySinh);

    printf("Nhap gioi tinh: ");
    fgets(sv->gioiTinh, 10, stdin);
    xoa_xuong_dong(sv->gioiTinh);

    printf("Nhap diem trung binh: ");
    fgets(buffer, 10, stdin);
    sscanf(buffer, "%lf", &sv->diemTB);
}

void inSinhVien(struct SinhVien sv) {
    printf("| %-25s | %-15s | %-10s | %8.2f |\n", 
           sv.hoTen, sv.ngaySinh, sv.gioiTinh, sv.diemTB);
}

void themSinhVien(struct SinhVien ds[], int *soLuong);
void hienThiDanhSach(struct SinhVien ds[], int soLuong);
int timViTriTheoTen(struct SinhVien ds[], int soLuong, char ten[]);
void xoaSinhVien(struct SinhVien ds[], int *soLuong);
void suaThongTin(struct SinhVien ds[], int soLuong);
void timKiem(struct SinhVien ds[], int soLuong);
void sapXep(struct SinhVien ds[], int soLuong);

int compareByScore(const void *a, const void *b);
int compareByName(const void *a, const void *b);


int main() {
    struct SinhVien danhSachSV[MAX_SV];
    int soLuongHienTai = 0;
    int luaChon;
    char buffer[10];

    do {
        printf("\n--- CHUONG TRINH QUAN LY SINH VIEN (C) ---\n");
        printf("1. Them sinh vien\n");
        printf("2. Hien thi danh sach\n");
        printf("3. Xoa sinh vien\n");
        printf("4. Sua thong tin sinh vien\n");
        printf("5. Tim kiem sinh vien\n");
        printf("6. Sap xep danh sach\n");
        printf("0. Thoat\n");
        printf("-------------------------------------------\n");
        printf("Nhap lua chon cua ban: ");
        
        fgets(buffer, 10, stdin);
        sscanf(buffer, "%d", &luaChon);

        switch (luaChon) {
            case 1:
                themSinhVien(danhSachSV, &soLuongHienTai); 
                break;
            case 2:
                hienThiDanhSach(danhSachSV, soLuongHienTai);
                break;
            case 3:
                xoaSinhVien(danhSachSV, &soLuongHienTai);
                break;
            case 4:
                suaThongTin(danhSachSV, soLuongHienTai);
                break;
            case 5:
                timKiem(danhSachSV, soLuongHienTai);
                break;
            case 6:
                sapXep(danhSachSV, soLuongHienTai);
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    } while (luaChon != 0);

    return 0;
}


// 1. Thêm sinh viên
void themSinhVien(struct SinhVien ds[], int *soLuong) {
    if (*soLuong >= MAX_SV) {
        printf("Danh sach da day, khong the them!\n");
        return;
    }

    printf("--- Nhap thong tin sinh vien moi ---\n");
    nhapThongTin(&ds[*soLuong]);
    (*soLuong)++;
    printf("Da them sinh vien thanh cong!\n");
}

// 2. Hiển thị danh sách
void hienThiDanhSach(struct SinhVien ds[], int soLuong) {
    if (soLuong == 0) {
        printf("Danh sach sinh vien trong.\n");
        return;
    }
    printf("--------------------------- Danh Sach Sinh Vien ---------------------------\n");
    printf("| %-25s | %-15s | %-10s | %8s |\n", "Ho Ten", "Ngay Sinh", "Gioi Tinh", "Diem TB");
    printf("---------------------------------------------------------------------------\n");

    for (int i = 0; i < soLuong; i++) {
        inSinhVien(ds[i]);
    }
    printf("---------------------------------------------------------------------------\n");
}

// Hàm hỗ trợ tìm vi trí
int timViTriTheoTen(struct SinhVien ds[], int soLuong, char ten[]) {
    for (int i = 0; i < soLuong; ++i) {
        if (strcmp(ds[i].hoTen, ten) == 0) { 
            return i;
        }
    }
    return -1;
}

// 3. Xóa sinh viên
void xoaSinhVien(struct SinhVien ds[], int *soLuong) {
    char tenCanXoa[MAX_LEN];
    printf("Nhap ten sinh vien can xoa: ");
    fgets(tenCanXoa, MAX_LEN, stdin);
    xoa_xuong_dong(tenCanXoa);

    int viTri = timViTriTheoTen(ds, *soLuong, tenCanXoa);
    if (viTri != -1) {
        for (int i = viTri; i < *soLuong - 1; i++) {
            ds[i] = ds[i + 1];
        }
        (*soLuong)--;
        printf("Da xoa sinh vien.\n");
    } else {
        printf("Khong tim thay sinh vien voi ten: %s\n", tenCanXoa);
    }
}

// 4. Sửa thông tin
void suaThongTin(struct SinhVien ds[], int soLuong) {
    char tenCanSua[MAX_LEN];
    printf("Nhap ten sinh vien can sua: ");
    fgets(tenCanSua, MAX_LEN, stdin);
    xoa_xuong_dong(tenCanSua);

    int viTri = timViTriTheoTen(ds, soLuong, tenCanSua);
    if (viTri != -1) {
        printf("--- Nhap thong tin moi cho sinh vien ---\n");
        nhapThongTin(&ds[viTri]);
        printf("Da cap nhat thong tin.\n");
    } else {
        printf("Khong tim thay sinh vien voi ten: %s\n", tenCanSua);
    }
}

// 5. Tìm kiếm
void timKiem(struct SinhVien ds[], int soLuong) {
    int luaChon;
    char buffer[10];
    printf("1. Tim theo ten\n");
    printf("2. Tim theo khoang diem TB\n");
    printf("Chon: ");
    fgets(buffer, 10, stdin);
    sscanf(buffer, "%d", &luaChon);

    int timThay = 0;
    if (luaChon == 1) {
        char tenCanTim[MAX_LEN];
        printf("Nhap ten can tim: ");
        fgets(tenCanTim, MAX_LEN, stdin);
        xoa_xuong_dong(tenCanTim);
        
        printf("--- Ket qua tim kiem ---\n");
        for (int i = 0; i < soLuong; i++) {
            if (strcmp(ds[i].hoTen, tenCanTim) == 0) {
                inSinhVien(ds[i]);
                timThay = 1;
            }
        }
    } else if (luaChon == 2) {
        double diemMin, diemMax;
        printf("Nhap diem min: ");
        fgets(buffer, 10, stdin);
        sscanf(buffer, "%lf", &diemMin);
        
        printf("Nhap diem max: ");
        fgets(buffer, 10, stdin);
        sscanf(buffer, "%lf", &diemMax);

        printf("--- Ket qua tim kiem ---\n");
        for (int i = 0; i < soLuong; i++) {
            if (ds[i].diemTB >= diemMin && ds[i].diemTB <= diemMax) {
                inSinhVien(ds[i]);
                timThay = 1;
            }
        }
    }

    if (!timThay) {
        printf("Khong tim thay sinh vien nao thoa man.\n");
    }
}

// 6. Sắp xếp
int compareByScore(const void *a, const void *b) {
    struct SinhVien *svA = (struct SinhVien*)a;
    struct SinhVien *svB = (struct SinhVien*)b;
    if (svA->diemTB < svB->diemTB) return 1;
    if (svA->diemTB > svB->diemTB) return -1;
    return 0;
}

int compareByName(const void *a, const void *b) {
    struct SinhVien *svA = (struct SinhVien*)a;
    struct SinhVien *svB = (struct SinhVien*)b;
    return strcmp(svA->hoTen, svB->hoTen);
}

void sapXep(struct SinhVien ds[], int soLuong) {
    int luaChon;
    char buffer[10];
    printf("1. Sap xep theo diem TB giam dan\n");
    printf("2. Sap xep theo ten A-Z\n");
    printf("Chon: ");
    fgets(buffer, 10, stdin);
    sscanf(buffer, "%d", &luaChon);

    if (luaChon == 1) {
        qsort(ds, soLuong, sizeof(struct SinhVien), compareByScore);
        printf("Da sap xep theo diem giam dan.\n");
    } else if (luaChon == 2) {
        qsort(ds, soLuong, sizeof(struct SinhVien), compareByName);
        printf("Da sap xep theo ten A-Z.\n");
    }
    hienThiDanhSach(ds, soLuong);
}
