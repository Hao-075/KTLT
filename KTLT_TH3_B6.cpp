#include <stdio.h>
#include <string.h>
#include <ctype.h>

void xoa_xuong_dong(char s[]) {
    s[strcspn(s, "\n")] = '\0';
}

void reverse_string(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

int main() {
    char s[256];
    char s_copy[256];

    printf("Nhap chu?i: ");
    fgets(s, 256, stdin);
    xoa_xuong_dong(s);
    strcpy(s_copy, s);

    int spaceCount = 0;
    for (int i = 0; s[i] != '\0'; ++i) {
        if (s[i] == ' ') {
            spaceCount++;
        }
    }
    printf("So khoang trang: %d\n", spaceCount);

    char cleaned_s[256] = "";
    char *word = strtok(s_copy, " ");
    
    while (word != NULL) {
        strcat(cleaned_s, word);
        strcat(cleaned_s, " ");
        word = strtok(NULL, " ");
    }
    cleaned_s[strlen(cleaned_s) - 1] = '\0';
    printf("Chuoi sau khi loai khoang trang thua: '%s'\n", cleaned_s);

    char s1[100], s2[100];
    printf("Nhap s1: ");
    fgets(s1, 100, stdin);
    xoa_xuong_dong(s1);

    printf("Nhap s2: ");
    fgets(s2, 100, stdin);
    xoa_xuong_dong(s2);

    strcat(s1, s2);
    printf("Chuoi s1 sau khi noi: %s\n", s1);

    strcpy(s_copy, s); 
    char capitalized_s[256] = "";
    char *word_cap = strtok(s_copy, " ");
    
    while (word_cap != NULL) {
        word_cap[0] = toupper(word_cap[0]);
        strcat(capitalized_s, word_cap);
        strcat(capitalized_s, " ");
        word_cap = strtok(NULL, " ");
    }
    capitalized_s[strlen(capitalized_s) - 1] = '\0';
    printf("Chuoi sau khi viet hoa: %s\n", capitalized_s);

    char original_s[] = "Lap Trinh";
    printf("Chuoi goc: %s\n", original_s);
    reverse_string(original_s);
    printf("Chuoi dao nguoc: %s\n", original_s);

    return 0;
}
