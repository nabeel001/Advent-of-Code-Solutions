#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    pair<int, int> currIndex = {1, 1};
    vector<vector<char>> keypad = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};
    string instruction;
    string accessCode = "";

    while (getline(cin, instruction))
    {
        for (int i = 0; i < instruction.length(); i++)
        {
            int rowId = currIndex.first;
            int colId = currIndex.second;

            if (instruction[i] == 'R')
                colId = min(++colId, 2);
            else if (instruction[i] == 'L')
                colId = max(--colId, 0);
            else if (instruction[i] == 'U')
                rowId = max(--rowId, 0);
            else if (instruction[i] == 'D')
                rowId = min(++rowId, 2);

            currIndex = {rowId, colId};
        }
        accessCode += keypad[currIndex.first][currIndex.second];
    }

    cout << accessCode << endl;
    return 0;
}