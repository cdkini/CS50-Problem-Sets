# import.py
import csv
import os
import sys
import sqlite3


def main():

    if len(sys.argv) != 2 or sys.argv[1][-3:] != "csv":
        print("Please add a single CSV argument!")
        sys.exit(0)

    conn = sqlite3.connect("students.db")
    c = conn.cursor()

    if not os.path.exists("students.db"):
        c.execute('''CREATE TABLE students
                (first text, middle text, last text, house text, birth text)''')


    with open(sys.argv[1]) as f:

        reader = csv.reader(f)
        for i, row in enumerate(reader):

            if not i:
                continue

            name_list = row[0].split()
            first = name_list[0]

            if len(name_list) == 2:
                middle = None
                last = name_list[1]

            else:
                middle = name_list[1]
                last = name_list[2]

            house = row[1]
            birth = int(row[2])

            c.execute(f"INSERT INTO students VALUES ({first}, {middle}, {last}, {house}, {birth})")
            conn.commit()


if __name__ == "__main__":
    main()


# roster.py
# TODO
