#include <stdio.h>

int my_atoifun(const char *s);

int main() {
    char s[100];

    printf("Enter the string: ");
    if (scanf("%99[^\n]", s) != 1) {
        printf("Error reading input.\n");
        return 1;
    }

    printf("The result of atoi: %d\n", my_atoifun(s));

    return 0;
}

int my_atoifun(const char *s) {
    int res = 0;
    int sign = 1;
    int i = 0;

    while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || 
           s[i] == '\r' || s[i] == '\v' || s[i] == '\f') {
        i++;
    }

    if (s[i] == '-') {
        sign = -1;
        i++;
    } else if (s[i] == '+') {
        i++;
    }

    while (s[i] >= '0' && s[i] <= '9') {
        res = (res * 10) + (s[i] - '0');
        i++;
    }

    return res * sign;
}
