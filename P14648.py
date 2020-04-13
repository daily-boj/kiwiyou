first_row = input().split(' ')
seq_len = int(first_row[0])
query_count = int(first_row[1])

sequence = [int(x) for x in input().split(' ')]

for _ in range(0, query_count):
    query = [int(x) - 1 for x in input().split(' ')]
    if query[0] == 0:
        a = query[1]
        b = query[2]
        print(sum(sequence[a:(b + 1)]))
        sequence[a], sequence[b] = sequence[b], sequence[a]
    else:
        a = query[1]
        b = query[2]
        c = query[3]
        d = query[4]
        print(sum(sequence[a:(b + 1)]) - sum(sequence[c:(d + 1)]))
