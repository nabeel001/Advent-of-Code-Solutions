#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    string s;
    int totalCodeCharCount = 0;
    int totalMemCharCount = 0;

    while (getline(cin, s))
    {
        totalCodeCharCount += s.length();

        for (int i = 1; i < s.length() - 1; i++)
        {
            if (s[i] == '\\')
            {
                if (s[i + 1] == 'x')
                    i += 3;
                else
                    ++i;
            }
            totalMemCharCount++;
        }
    }

    cout << totalCodeCharCount - totalMemCharCount << endl;
    return 0;
}