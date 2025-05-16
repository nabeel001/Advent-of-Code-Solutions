#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    string s;
    cin >> s;

    int x = 0, y = 0;
    set<pair<int, int>> coordinates;
    coordinates.insert(make_pair(x, y));

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '^')
            y++;
        else if (s[i] == 'v')
            y--;
        else if (s[i] == '<')
            x--;
        else
            x++;
        coordinates.insert(make_pair(x, y));
    }

    cout << coordinates.size() << endl;

    return 0;
}