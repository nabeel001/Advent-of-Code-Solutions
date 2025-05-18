#include <bits/stdc++.h>
using namespace std;

int solveCircuit(string wireId, map<string, vector<string>> &logicMap, map<string, int> &logicMapValues);

vector<string> splitString(string s)
{
    string word;
    vector<string> words;
    stringstream ss(s);
    while (getline(ss, word, ' '))
        words.push_back(word);
    return words;
}

int getValue(string wireId, map<string, vector<string>> &logicMap, map<string, int> &logicMapValues)
{
    return all_of(wireId.begin(), wireId.end(), ::isdigit) ? stoi(wireId) : solveCircuit(wireId, logicMap, logicMapValues);
}

int solveCircuit(string wireId, map<string, vector<string>> &logicMap, map<string, int> &logicMapValues)
{
    vector<string> input = logicMap[wireId];

    if (logicMapValues[wireId] != -1)
        return logicMapValues[wireId];

    if (input.size() == 1)
        return logicMapValues[wireId] = getValue(input[0], logicMap, logicMapValues);

    else if (input.size() == 2 and input[0] == "NOT")
        return logicMapValues[wireId] = (uint16_t)~solveCircuit(input[1], logicMap, logicMapValues);

    else
    {
        int value1 = getValue(input[0], logicMap, logicMapValues);
        int value2 = getValue(input[2], logicMap, logicMapValues);

        int result;
        string operation = input[1];
        if (operation == "OR")
            result = value1 | value2;
        else if (operation == "AND")
            result = value1 & value2;
        else if (operation == "LSHIFT")
            result = value1 << value2;
        else if (operation == "RSHIFT")
            result = value1 >> value2;

        return logicMapValues[wireId] = (uint16_t)result;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    string instruction;
    map<string, vector<string>> logicMap;
    map<string, int> logicMapValues;

    while (getline(cin, instruction))
    {
        vector<string> tokens = splitString(instruction);
        string wireId = tokens.back();
        vector<string> input;
        for (int i = 0; i < tokens.size(); i++)
        {
            if (tokens[i] == "->")
                break;
            else
                input.push_back(tokens[i]);
        }
        logicMap[wireId] = input;
        logicMapValues[wireId] = -1;
    }

    int signalToA = solveCircuit("a", logicMap, logicMapValues);

    for (auto &it : logicMapValues)
        it.second = -1;
    logicMapValues["b"] = signalToA;

    int finalSignal = solveCircuit("a", logicMap, logicMapValues);

    cout << finalSignal << endl;
    return 0;
}