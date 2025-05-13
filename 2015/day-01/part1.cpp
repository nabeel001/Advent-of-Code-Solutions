#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    string s;
    cin >> s;

    int resultFloor = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            resultFloor++;
        else
            resultFloor--;
    }

    cout << resultFloor << endl;
    return 0;
}