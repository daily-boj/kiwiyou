components = input().split(" ")

year = int(components[2])
is_leap = year % 400 == 0 or (year % 4 == 0 and year % 100 != 0)
february_days = 29 if is_leap else 28
time_components = components[3].split(":")
minutes = int(time_components[0]) * 60 + int(time_components[1])

month_map = {
	"January": 0,
	"February": 31,
	"March": 31 + february_days,
	"April": 31 + february_days + 31,
	"May": 31 + february_days + 31 + 30,
	"June": 31 + february_days + 31 + 30 + 31,
	"July": 31 + february_days + 31 + 30 + 31 + 30,
	"August": 31 + february_days + 31 + 30 + 31 + 30 + 31,
	"September": 31 + february_days + 31 + 30 + 31 + 30 + 31 + 31,
	"October": 31 + february_days + 31 + 30 + 31 + 30 + 31 + 31 + 30,
	"November": 31 + february_days + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31,
	"December": 31 + february_days + 31 + 30 + 31 + 30 + 31 + 31 + 30 + 31 + 30,
}

days_of_month = int(components[1][:-1])
days = days_of_month + month_map[components[0]] - 1
minutes += days * 24 * 60
days_in_year = 366 if is_leap else 365

print((minutes / (days_in_year * 24 * 60)) * 100)
