import std.stdio;

void main()
{
    int width;
    readf!"%d"(width);
    int zero = 1;
    int full = 0;
    int two = 2;
    int one = 0;
    foreach (_; 1..width)
    {
        immutable int new_zero = full;
        immutable int new_full = zero + two;
        immutable int new_two = full + full + one;
        immutable int new_one = two;
        zero = new_zero;
        full = new_full;
        two = new_two;
        one = new_one;
    }
    writefln!"%d"(full);
}