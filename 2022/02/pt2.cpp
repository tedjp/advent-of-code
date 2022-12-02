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

constexpr int LossPoints = 0;
constexpr int DrawPoints = 3;
constexpr int WinPoints = 6;

int Points(const Move myMove, const Move theirMove) {
    int points = 0;

    switch (myMove) {
        case Rock:
            points = 1;
            if (theirMove == Rock)
                return points + DrawPoints;
            if (theirMove == Paper)
                return points + LossPoints;
            return points + WinPoints;

        case Paper:
            points = 2;
            if (theirMove == Rock)
                return points + WinPoints;
            if (theirMove == Paper)
                return points + DrawPoints;
            return points + LossPoints;

        case Scissors:
            points = 3;
            if (theirMove == Rock)
                return points + LossPoints;
            if (theirMove == Paper)
                return points + WinPoints;
            return points + DrawPoints;
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

enum Outcome {
    Win,
    Lose,
    Draw,
};

static Outcome OutcomeFromChar(char c) {
    switch (c) {
        case 'X':
            return Lose;
        case 'Y':
            return Draw;
        case 'Z':
            return Win;
    }

    throw runtime_error(__func__);
}

static Move MoveFromOutcome(const Move opMove, const Outcome outcome) {
    switch (opMove) {
        case Rock:
            if (outcome == Win)
                return Paper;
            if (outcome == Lose)
                return Scissors;
            return Rock;

        case Paper:
            if (outcome == Win)
                return Scissors;
            if (outcome == Lose)
                return Rock;
            return Paper;

        case Scissors:
            if (outcome == Win)
                return Rock;
            if (outcome == Lose)
                return Paper;
            return Scissors;
    }

    throw runtime_error(__func__);
}

int main() {
    int score = 0;
    char oppChar;
    char outcomeChar;

    while (cin >> oppChar >> outcomeChar) {
        const Move opMove = MoveFromChar(oppChar);
        const Outcome outcome = OutcomeFromChar(outcomeChar);
        const Move meMove = MoveFromOutcome(opMove, outcome);

        score += Points(meMove, opMove);
    }

    cout << score << "\n";
}
