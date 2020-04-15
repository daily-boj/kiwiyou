words = int(input().split(' ')[0])

short_forms = [input() for _ in range(words)]
long_forms = [input() for _ in range(words)]

extended = [''.join(letter * 2 for letter in word) for word in short_forms]

if extended == long_forms:
    print('Eyfa')
else:
    print('Not Eyfa')