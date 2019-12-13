#include <stdio.h>

void repeat(char input, int count);

int main() {
  int height;
  do {
  printf("Height: ");
  scanf("%d", &height);
  } while (height < 2 || height > 8);

  int spaces = height - 1;
  int hashes = 1;

  for (int i = 0; i < height; i++) {
    repeat(' ', spaces);
    repeat('#', hashes);
    printf(" ");
    repeat('#', hashes);
    repeat(' ', spaces);
    printf("\n");
    hashes++;
    spaces--;
  }
}

void repeat(char input, int count) {
  for (int i = 0; i < count; i++) {
    printf("%c", input);
  }
}
