#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    string s;
    int totalOldCharCount = 0;
    int totalNewCharCount = 0;

    while (getline(cin, s))
    {
        totalOldCharCount += s.length();

        totalNewCharCount += 6;
        for (int i = 1; i < s.length() - 1; i++)
        {
            if (s[i] == '\\')
            {
                if (s[i + 1] == 'x')
                {
                    i += 3;
                    totalNewCharCount += 5;
                }
                else
                {
                    ++i;
                    totalNewCharCount += 4;
                }
            }
            else
                totalNewCharCount++;
        }
    }

    cout << totalNewCharCount - totalOldCharCount << endl;
    return 0;
}