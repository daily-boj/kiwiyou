#include <iostream>
using namespace std;

int main() {
    int cases;
    cin >> cases;
    while (cases-- > 0) {
        int row, column;
        cin >> row >> column;
        char box[400][400];
        int candy = 0;
        for (int y = 0; y < row; ++y) {
            for (int x = 0; x < column; ++x) {
                cin >> box[y][x];
                if (y >= 2 && box[y][x] == '^' && box[y - 1][x] == 'o' && box[y - 2][x] == 'v') {
                    ++candy;
                } else if (x >= 2 && box[y][x] == '<' && box[y][x - 1] == 'o' && box[y][x - 2] == '>') {
                    ++candy;
                }
            }
        }
        cout << candy << "\n";
    }
}