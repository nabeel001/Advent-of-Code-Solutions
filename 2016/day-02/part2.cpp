#include <bits/stdc++.h>
using namespace std;

bool checkColMov(int rowId, int colId)
{
    if ((rowId == 0 || rowId == 4) && colId == 2)
        return true;
    if ((rowId == 1 || rowId == 3) && colId >= 1 && colId <= 3)
        return true;
    if (rowId == 2 && colId >= 0 && colId <= 4)
        return true;
    return false;
}

bool checkRowMov(int rowId, int colId)
{
    if ((colId == 0 || colId == 4) && rowId == 2)
        return true;
    if ((colId == 1 || colId == 3) && rowId >= 1 && rowId <= 3)
        return true;
    if (colId == 2 && rowId >= 0 && rowId <= 4)
        return true;
    return false;
}

int main()
{
    freopen("input.txt", "r", stdin);

    pair<int, int> currIndex = {1, 1};
    vector<vector<char>> keypad = {{'0', '0', '1', '0', '0'}, {'0', '2', '3', '4', '0'}, {'5', '6', '7', '8', '9'}, {'0', 'A', 'B', 'C', '0'}, {'0', '0', 'D', '0', '0'}};
    string instruction;
    string accessCode = "";

    while (getline(cin, instruction))
    {
        for (int i = 0; i < instruction.length(); i++)
        {
            int rowId = currIndex.first;
            int colId = currIndex.second;

            if (instruction[i] == 'R')
                colId = checkColMov(rowId, colId + 1) ? colId + 1 : colId;
            else if (instruction[i] == 'L')
                colId = checkColMov(rowId, colId - 1) ? colId - 1 : colId;
            else if (instruction[i] == 'U')
                rowId = checkRowMov(rowId - 1, colId) ? rowId - 1 : rowId;
            else if (instruction[i] == 'D')
                rowId = checkRowMov(rowId + 1, colId) ? rowId + 1 : rowId;

            currIndex = {rowId, colId};
        }
        accessCode += keypad[currIndex.first][currIndex.second];
    }

    cout << accessCode << endl;
    return 0;
}