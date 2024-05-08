import csv
import sys


def main():

    # TODO: Check for command-line usage
    n = len(sys.argv)
    print("Total arguments passed:", n)
    if (n != 3):
        print("Error, wrong command line argument number")
        sys.exit(1)

    # TODO: Read database file into a variable
    rows = []
    header = None
    # database_path = "databases/" + str(name_db)
    with open("databases/small.csv", 'r') as file:
        reader = csv.DictReader(file)
        header = reader.fieldnames
        for row in reader:
            rows.append(row)
    print(rows[0])
    print(rows[1])
    print(rows[2])

    # TODO: Read DNA sequence file into a variable
    seq = []
    # sequence_path = "sequences/" + str(name_seq)
    with open("sequences/1.txt", 'r') as file:
        seq = file.read()
    print(seq)

    # TODO: Find longest match of each STR in DNA sequence
    STRs = header[1:]
    str_match = []
    for str in STRs:
        str_match.append(longest_match(seq, str))
    print(STRs)
    print(str_match)

    # TODO: Check database for matching profiles
    i, match_found = 0, 0;
    while ((match_found == 0) & (i < len(rows)-1)):
        for j in range(len(STRs)):
            print("j is : ", j)
            key_str = j
            nb_str = rows[i][STRs[j]]
            print("STR : ", key_str, " nb : ", nb_str)
            if (nb_str == str_match[j]):
                match_found = 1

            

        i+=1

    return



def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
