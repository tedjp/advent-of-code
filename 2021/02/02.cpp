#include <iostream>
#include <stdexcept>
#include <string>
#include <utility>

using namespace std;

struct Position {
    int distance = 0;
    int depth = 0;
};

Position read() {
    string relative;
    int dist;

    cin >> relative;
    cin >> dist;

    Position p;

    if (relative == "forward")
        p.distance += dist;
    else if (relative == "down")
        p.depth += dist;
    else if (relative == "up")
        p.depth -= dist;
#if 0
    else
        throw runtime_error("invalid direction");
#endif

    return p;
}

int main(void) {
    Position position;

    while (cin.good()) {
        Position change = read();
        if (!cin.good())
            break;
        position.depth += change.depth;
        position.distance += change.distance;
    }

    cout << (position.depth * position.distance) << '\n';
}
