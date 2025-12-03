#include <charconv>
#include <iostream>

using namespace std;

int main(void) {
    string input;

    int position = 50;
    unsigned zerocount = 0;

    while (getline(cin, input)) {
        char dir = input[0];
        int diff;
        from_chars(&input[1], &input[input.size()], diff);

        if (dir == 'L') {
            position -= diff;
        }
        else {
            position += diff;
        }

        position %= 100;

        if (position < 0)
            position += 100;

        if (position == 0) {
            ++zerocount;
        }
    }

    cout << zerocount << "\n";
    return 0;
}
