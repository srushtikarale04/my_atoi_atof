#include <stdio.h>

double my_atoffun(const char *s);

int main() {
    char s[100];

    printf("enter the string for atof: ");
    if (scanf("%99[^\n]", s) != 1) {
        return 1;
    }

    printf("the atof is %f\n", my_atoffun(s));

    return 0;
}

double my_atoffun(const char *s) {
    double res = 0;
    double factor = 1.0;
    int i = 0;

    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || 
           s[i] == '\r' || s[i] == '\v' || s[i] == '\f') {
        i++;
    }

    int sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '-' || s[i] == '+') {
        i++;
    }

    for (; s[i] >= '0' && s[i] <= '9'; i++) {
        res = (res * 10) + (s[i] - '0');
    }

    if (s[i] == '.') {
        i++;
    }

    for (; s[i] >= '0' && s[i] <= '9'; i++) {
        factor *= 0.1;
        res = res + (s[i] - '0') * factor;
    }

    return res * sign;
}
