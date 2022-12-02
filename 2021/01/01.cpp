#include <iostream>
#include <optional>
#include <string>

using namespace std;

int main(void) {
    optional<int> previous;

    unsigned increases = 0;

    string s;
    while (cin >> s) {
        int v = stoi(s);
        if (previous && *previous < v)
            ++increases;
        previous = v;
    }

    cout << increases << '\n';
}
