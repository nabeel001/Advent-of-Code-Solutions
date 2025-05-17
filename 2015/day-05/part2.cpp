#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    string s;
    int niceStringCount = 0;

    while (getline(cin, s))
    {
        int n = s.length();
        bool twiceLetterCheck = false;
        bool oneLetterBetweenCheck = false;

        for (int i = 0; i < n - 2; i++)
        {
            string s1 = s.substr(i, 2);
            for (int j = i + 2; j < n - 1; j++)
            {
                string s2 = s.substr(j, 2);
                if (s1 == s2)
                {
                    twiceLetterCheck = true;
                    break;
                }
            }
            if (twiceLetterCheck)
                break;
        }

        for (int i = 0; i < n - 2; i++)
        {
            if (s[i] == s[i + 2])
            {
                oneLetterBetweenCheck = true;
                break;
            }
        }

        if (twiceLetterCheck && oneLetterBetweenCheck)
            niceStringCount++;
    }

    cout << niceStringCount << endl;
    return 0;
}