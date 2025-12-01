#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("input.txt", "r", stdin);

    int zero_count = 0;
    int current_position = 50;

    string rotation;
    while (getline(cin, rotation))
    {
        char direction = rotation[0];
        int count = stoi(rotation.substr(1));

        if (direction == 'L')
        {
            current_position -= (count % 100);
            if (current_position < 0)
                current_position += 100;
        }
        else
        {
            current_position += (count % 100);
            if (current_position >= 100)
                current_position %= 100;
        }

        if (current_position == 0)
            zero_count++;
    }

    cout << zero_count << endl;
    return 0;
}