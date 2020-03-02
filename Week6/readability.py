def average_letters_and_sentences(text):
    letters, words, sentences = 0, 1, 0
    for char in text:
        if char.isalpha():
            letters += 1
        if char == ' ':
            words += 1
        if char in ['.', '!', '?']:
            sentences += 1
    L = letters / words * 100
    S = sentences / words * 100
    return (L, S)

  
def coleman_liau_index(L, S):
    return round(0.0588 * L - 0.296 * S - 15.8)

  
def main():
    text = input("Text: ")
    L, S = average_letters_and_sentences(text)
    index = coleman_liau_index(L, S)
    if index >= 16:
        print("Grade 16+")
    elif index <= 1:
        print("Before Grade 1")
    else:
        print(f"Grade {index}")

if __name__ == "__main__":
    main()
