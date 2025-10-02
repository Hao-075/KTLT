#include <stdio.h>
#include <math.h> // Thu vi?n cho các hàm toán h?c nhu sqrt()

// --- KHAI BÁO CÁC HÀM (Function Prototypes) ---

/**
 * @brief Phân lo?i tam giác d?a vào 3 c?nh.
 * @return int Tr? v? m?t mã s?:
 * 0: Không ph?i tam giác
 * 1: Tam giác thu?ng
 * 2: Tam giác cân
 * 3: Tam giác d?u
 * 4: Tam giác vuông
 * 5: Tam giác vuông cân
 */
int phanLoaiTamGiac(double a, double b, double c);

/**
 * @brief Tính di?n tích tam giác theo công th?c Heron.
 * @return double Di?n tích c?a tam giác.
 */
double tinhDienTich(double a, double b, double c);


// --- HÀM CHÍNH (Main Program) ---
int main() {
    double a, b, c;

    // 1. Nh?p d? li?u
    printf("Nhap vao do dai ba canh a, b, c: ");
    scanf("%lf %lf %lf", &a, &b, &c);

    // 2. G?i hàm d? phân lo?i tam giác
    int loaiTamGiac = phanLoaiTamGiac(a, b, c);

    // 3. S? d?ng k?t qu? tr? v? d? thông báo và tính di?n tích
    if (loaiTamGiac == 0) {
        printf("=> Day khong phai la ba canh cua mot tam giac.\n");
    } else {
        printf("=> Day la ");
        switch (loaiTamGiac) {
            case 1: printf("tam giac thuong.\n"); break;
            case 2: printf("tam giac can.\n"); break;
            case 3: printf("tam giac deu.\n"); break;
            case 4: printf("tam giac vuong.\n"); break;
            case 5: printf("tam giac vuong can.\n"); break;
        }

        // G?i hàm tính di?n tích và in k?t qu?
        double dienTich = tinhDienTich(a, b, c);
        printf("   Dien tich cua tam giac la: %.2f\n", dienTich);
    }

    return 0;
}


// --- Ð?NH NGHIA CÁC HÀM (Function Definitions) ---

int phanLoaiTamGiac(double a, double b, double c) {
    // B1: Ki?m tra di?u ki?n t?n t?i c?a tam giác (b?t d?ng th?c tam giác)
    if (a + b <= c || a + c <= b || b + c <= a || a <= 0 || b <= 0 || c <= 0) {
        return 0; // Không ph?i tam giác
    }

    // B2: Ki?m tra các tính ch?t d?c bi?t (vuông, cân, d?u)
    int laVuong = 0;
    // Ð? tránh sai s? c?a s? th?c, ta so sánh bình phuong các c?nh
    if (a*a == b*b + c*c || b*b == a*a + c*c || c*c == a*a + b*b) {
        laVuong = 1;
    }

    int laCan = (a == b || b == c || a == c);
    int laDeu = (a == b && b == c);

    // B3: D?a vào các tính ch?t d? k?t lu?n (uu tiên các tru?ng h?p d?c bi?t nh?t)
    if (laDeu) {
        return 3; // Tam giác d?u
    }
    if (laVuong && laCan) {
        return 5; // Tam giác vuông cân
    }
    if (laVuong) {
        return 4; // Tam giác vuông
    }
    if (laCan) {
        return 2; // Tam giác cân
    }

    return 1; // M?c d?nh là tam giác thu?ng
}

double tinhDienTich(double a, double b, double c) {
    // Tính di?n tích theo công th?c Heron
    double p = (a + b + c) / 2.0; // N?a chu vi
    return sqrt(p * (p - a) * (p - b) * (p - c));
}
