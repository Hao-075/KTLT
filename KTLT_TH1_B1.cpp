 #include <stdio.h>

int main() {
    char tenMatHang[100];
    float trongLuong;
    float donGia;
    char maChatLuong;
    int soLuong;

    printf("NHAP THONG TIN MAT HANG:\n");
    printf("Nhap ten mat hang: ");
    fgets(tenMatHang, sizeof(tenMatHang), stdin);
    printf("Nhap trong luong (kg): ");
    scanf("%f", &trongLuong);
    printf("Nhap don gia (VND): ");
    scanf("%f", &donGia);
    printf("Nhap ma chat luong (A, B, C,...): ");
    scanf(" %c", &maChatLuong);
    printf("Nhap so luong: ");
    scanf("%d", &soLuong);
    
    printf("THONG TIN MAT HANG VUA NHAP:\n");
    printf("Ten mat hang: %s", tenMatHang);
    printf("Trong luong: %.2f kg\n", trongLuong);
    printf("Don gia: %.0f VND\n", donGia);
    printf("Ma chat luong: %c\n", maChatLuong);
    printf("So luong: %d\n", soLuong);

    return 0;
}

