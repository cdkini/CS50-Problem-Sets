#include <stdio.h>

int countDigits(int num);

int main() {
    unsigned long cardnum = 0;
    do {
        printf("Number: ");
        scanf("%lu", &cardnum);
    } while (countDigits(cardnum) < 13 || countDigits(cardnum) >16);
    
    return 0;
}

int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}
