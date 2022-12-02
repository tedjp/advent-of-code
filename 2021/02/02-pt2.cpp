#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

using namespace std;

struct Input {
    int aim = 0;
    int distance = 0;
};

struct Position {
    int distance = 0;
    int depth = 0;
};

Input read() {
    string relative;
    int dist;

    cin >> relative;
    cin >> dist;

    Input input;

    if (relative == "forward")
        input.distance += dist;
    else if (relative == "down")
        input.aim += dist;
    else if (relative == "up")
        input.aim -= dist;

    return input;
}

int main(void) {
    Position position;
    int aim = 0;

    for (;;) {
        Input input = read();
        if (!cin.good())
            break;

        if (input.distance != 0) {
            position.distance += input.distance;
            position.depth += aim * input.distance;
        } else {
            aim += input.aim;
        }
    }

    cout << (position.depth * position.distance) << '\n';
}
