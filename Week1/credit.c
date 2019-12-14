#include <stdio.h>

int countDigits(unsigned long num);

int main(void) {
  unsigned long cardNum = 0;
   do {
       printf("Number: ");
       scanf("%lu", &cardNum);
   } while (countDigits(cardNum) < 13 || countDigits(cardNum) > 16);
    
  int sumDig = 0, otherDig = 0, firstTwo = 0;
  int len = countDigits(cardNum);
  int i = 0;
    
  while (cardNum != 0) {
    int lastDig = cardNum % 10;
    if (i % 2 == 0) { 
      otherDig += lastDig;
    }
    else {
      if (lastDig >= 5) {
        sumDig += ((lastDig - 4) * 2 - 1);
      }
      else {
        sumDig += lastDig * 2;
      }
    }
    if (countDigits(cardNum) == 2) {
      firstTwo += cardNum;
    }
    cardNum /= 10;
    i++;
  }
    
  if ((sumDig + otherDig) % 10 != 0) {
      printf("INVALID\n");
      return 0;
  }
  if ((firstTwo == 51 || firstTwo == 52 || firstTwo == 53 || firstTwo == 54 || firstTwo == 55) && (len == 16)) {
    printf("MASTERCARD\n");
  }
  else if ((firstTwo == 34 || firstTwo == 37) && (len == 15)) {
    printf("AMEX\n");
  }
  else if ((firstTwo / 10 == 4) && (len == 13 || len == 16)) {
    printf("VISA\n");
  }
  else {
    printf("INVALID\n");
  }
  return 0;
}

 
int countDigits(unsigned long num) {
  int count = 0;
  while (num != 0) {
    num /= 10;
    count++;
  }
  return count;
}
