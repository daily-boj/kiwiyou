from collections import Counter
while True:
    line = input()
    if line == '#':
        break
    letter, sentence = line.split(maxsplit=1)
    counter = Counter(sentence.lower())
    print(letter, counter[letter])