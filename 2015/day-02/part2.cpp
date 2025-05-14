#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int totalLength = 0;

    string dimensions;
    while (getline(cin, dimensions))
    {
        string side;
        vector<int> sides;

        stringstream ss(dimensions);
        while (getline(ss, side, 'x'))
        {
            sides.push_back(stoi(side));
        }

        sort(sides.begin(), sides.end());
        totalLength += 2 * (sides[0] + sides[1]) + (sides[0] * sides[1] * sides[2]);
    }

    cout << totalLength << endl;
    return 0;
}