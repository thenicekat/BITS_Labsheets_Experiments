# Take input
key = input()
digits_included = [int(x) for x in input().split()]
cipher_to_decrypt = input()
rail_fence_key = int(input())

tracker_on_key = 0
table = [[], [], []]

for i in range(10):
    if i not in digits_included:
        table[0].append(key[tracker_on_key])
        tracker_on_key += 1
    else:
        table[0].append("")

for i in range(10):
    table[1].append(key[tracker_on_key])
    tracker_on_key += 1

for i in range(10):
    if tracker_on_key < len(key):
        table[2].append(key[tracker_on_key])
        tracker_on_key += 1
    else:
        table[2].append("")


length = len(cipher_to_decrypt)


class RailFence:
    def __init__(self, key):
        self.key = int(key)
        self.rail_fence = [[] for i in range(self.key)]
        self.tracker_on_word = 0
        self.result = ""

    def add_to_rail_fence(self, i, word):
        if self.tracker_on_word >= len(word):
            return

        for i in range(self.key):
            # print(i)
            if self.tracker_on_word < len(word):
                self.rail_fence[i].append(word[self.tracker_on_word])
                self.tracker_on_word += 1

        for i in range(self.key - 2, 0, -1):
            # print(i)
            if self.tracker_on_word < len(word):
                self.rail_fence[i].append(word[self.tracker_on_word])
                self.tracker_on_word += 1

        return self.add_to_rail_fence(i, word)

    def extract_word(self, word):
        if self.tracker_on_word >= len(word):
            return

        for i in range(self.key):
            if self.tracker_on_word < len(word):
                self.result[self.tracker_on_word] = self.new_rail_fence[i].pop(0)
                self.tracker_on_word += 1

        for i in range(self.key - 2, 0, -1):
            if self.tracker_on_word < len(word):
                self.result[self.tracker_on_word] = self.new_rail_fence[i].pop(0)
                self.tracker_on_word += 1

        return self.extract_word(word)

    def encrypt(self, word):
        self.tracker_on_word = 0
        self.rail_fence = [[] for i in range(self.key)]
        self.add_to_rail_fence(0, word)

        result = ""
        for x in self.rail_fence:
            for y in x:
                result += y
        return result

    def decrypt(self, word):
        self.tracker_on_word = 0

        self.rail_fence = [[] for i in range(self.key)]
        self.new_rail_fence = [[] for i in range(self.key)]

        self.add_to_rail_fence(0, word)

        counter = 0
        row = 0

        for x in self.rail_fence:
            for y in x:
                self.new_rail_fence[row].append(word[counter])
                counter += 1
            row += 1

        self.tracker_on_word = 0
        self.result = [""] * len(word)
        self.extract_word(word)
        return "".join(self.result)


railfence = RailFence(rail_fence_key)

result = railfence.decrypt(cipher_to_decrypt)

# now we have the result, we need to decrypt it using the table
# we check if the number is in the digits_included list
final_answer = ""
letter_index = 0
while letter_index < len(result):
    if int(result[letter_index]) not in digits_included:
        final_answer += table[0][(int(result[letter_index]))]
    else:
        final_answer += table[1 + digits_included.index(int(result[letter_index]))][
            int(result[letter_index + 1])
        ]
        letter_index += 1
    letter_index += 1

print(final_answer)
