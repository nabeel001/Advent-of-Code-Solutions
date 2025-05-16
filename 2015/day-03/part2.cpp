#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    string s;
    cin >> s;

    bool santaDelivery = true;
    int x_santa = 0, y_santa = 0;
    int x_robo = 0, y_robo = 0;
    set<pair<int, int>> coordinates;
    coordinates.insert(make_pair(0, 0));

    for (int i = 0; i < s.length(); i++)
    {
        if (santaDelivery)
        {
            if (s[i] == '^')
                y_santa++;
            else if (s[i] == 'v')
                y_santa--;
            else if (s[i] == '<')
                x_santa--;
            else
                x_santa++;
            coordinates.insert(make_pair(x_santa, y_santa));
        }
        else
        {
            if (s[i] == '^')
                y_robo++;
            else if (s[i] == 'v')
                y_robo--;
            else if (s[i] == '<')
                x_robo--;
            else
                x_robo++;
            coordinates.insert(make_pair(x_robo, y_robo));
        }
        santaDelivery = !santaDelivery;
    }

    cout << coordinates.size() << endl;

    return 0;
}