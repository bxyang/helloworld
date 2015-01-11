#include <cstdio>
#include <cctype>

char* get_num(char* str, int& n) {
    if (*str == '\0') {n = 1; return str;}
    if (isalpha(*str)) {n = 1; return str;}

    if (*(str+1) == '\0') { n = *str - '0'; return str+1;}
    if (isalpha(*(str+1))) { n = *str - '0'; return str+1;}

    n = (*str - '0')*10 + (*(str+1) - '0');
    return str+2;
}

double get_mass(char* str, int length) {
    double ret_mass = 0;
    int n = 0;
    while (*str != '\0') {
        char c = str[0]; 
        int n = -1;
        str = get_num(str+1, n);
        double w = -1;
        switch(c) {
        case 'C':
            w = 12.01;
            break;
        case 'H':
            w = 1.008;
            break;
        case 'O':
            w = 16;
            break;
        case 'N':
            w = 14.01;
            break;
        }
        ret_mass += n*w;
    }
    return ret_mass;
}

int main() {
    int case_num = 0;
    scanf("%d", &case_num);
    char str[100];
    for (int i = 0; i < case_num; i++) {
        int n = scanf("%s", str);
        double mass = get_mass(str, n);
        printf("%.3f\n", mass);
    }
    return 0;
}
