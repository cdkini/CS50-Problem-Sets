import csv
import sys


def generate_str_dict(file):
    reader = csv.reader(file)
    str_dict = {}
    for i, row in enumerate(reader):
        if not i:
            str_dict[row[0]] = tuple(val for val in row[1:])
        else:
            str_dict[tuple(int(val) for val in row[1:])] = row[0]
    print(str_dict)
    return str_dict


def longest_repeating_str(target_str, sequence):
    count = 1
    while True:
        if target_str * count in sequence:
            count += 1
        else:
            return count


def main():
    if len(sys.argv) != 3:
        print("Error! Please ensure that you've passed two args")
        sys.exit(1)
    with open(sys.argv[1], 'r') as db_file:
        str_dict = generate_str_dict(db_file)
        with open(sys.argv[2], 'r') as sequence_file:
            sequence = sequence_file.read()
            check = []
            for dna_str in str_dict["name"]:
                check.append(longest_repeating_str(dna_str, sequence))
            print(check[::-1])
            result = str_dict.get(tuple(str(val) for val in check), "No match")
            print(result)


if __name__ == "__main__":
    main()
