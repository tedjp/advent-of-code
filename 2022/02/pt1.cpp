#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

enum Move {
    Rock,
    Paper,
    Scissors
};

constexpr int Loss = 0;
constexpr int Draw = 3;
constexpr int Win = 6;

int Points(const Move myMove, const Move theirMove) {
    int points = 0;

    switch (myMove) {
        case Rock:
            points = 1;
            if (theirMove == Rock)
                return points + Draw;
            if (theirMove == Paper)
                return points;
            return points + Win;

        case Paper:
            points = 2;
            if (theirMove == Rock)
                return points + Win;
            if (theirMove == Paper)
                return points + Draw;
            return points + Loss;

        case Scissors:
            points = 3;
            if (theirMove == Rock)
                return points + Loss;
            if (theirMove == Paper)
                return points + Win;
            return points + Draw;
    }

    throw runtime_error(__func__);
}

static Move MoveFromChar(char c) {
    switch (c) {
        case 'A':
        case 'X':
            return Rock;
        case 'B':
        case 'Y':
            return Paper;
        case 'C':
        case 'Z':
            return Scissors;
    }

    throw runtime_error(__func__);
}

int main() {
    int score = 0;
    char oppChar;
    char meChar;

    while (cin >> oppChar >> meChar) {
        const Move opMove = MoveFromChar(oppChar);
        const Move meMove = MoveFromChar(meChar);

        score += Points(meMove, opMove);
    }

    cout << score << "\n";
}
