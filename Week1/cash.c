#include <stdio.h>
#include <math.h>

int main() {
    float money;
    do {
    printf("Change owed: ");
    scanf("%f", &money);
    } while (money < 0);
    
    money = (int)round(money * 100);
    int count = 0;
    int coins[] = {25, 10, 5, 1};
    while (money > 0) {
        for (int i = 0; i < 4; i++) {
            if (money < coins[i]) {
                continue;
            }
            else {
                count += money / coins[i];
                money -= (money / coins[i]) * coins[i];
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
