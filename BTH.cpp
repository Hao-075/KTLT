#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ð?nh nghia h?ng s?
#define MAX_SV 100 // T?i da 100 sinh viên
#define MAX_LEN 50 // Ð? dài t?i da c?a chu?i

// 1. Ð?NH NGHIA C?U TRÚC
struct SinhVien {
    char hoTen[MAX_LEN];
    char ngaySinh[12]; // D?ng "dd/mm/yyyy"
    char gioiTinh[10];
    double diemTB;
};

// 2. HÀM TI?N ÍCH
// Hàm xóa ký t? \n ? cu?i chu?i mà fgets d?c vào
void xoa_xuong_dong(char s[]) {
    s[strcspn(s, "\n")] = '\0';
}

// Hàm nh?p thông tin cho 1 sinh viên
void nhapThongTin(struct SinhVien *sv) {
    char buffer[10]; // Bi?n d?m d? d?c s?

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
    sscanf(buffer, "%lf", &sv->diemTB); // Chuy?n chu?i sang double
}

// Hàm in thông tin 1 sinh viên (in d?ng b?ng)
void inSinhVien(struct SinhVien sv) {
    // In theo d?nh d?ng "| Ten | Ngay Sinh | Gioi Tinh | Diem |"
    printf("| %-25s | %-15s | %-10s | %8.2f |\n", 
           sv.hoTen, sv.ngaySinh, sv.gioiTinh, sv.diemTB);
}

// 3. CÁC HÀM CH?C NANG (DÙNG PROTOTYPE)
void themSinhVien(struct SinhVien ds[], int *soLuong);
void hienThiDanhSach(struct SinhVien ds[], int soLuong);
int timViTriTheoTen(struct SinhVien ds[], int soLuong, char ten[]);
void xoaSinhVien(struct SinhVien ds[], int *soLuong);
void suaThongTin(struct SinhVien ds[], int soLuong);
void timKiem(struct SinhVien ds[], int soLuong);
void sapXep(struct SinhVien ds[], int soLuong);

// Hàm so sánh cho qsort
int compareByScore(const void *a, const void *b);
int compareByName(const void *a, const void *b);


// 4. HÀM MAIN (MENU ÐI?U KHI?N)
int main() {
    struct SinhVien danhSachSV[MAX_SV]; // M?ng c? d?nh
    int soLuongHienTai = 0; // Bi?n d?m s? sinh viên
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
        sscanf(buffer, "%d", &luaChon); // Ð?c l?a ch?n

        switch (luaChon) {
            case 1:
                // Truy?n con tr? (d?a ch?) c?a soLuongHienTai
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

// 5. Ð?NH NGHIA CÁC HÀM CH?C NANG

// 1. Thêm sinh viên
void themSinhVien(struct SinhVien ds[], int *soLuong) {
    if (*soLuong >= MAX_SV) {
        printf("Danh sach da day, khong the them!\n");
        return;
    }

    printf("--- Nhap thong tin sinh vien moi ---\n");
    nhapThongTin(&ds[*soLuong]); // Nh?p vào v? trí cu?i cùng
    (*soLuong)++; // Tang s? lu?ng
    printf("Da them sinh vien thanh cong!\n");
}

// 2. Hi?n th? danh sách
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

// Hàm h? tr? tìm v? trí
int timViTriTheoTen(struct SinhVien ds[], int soLuong, char ten[]) {
    for (int i = 0; i < soLuong; ++i) {
        if (strcmp(ds[i].hoTen, ten) == 0) { // Dùng strcmp d? so sánh chu?i
            return i; // Tr? v? ch? s? (index)
        }
    }
    return -1; // Không tìm th?y
}

// 3. Xóa sinh viên
void xoaSinhVien(struct SinhVien ds[], int *soLuong) {
    char tenCanXoa[MAX_LEN];
    printf("Nhap ten sinh vien can xoa: ");
    fgets(tenCanXoa, MAX_LEN, stdin);
    xoa_xuong_dong(tenCanXoa);

    int viTri = timViTriTheoTen(ds, *soLuong, tenCanXoa);
    if (viTri != -1) {
        // Dùng vòng l?p d? d?n các ph?n t? t? phía sau lên
        for (int i = viTri; i < *soLuong - 1; i++) {
            ds[i] = ds[i + 1];
        }
        (*soLuong)--; // Gi?m s? lu?ng
        printf("Da xoa sinh vien.\n");
    } else {
        printf("Khong tim thay sinh vien voi ten: %s\n", tenCanXoa);
    }
}

// 4. S?a thông tin
void suaThongTin(struct SinhVien ds[], int soLuong) {
    char tenCanSua[MAX_LEN];
    printf("Nhap ten sinh vien can sua: ");
    fgets(tenCanSua, MAX_LEN, stdin);
    xoa_xuong_dong(tenCanSua);

    int viTri = timViTriTheoTen(ds, soLuong, tenCanSua);
    if (viTri != -1) {
        printf("--- Nhap thong tin moi cho sinh vien ---\n");
        nhapThongTin(&ds[viTri]); // Nh?p dè lên thông tin cu
        printf("Da cap nhat thong tin.\n");
    } else {
        printf("Khong tim thay sinh vien voi ten: %s\n", tenCanSua);
    }
}

// 5. Tìm ki?m
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

// 6. S?p x?p
// Hàm so sánh cho qsort (theo di?m gi?m d?n)
int compareByScore(const void *a, const void *b) {
    struct SinhVien *svA = (struct SinhVien*)a;
    struct SinhVien *svB = (struct SinhVien*)b;
    if (svA->diemTB < svB->diemTB) return 1;
    if (svA->diemTB > svB->diemTB) return -1;
    return 0;
}

// Hàm so sánh cho qsort (theo tên A-Z)
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
    hienThiDanhSach(ds, soLuong); // Hi?n th? l?i danh sách
}
