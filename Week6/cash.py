def main():
  change = float(input("Change owed: "))
  count = 0
  coins = [0.25, 0.1, 0.05, 0.01]
  
  for coin in coins:
    change -= change // coin * coin
    count += change // coin
    
  print(int(count))

if __name__ == "__main__":
  main()
