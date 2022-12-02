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

int main(void) {
    ifstream stream("input.txt");

    int maxcal = 0;

    while (stream.good()) {
        int cals = readelf(stream);
        if (cals > maxcal)
            maxcal = cals;
    }

    cout << maxcal << "\n";
}
