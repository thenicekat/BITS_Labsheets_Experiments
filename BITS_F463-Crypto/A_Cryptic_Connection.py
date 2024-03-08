from math import ceil


playfair_key = input()
vignere_key = input()
columnar_key = input()
ciphertext = input()


def decrypt_playfair(ciphertext, key):
    letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    # First we have to add key to the matrix
    playfair_matrix = []
    for letter in key:
        if letter not in playfair_matrix:
            playfair_matrix.append(letter)
    for letter in letters:
        if letter not in playfair_matrix and letter != "J":
            playfair_matrix.append(letter)
    # Convert this into amatrix
    playfair_matrix = [playfair_matrix[i : i + 5] for i in range(0, 25, 5)]

    # for row in playfair_matrix:
    #     print(row)

    result = ""

    for i in range(0, len(ciphertext), 2):
        first_one = {
            "row": 0,
            "column": 0,
        }
        second_one = {
            "row": 0,
            "column": 0,
        }
        for row in range(5):
            for column in range(5):
                # print(playfair_matrix, row, column, i, ciphertext[i], ciphertext[i + 1])
                if playfair_matrix[row][column] == ciphertext[i]:
                    first_one["row"] = row
                    first_one["column"] = column
                if playfair_matrix[row][column] == ciphertext[i + 1]:
                    second_one["row"] = row
                    second_one["column"] = column

        if first_one["row"] == second_one["row"]:
            result += (
                playfair_matrix[first_one["row"]][(first_one["column"] - 1) % 5]
                + playfair_matrix[second_one["row"]][(second_one["column"] - 1) % 5]
            )
        elif first_one["column"] == second_one["column"]:
            result += (
                playfair_matrix[(first_one["row"] - 1) % 5][first_one["column"]]
                + playfair_matrix[(second_one["row"] - 1) % 5][second_one["column"]]
            )
        else:
            result += (
                playfair_matrix[first_one["row"]][second_one["column"]]
                + playfair_matrix[second_one["row"]][first_one["column"]]
            )
    return result


def decrypt_vignere(ciphertext, key):
    letters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"

    while len(key) < len(ciphertext):
        key += key
    key = key[: len(ciphertext)]

    plaintext = ""
    for i in range(len(ciphertext)):
        index = (letters.index(ciphertext[i]) - letters.index(key[i]) + 26) % 26
        # print(
        #     letters.index(ciphertext[i]), letters.index(key[i]), index, letters[index]
        # )
        plaintext += letters[index]
    return plaintext


def decrypt_columnar(ciphertext, key):
    # We have to sort the columns based on the column key
    column_key = [(x, i) for i, x in enumerate(key)]
    column_key = sorted(column_key, key=lambda x: x[0])

    numberOfFullCols = len(ciphertext) % len(key)
    numberOfRows = ceil(len(ciphertext) / len(key))
    numberOfCols = len(key)

    dictionary = {}
    for x in column_key:
        dictionary[x[0]] = []

    mat = [[0 for i in range(numberOfCols)] for j in range(numberOfRows)]

    if numberOfFullCols > 0:
        for i in range(numberOfFullCols, numberOfCols):
            mat[numberOfRows - 1][i] = 9

    # for x in mat:
    #     print(x)

    # print()
    tracker = 0
    for let, idx in column_key:
        # we fill column number idx
        for i in range(numberOfRows):
            if mat[i][idx] != 9:
                mat[i][idx] = ciphertext[tracker]
                tracker += 1
            else:
                mat[i][idx] = ""
    result = ""
    for x in mat:
        # print(x)
        for y in x:
            result += y
    return result


# print(ciphertext)
ciphertext = decrypt_columnar(ciphertext, columnar_key)
while ciphertext[-1] == "X":
    ciphertext = ciphertext[:-1]
ciphertext = decrypt_vignere(ciphertext, vignere_key)
while ciphertext[-1] == "X":
    ciphertext = ciphertext[:-1]
ciphertext = decrypt_playfair(ciphertext, playfair_key)
print(ciphertext)
