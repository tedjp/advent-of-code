#include <array>
#include <iostream>
#include <optional>
#include <string>

using namespace std;

int read() {
    string s;
    cin >> s;
    if (cin.good())
        return stoi(s);
    return 0;
}

int sum(array<int, 3> vs) {
    return vs[0] + vs[1] + vs[2];
}

int main(void) {
    array<int, 3> vs = {0, 0, 0};
    unsigned nvs = 0;
    unsigned increases = 0;

    while (cin.good()) {
        int prevsum = sum(vs);
        ++nvs;
        int v = read();
        if (!cin.good())
            break;
        vs[nvs % vs.size()] = v;
        int s = sum(vs);
        if (nvs >= 4 && s > prevsum)
            ++increases;
    }

    cout << increases << '\n';
}
