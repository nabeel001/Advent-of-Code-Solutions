#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int totalArea = 0;

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
        int area1 = sides[0] * sides[1];
        int area2 = sides[1] * sides[2];
        int area3 = sides[0] * sides[2];

        totalArea += 2 * (area1 + area2 + area3) + min(min(area1, area2), area3);
    }

    cout << totalArea << endl;
    return 0;
}