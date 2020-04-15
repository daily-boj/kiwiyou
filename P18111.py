line = [int(x) for x in input().split(' ')]
vertical = line[0]
horizontal = line[1]
blocks = line[2]

# 높이가 i인 개수
height_count = [0] * 501
# 높이 i를 만들기 위해 파내야 하는 수
to_dig = [0] * 501
# 높이 i를 만들기 위해 채워야 하는 블럭 수
to_fill = [0] * 501

field = [[int(height) for height in input().split(' ')] for _ in range(vertical)]

lowest = 256
highest = 0

for row in field:
    for block in row:
        height_count[block] += 1
        lowest = min(lowest, block)
        highest = max(highest, block)

# 여기서 height_count[i] = 높이 i에 있는 블록 수
for height in range(highest, lowest - 1, -1):
    height_count[height] += height_count[height + 1]

field_area = horizontal * vertical
for height in range(lowest + 1, highest + 1):
    to_fill[height] = field_area - height_count[height] + to_fill[height - 1]

for height in range(highest - 1, lowest - 1, -1):
    to_dig[height] = to_dig[height + 1] + height_count[height + 1]

min_time = 500 * 500 * 256 * 2
min_time_height = 0

for height in range(highest, lowest - 1, -1):
    if to_fill[height] > (blocks + to_dig[height]):
        continue
    time = (to_dig[height] * 2) + to_fill[height]
    if time < min_time:
        min_time = time
        min_time_height = height

print('%d %d' % (min_time, min_time_height))