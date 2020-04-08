#include <stdio.h>
#include <string.h>

int main() {
	char *month_table[12] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };
	int month_offset[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	char month[10];
	int day, year, hour, minute;
	int is_leap;
	int year_days = 365 * 24 * 60;
	char **month_cursor = month_table;
	int *offset_cursor = month_offset;
	scanf("%s %d, %d %d:%d", month, &day, &year, &hour, &minute);
	is_leap = !(year % 400) || (!(year & 3) && year % 100);
	if (is_leap) {
		month_offset[1] += 1;
		year_days += 24 * 60;
	}
	while (strncmp(*month_cursor, month, 3)) {
		day += *offset_cursor;
		++month_cursor;
		++offset_cursor;
	}
	minute += ((day - 1) * 24 + hour) * 60;
	printf("%.15f", 100 * minute / (double) year_days);
}
