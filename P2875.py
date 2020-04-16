from math import ceil

line = [int(n) for n in input().split()]

female, male, internship = line[0], line[1], line[2]

max_team = min(female, male * 2) // 2

internship -= female - max_team * 2
internship -= male - max_team

if internship > 0:
    max_team -= ceil(internship / 3)

print(max(max_team, 0))