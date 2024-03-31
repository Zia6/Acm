#include <cstdio>
#include <cstring>

char s[105];
int f1, f2;

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    while (n--) {
        fgets(s, sizeof(s), stdin);
        int len = strlen(s);
        for (int i = 0; i < len; i++) {
            if (s[i] == ',') {
                if (s[i - 1] == 'g' && s[i - 2] == 'n' && s[i - 3] == 'o')
                    f1 = 1;
            }
            if (s[i] == '.') {
                if (s[i - 1] == 'g' && s[i - 2] == 'n' && s[i - 3] == 'o')
                    f2 = 1;
            }
        }
        int sum = 0, dot = 0;
        if (f1 == 1 && f2 == 1) {
            for (int i = 0; i < len; i++) {
                if (s[i] == ',') {
                    dot = i;
                    for (int j = i; j < len; j++) {
                        if (s[j] == ' ')
                            sum++;
                    }
                }
            }
            for (int i = 0; i <= dot; i++)
                printf("%c", s[i]);
            for (int i = dot + 1;; i++) {
                printf("%c", s[i]);
                if (s[i] == ' ')
                    sum--;
                if (sum == 2)
                    break;
            }
            printf("qiao ben zhong.");
        } else
            printf("Skipped");
        printf("\n");
        f1 = f2 = 0;
    }
    return 0;
}
