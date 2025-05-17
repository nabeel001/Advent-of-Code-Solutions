#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    vector<string> blackListStrings = {"ab", "cd", "pq", "xy"};
    string s;
    int niceStringCount = 0;

    while (getline(cin, s))
    {
        int vowelsCount = false;
        bool doubleLetterCheck = false;
        bool validStringCheck = true;

        int n = s.length();

        for (int i = 0; i < n; i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                vowelsCount++;
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i + 1])
            {
                doubleLetterCheck = true;
                break;
            }
        }

        if (s.find("ab") != string::npos || s.find("cd") != string::npos || s.find("pq") != string::npos || s.find("xy") != string::npos)
            validStringCheck = false;

        if (vowelsCount >= 3 && doubleLetterCheck && validStringCheck)
            niceStringCount++;
    }

    cout << niceStringCount << endl;
    return 0;
}