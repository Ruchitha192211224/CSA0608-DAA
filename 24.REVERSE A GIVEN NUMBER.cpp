#include <stdio.h>

int reverseNumber(int num) {
    int reversed = 0;
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed;
}

int main() {
    int num;
    printf("P.RUCHITHA-192211224\n");
    printf("Enter a number: ");
    scanf("%d", &num);
    int reversed = reverseNumber(num);
    printf("Reversed number is: %d\n", reversed);
    return 0;
}
