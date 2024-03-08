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


print(
    decrypt_vignere(
        "DAZFISFSPAVQLSNPXYSZWXALCDAFGQUISMTPHZGAMKTTFTCCFXKFCRGGLPFETZMMMZOZDE",
        "AMBROISETHOMAS",
    )
)
