quarters = 0
halves = 0
three_quarters = 0

for i in range(0, int(input())):
    eat = input()
    if eat[0] == '3':
        three_quarters += 1
    elif eat[2] == '2':
        halves += 1
    else:
        quarters += 1

quarters -= three_quarters
if halves % 2 == 1:
    quarters -= 2
    halves += 1
halves //= 2
if quarters > 0:
    quarters += 3
    print(str(three_quarters + halves + quarters // 4))
else:
    print(str(three_quarters + halves))
