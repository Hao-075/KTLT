#include <stdio.h>
#include <math.h>

int kiemTraTamGiac(float a, float b, float c) {
    if (a > 0 && b > 0 && c > 0 && (a + b > c) && (a + c > b) && (b + c > a)) {
        return 1;
    }
    return 0;
}

void phanLoaiTamGiac(float a, float b, float c) {
    const float epsilon = 0.0001;

    int laTamGiacVuong = (fabs(a*a + b*b - c*c) < epsilon) || 
                         (fabs(a*a + c*c - b*b) < epsilon) || 
                         (fabs(b*b + c*c - a*a) < epsilon);

    if (a == b && b == c) {
        printf("Loai tam giac: Tam giac deu.\n");
    }
    else if (laTamGiacVuong && (a == b || b == c || a == c)) {
        printf("Loai tam giac: Tam giac vuong can.\n");
    }
    else if (a == b || b == c || a == c) {
        printf("Loai tam giac: Tam giac can.\n");
    }
    else if (laTamGiacVuong) {
        printf("Loai tam giac: Tam giac vuong.\n");
    }
    else {
        printf("Loai tam giac: Tam giac thuong.\n");
    }
}

float tinhDienTich(float a, float b, float c) {
    float p = (a + b + c) / 2.0;
    
    float dienTich = sqrt(p * (p - a) * (p - b) * (p - c));
    
    return dienTich;
}

int main() {
    float a, b, c;

    printf("Nhap vao do dai 3 canh a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    if (kiemTraTamGiac(a, b, c)) {
        printf("Ba canh a, b, c tao thanh mot tam giac.\n");
        
        phanLoaiTamGiac(a, b, c);
        
        printf("Dien tich cua tam giac la: %.2f\n", tinhDienTich(a, b, c));
    } else {
        printf("Ba canh a, b, c khong tao thanh mot tam giac.\n");
    }

    return 0;
}
