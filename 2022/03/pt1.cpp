#include <bits/stdc++.h>
#include <optional>

using namespace std;

struct Pack {
    string left;
    string right;
};

static optional<Pack> ReadPack(istream& input) {
    if (!input.good())
        return nullopt;

    string line;
    getline(input, line);

    if (line.empty())
        return nullopt;

    if (line.size() % 2 != 0)
        throw runtime_error("pack size not even");

    Pack pack;
    // This constructor requires C++20
    pack.left = string_view(line.begin(), line.begin() + (line.size() / 2));
    pack.right = string_view(line.begin() + (line.size() / 2), line.end());

    return pack;
}

static char FindDupe(const Pack& pack) {
    unordered_set<char> left;
    for (char c: pack.left)
        left.emplace(c);

    for (char c: pack.right)
        if (left.contains(c))
            return c;

    throw runtime_error("no dupe");
}

int Points(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 1;
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 27;
    throw runtime_error("unexpected char");
}

int main() {
    int points = 0;

    while (optional<Pack> pack = ReadPack(cin)) {
        points += Points(FindDupe(pack.value()));
    }

    cout << points << "\n";
}
