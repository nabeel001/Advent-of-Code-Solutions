#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    string s;
    cin >> s;

    int position = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            position++;
        else
            position--;
        if (position == -1)
        {
            position = i + 1;
            break;
        }
    }

    cout << position << endl;
    return 0;
}