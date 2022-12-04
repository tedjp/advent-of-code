#include <bits/stdc++.h>
#include <optional>

using namespace std;

static string GetCommonChars(string_view left, string_view right) {
    unordered_set<char> commonChars;
    for (char c: left)
        commonChars.emplace(c);

    string common;

    for (char c: right)
        if (commonChars.contains(c))
            common += c;

    return common;
}

static int Points(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 1;
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 27;
    throw runtime_error("unexpected char");
}

int main() {
    int points = 0;

    string commonChars;

    for (int i = 0; cin.good(); ++i) {
        string line;

        switch (i % 3) {
            case 0:
                getline(cin, commonChars);
                break;

            case 1:
            case 2:
                getline(cin, line);
                commonChars = GetCommonChars(commonChars, line);
                break;
        }

        if (i % 3 == 2)
            points += Points(commonChars[0]);
    }

    cout << points << "\n";
}
