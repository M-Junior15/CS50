import sys
import csv


def main():
    # Print how to use the program and exit
    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py data.csv sequence.txt")

    # Create variables
    csvfile = []
    comparecsv = []
    names = []

    # Open and read csv file
    with open(sys.argv[1]) as fileC:
        readcsv = csv.DictReader(fileC)
        for row in readcsv:
            # Csv receives the first row of csv file (names and STR)
            csvfile = list(readcsv.fieldnames)
            # Append all the csv inside comparecsv
            comparecsv.append(row)
            # Append all the names in csv file inside names
            names.append(row['name'])

    # Open the txt file and read the content
    with open(sys.argv[2]) as fileT:
        readtxt = fileT.read()

    # Call the function compute_str
    compute = compute_str(csvfile, readtxt)

    # Get all the values of comparecsv (with names)
    value = []
    for v in comparecsv:
        value.append(list(v.values()))

    # Get all the values of value
    integer = []
    for i in value:
        # Take of the names
        integer.append(i[1:])

    # Call the function string_integer
    val = string_integer(integer)

    # Get all values inside val
    count = 0
    for i in val:
        # See if compute (list of compute_str) is equal i (STR of all names)
        if compute[1:] == i:
            print(names[count])
            break
        elif compute != i and count == len(names) - 1:
            print('No match')
            break
        count += 1

# Function to change string numbers to integer numbers
def string_integer(val):
    results = []
    for i in val:
        results.append(list(map(int, i)))

    return results

# Function to calculate the maximum sequence
def compute_str(str_list, sequence):
    # Declare variables
    count = 0
    sum_list = []

    # For each value in str_list (STR's of each people in csv file)
    for val in str_list:
        i = 0
        largest = 0
        # While i is less than lenght of sequence (txt file, sequence of STR's)
        while i < len(sequence):
            # If sequence from i to i + lenght of val = val
            if sequence[i: i + len(val)] == val:
                # Count sum 1
                count += 1
                # If count is greater than largest
                if count > largest:
                    # Largest receives count
                    largest = count
                i += len(val)
            else:
                count = 0
                i += 1
        # Append largest to a list
        sum_list.append(largest)

    # Return the list
    return sum_list


main()

