#include <algorithm>
#include <array>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

static int readelf(istream& input) {
    int calories = 0;

    string str;

    for (string str; getline(input, str) && !str.empty(); )
    {
        int v = stoi(str);
        calories += v;
    }

    return calories;
}

int main() {
    // keep sorted
    array<int, 3> maxcal = {0, 0, 0};

    while (cin.good()) {
        int cals = readelf(cin);
        if (cals > maxcal[0]) {
            maxcal[0] = cals;
            sort(maxcal.begin(), maxcal.end());
            cerr << "maxcals: " << maxcal[0] << " " << maxcal[1] << " " << maxcal[2] << endl;
        }
    }

    cout << maxcal[0] + maxcal[1] + maxcal[2] << "\n";
}
