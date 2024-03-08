column_key = input()
matrix = input()
plaintext = input()
left_header = "CRYPTO"
top_header = "GRAPHY"

# First we have to map the column key to the matrix
key_matrix = {}
for idx, c in enumerate(matrix):
    key_matrix[c] = left_header[int(idx / 6)] + top_header[idx % 6]

# Now we can map the plaintext to the matrix
res = ""
for x in plaintext:
    res += key_matrix[x]

# We have to convert this string to a 6 column matrix
res = [res[i : i + len(column_key)] for i in range(0, len(res), len(column_key))]
for i in range(len(res)):
    res[i] = res[i].ljust(len(column_key), "X")

res = [x[i] for i in range(len(column_key)) for x in res]

# We now have to split them into sets of (size / keysize)
rows = len(res) // len(column_key)
res = ["".join(res[i : i + rows]) for i in range(0, len(res), rows)]

# We have to sort the columns based on the column key
column_key = [(x, i) for i, x in enumerate(column_key)]
column_key = sorted(column_key, key=lambda x: x[0])

final_ans = [res[x[1]] for x in column_key]
print("".join(final_ans))
