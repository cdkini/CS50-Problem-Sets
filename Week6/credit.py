def is_valid_card(card_num) -> boolean:
  if int(len(card_num)) not in [13, 15, 16]:
    return False
  temp = 0
  for i, digit in enumerate(card_num[::-1]):
    if not i % 2:
      temp += int(digit)
    else:
      temp += sum(int(x) for x in str(int(digit)*2))
  if str(temp)[-1] != '0':
    return False
  return True


def which_card(card_num):
  length = len(card_num)
  if length == 15 and int(card_num[:2]) in [34, 37]:
    print("AMEX")
  elif length == 16 and int(card_num[:2]) in range(51, 56):
    print("MASTERCARD")
  elif length in [13, 16] and int(card_num[0]) == 4:
    print("VISA")
  else:
    print("INVALID")


def main():
  card_num = input("Number: ")
  if not is_valid_card(card_num):
    print("INVALID")
  else:
    which_card(card_num)
    
if __name__ == "__main__":
  main()
