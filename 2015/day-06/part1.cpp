#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    vector<vector<bool>> grid(1000, vector<bool>(1000, false));
    string instruction;
    int lightOnCount = 0;

    while (getline(cin, instruction))
    {
        string word, operation;
        vector<int> coords;

        stringstream ss(instruction);
        while (getline(ss, word, ' '))
        {
            if (word == "toggle" || word == "on" || word == "off")
                operation = word;
            if (word.find(",") != string::npos)
            {
                string value = "";
                for (int i = 0; i < word.length(); i++)
                {
                    if (word[i] == ',')
                    {
                        coords.push_back(stoi(value));
                        value.clear();
                    }
                    else
                        value += word[i];
                }
                coords.push_back(stoi(value));
            }
        }

        for (int x = coords[0]; x <= coords[2]; x++)
        {
            for (int y = coords[1]; y <= coords[3]; y++)
            {
                if (operation == "on")
                    grid[x][y] = true;
                else if (operation == "off")
                    grid[x][y] = false;
                else
                    grid[x][y] = !grid[x][y];
            }
        }
    }

    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if (grid[i][j])
                lightOnCount++;
        }
    }

    cout << lightOnCount << endl;
    return 0;
}