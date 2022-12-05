#include <bits/stdc++.h>

using namespace std;

static int ProcessLine(string& s) {
    int a, b, c, d;
    int count = sscanf(s.c_str(), "%d-%d,%d-%d\n", &a, &b, &c, &d);
    if (count < 4 || count == EOF)
        throw runtime_error("insufficient input");

    if (a <= c && b >= d)
        return 1;
    if (c <= a && d >= b)
        return 1;

    return 0;
}

static int Parse(istream& input) {
    int overlaps = 0;
    string line;

    while (getline(input, line))
        overlaps += ProcessLine(line);

    return overlaps;
}

int main() {
    int overlaps = Parse(cin);

    cout << overlaps << "\n";
}
