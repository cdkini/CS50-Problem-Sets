import csv
import sys


def generate_str_list(reader):
    str_list = []
    for i, row in enumerate(reader):
        if not i:
            str_list += row[1:]
            break
    return str_list


def generate_str_dict(reader):
    str_dict = {}
    for i, row in enumerate(reader):
        if i:
            str_dict[tuple(int(num) for num in row[1:])] = row[0] 
    return str_dict


def count_str(seq, dna):
    seq_len = len(seq)
    found = False
    count = 0
    for i in range(len(dna)):
        if not found:
            if dna[i:i+seq_len] == seq:
                found = True
        if found:
            for j in range(i, len(dna)-i, seq_len):
                if dna[j:j+seq_len] == seq:
                    count += 1
                else:
                    return count
    return count
        
    
def main():
    if len(sys.argv) != 3:
        print("Error! Please ensure that you've passed two args!")
        sys.exit(1)
    with open(sys.argv[1], 'r') as db_file:
        reader = csv.reader(db_file)
        str_list = generate_str_list(reader) 
        str_dict = generate_str_dict(reader)
    with open(sys.argv[2], 'r') as dna_file:
        dna = dna_file.read()
        target = tuple([count_str(seq, dna) for seq in str_list])
        print(str_dict.get(target, "No match"))
        

if __name__ == "__main__":
    main()
