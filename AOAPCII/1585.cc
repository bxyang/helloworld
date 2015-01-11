#include <cstdio>

int get_score(char* str, int length) {
    int ret_score = 0;
    int last_score = 0;
    while (*str != 0) {
        if (*str == 'O') {
            last_score += 1;
            ret_score += last_score;
        } else {
            last_score = 0;
        }
        str++;
    }
    return ret_score;
}


int main() {
    int case_num = 0;
    scanf("%d", &case_num);
    char str[100];
    for (int i = 0; i < case_num; i++) {
        int n = scanf("%s", str);
        int score = get_score(str, n);
        printf("%d\n", score);
    }
    return 0;
}
