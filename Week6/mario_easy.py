def main():
  height = int(input("Height: "))
  for i in range(height):
    print((' ' * (height-i+1)) + ('#' * (i+1)))


if __name__ == "__main__":
  main()
