import std.stdio;
void main()
{
    int steps;
    readf!"%d"(steps);
    int points = 5;
    foreach (step; 2..steps + 1)
    {
        points += step * 3 + 1;
        points %= 45_678;
    }
    writefln!"%d"(points);
}