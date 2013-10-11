#include<cstdlib>
#include<cstdio>
#include<string.h>
#include<list>
#include<iterator>
using namespace std;

char* read_str[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
char* times_str[] = {"", "one", "double", "triple", "quadruple", "quintuple", 
                    "sextuple", "septuple", "octuple", "nonuple", "decuple"};

int main() {
    int n;
    FILE* fin = fopen("A-large.in", "r");
    FILE* fout = fopen("A-large.out", "w");
    fscanf(fin, "%d\n", &n);
    for (int i = 1; i <=n; i++) {
        char* phone = new char[101];
        char* format = new char[101];
        fscanf(fin, "%s", phone);
        fscanf(fin, "%s", format);
        int* group = new int[101];
        int group_num = 0;
        char* p1 = format;
        char* p2 = format;
        int c = 0;
        while (*p2 != '\0') {
            if (*p2 == '-') {
                char tmp[101];
                strncpy(tmp, p1, c);
                *(tmp+c) = '\0';
                group[group_num++] = atoi(tmp);
                p1 = p2 + 1;
                c = 0;
            } else
                c++;
            p2++;
        }
        char tmp[101];
        strncpy(tmp, p1, c);
        *(tmp+c) = '\0';
        group[group_num++] = atoi(tmp);

        fprintf(fout, "Case #%d:", i);
        char* ph = phone;
        for (int j = 0; j < group_num; j++) {
            int cn = group[j];
            char last = '0' - 1;
            int cnt = 0;
            for (int k = 0; k < cn; k++) {
                if (ph[k] == last)
                    cnt++;
                else {
                    if (cnt == 0) {
                        last = ph[k];
                        cnt = 1;
                    } else {
                        if ((cnt == 1) || (cnt > 10)) {
                            for (int l = 0; l < cnt; l++)
                                fprintf(fout, " %s", read_str[last-'0']);
                        }
                        else if (cnt <= 10) {
                            fprintf(fout, " %s %s", times_str[cnt], read_str[last-'0']);
                        } 
                        last = ph[k];
                        cnt = 1;
                    }
                }
            }
            if (cnt == 0) {
                ;
            } else {
                if ((cnt == 1) || (cnt > 10)) {
                    for (int l = 0; l < cnt; l++)
                        fprintf(fout, " %s", read_str[last-'0']);
                }
                else if (cnt <= 10) {
                    fprintf(fout, " %s %s", times_str[cnt], read_str[last-'0']);
                } 
            }
            ph = ph + cn;
        }
        fprintf(fout, "\n");
    }
}
