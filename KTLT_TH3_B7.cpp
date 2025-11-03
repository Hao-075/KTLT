#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct MatHang {
    char ma[20];
    char ten[100];
    int so_luong;
    double don_gia;
    int ton_kho;
    int bao_hanh;
};

void xoa_xuong_dong_mh(char s[]) {
    s[strcspn(s, "\n")] = '\0';
}

void nhapMatHang(struct MatHang *mh) {
    char buffer[100];

    printf("Nhap ma hang: ");
    fgets(mh->ma, 20, stdin);
    xoa_xuong_dong_mh(mh->ma);

    printf("Nhap ten mat hang: ");
    fgets(mh->ten, 100, stdin);
    xoa_xuong_dong_mh(mh->ten);

    printf("Nhap so luong: ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%d", &mh->so_luong);

    printf("Nhap don gia: ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%lf", &mh->don_gia);

    printf("Nhap so luong ton: ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%d", &mh->ton_kho);

    printf("Nhap thoi gian bao hanh (thang): ");
    fgets(buffer, 100, stdin);
    sscanf(buffer, "%d", &mh->bao_hanh);
}

void xuatMatHang(struct MatHang mh) {
    printf("Ma: %s, Ten: %s, SL: %d, Gia: %.2f, Ton: %d, BH: %d thang\n",
           mh.ma, mh.ten, mh.so_luong, mh.don_gia, mh.ton_kho, mh.bao_hanh);
}

int compareByTonKho(const void *a, const void *b) {
    struct MatHang *mhA = (struct MatHang*)a;
    struct MatHang *mhB = (struct MatHang*)b;
    return (mhA->ton_kho - mhB->ton_kho);
}

int main() {
    int n;
    struct MatHang ds[100];
    char buffer[10];

    printf("Nhap so luong mat hang: ");
    fgets(buffer, 10, stdin);
    sscanf(buffer, "%d", &n);

    for (int i = 0; i < n; ++i) {
        printf("--- Nhap mat hang thu %d ---\n", i + 1);
        nhapMatHang(&ds[i]);
    }

    int maxTon = -1;
    int idxTon = -1;
    for (int i = 0; i < n; i++) {
        if (ds[i].ton_kho > maxTon) {
            maxTon = ds[i].ton_kho;
            idxTon = i;
        }
    }
    printf("\n--- Mat hang ton kho nhieu nhat ---\n");
    if(idxTon != -1) xuatMatHang(ds[idxTon]);

    double maxGia = -1.0;
    int idxGia = -1;
    for (int i = 0; i < n; i++) {
        if (ds[i].don_gia > maxGia) {
            maxGia = ds[i].don_gia;
            idxGia = i;
        }
    }
    printf("\n--- Mat hang don gia cao nhat ---\n");
    if(idxGia != -1) xuatMatHang(ds[idxGia]);

    printf("\n--- Mat hang bao hanh > 12 thang ---\n");
    for (int i = 0; i < n; i++) {
        if (ds[i].bao_hanh > 12) {
            xuatMatHang(ds[i]);
        }
    }

    qsort(ds, n, sizeof(struct MatHang), compareByTonKho);
    printf("\n--- Danh sach sau khi sap xep tang dan theo ton kho ---\n");
    for (int i = 0; i < n; i++) {
        xuatMatHang(ds[i]);
    }

    return 0;
}
