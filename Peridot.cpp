#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class stringHold // holds user created strings and values by matching word
{
private:
    // holds matching word of output
    vector<string> index;
    // holds output of matching ketword
    vector<string> output;

public:
    // debugging function
    void getter()
    {

        // cout << index[index.size() - 1] << '-' << output[output.size() - 1] << endl;
    }
    // pushs index "word" into vecto
    void setterI(string &input)
    {
        index.push_back(input);
    }
    // pushes outpur string into vector
    void setterO(string &input)
    {
        output.push_back(input);
    }

    bool search(string &key)
    {
        if (count(index.begin(), index.end(), key))
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    int find(string &key)
    {

        for (int i = 0; i < index.size(); i++)
        {

            if (index[i] == key)
            {
                return i;
            }
        }
        return -1;
    }

    void printOut(int &index)
    {
        cout << output[index] << endl;
    }
};

class intHold // holds user created strings and values by matching word
{
private:
    // holds matching word of output
    vector<string> index;
    // holds output of matching ketword
    vector<int> output;

public:
    // debugging function
    void getter()
    {
        //  cout << index[index.size() - 1] << '-' << output[output.size() - 1] << endl;
    }
    // pushs index "word" into vecto
    void setterI(string &input)
    {
        index.push_back(input);
    }
    // pushes outpur string into vector
    void setterO(int &input)
    {
        output.push_back(input);
    }
    bool search(string &key)
    {
        if (count(index.begin(), index.end(), key))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    int find(string &key)
    {

        for (int i = 0; i < index.size(); i++)
        {

            if (index[i] == key)
            {
                return i;
            }
        }
        return -1;
    }
    void printOut(int &index)
    {

        cout << output[index] << endl;
    }
};

// global string holder
stringHold objectString;
intHold objectInt;

// function to parse and store string values
void varString(string &input)
{
    int x = 10;
    string output;
    string outputO;

    while (input[x + 1] != '=')
    {
        if (x == 11)
        {
            string holder = " ";
            holder = input[x];
            output = holder;
        }
        else
        {
            string holder = " ";
            holder = input[x];
            output += holder;
        }

        x++;
    }

    for (int i = x + 3; i < input.size(); i++)
    {

        if (i == x)
        {
            string holder = " ";
            holder = input[i];
            outputO = holder;
        }
        else
        {
            string holder = " ";
            holder = input[i];
            outputO += holder;
        }
    }

    objectString.setterI(output);
    objectString.setterO(outputO);
    objectString.getter();
}

// function to parse and store interger values
void varInt(string &input)
{
    int x = 7;
    string output;
    string outputO;

    while (input[x + 1] != '=')
    {
        if (x == 8)
        {
            string holder = " ";
            holder = input[x];
            output = holder;
        }
        else
        {
            string holder = " ";
            holder = input[x];
            output += holder;
        }

        x++;
    }

    for (int i = x + 3; i < input.size(); i++)
    {

        if (i == x)
        {
            string holder = " ";
            holder = input[i];
            outputO = holder;
        }
        else
        {
            string holder = " ";
            holder = input[i];
            outputO += holder;
        }
    }
    int outputed;
    stringstream stoi(outputO);
    stoi >> outputed;

    objectInt.setterI(output);
    objectInt.setterO(outputed);
    objectInt.getter();
}

void varAssign(string &input)
{

    if (input[4] == 's')
    {

        varString(input);
    }
    else if (input[4] == 'i')
    {

        varInt(input);
    }
    else if (input[4] == 'c')
    {
    }
}

void findVar(string &target)
{
    int index;
    string key = target;
    if (objectString.search(key))
    {
        index = objectString.find(key);

        objectString.printOut(index);
    }
    else if (objectInt.search(key))
    {
        index = objectInt.find(key);

        objectInt.printOut(index);
    }
}

void sysOut(string &input)
{
    string target;
    int index;
    for (int i = 4; i < input.size(); i++)
    {
        if (i == 4)
        {
            string holder = " ";
            holder = input[i];
            target = holder;
        }
        else
        {
            string holder = " ";
            holder = input[i];
            target += holder;
        }
    }
    findVar(target);
}

void batchEnd(string &input)
{
}

void parser(vector<string> &input)
{
    for (int i = 0; i < input.size(); i++)
    {

        string stringIn = input[i];

        if (stringIn[0] == 'v')
        {

            if (stringIn[1] == 'a')
            {

                if (stringIn[2] == 'r')
                {

                    varAssign(stringIn);
                }
            }
        }
        else if (stringIn[0] == 'o')
        {

            if (stringIn[1] == 'u')
            {

                if (stringIn[2] == 't')
                {

                    sysOut(stringIn);
                }
            }
        }
        else if (stringIn[0] == 'e')
        {
            if (stringIn[1] == 'n')
            {

                if (stringIn[2] == 'd')
                {

                    batchEnd(stringIn);
                }
            }
        }
        else if (stringIn[0] == 'i')
        {

            if (stringIn[1] == 'f')
            {
            }
        }
    }
}

int main()
{

    // string nameoffile;
    // cout << "files must be in the same directory as peridot.exec" << endl;
    // cout << "please enter the name of the peridot file (ends in .pdot): ";
    // cin >> nameoffile;

    ifstream fin("input.txt");

    vector<string> stringVec(0);

    if (fin.is_open())
    {
        string line;
        while (getline(fin, line))

        {
            stringVec.push_back(line);
        }
        fin.close();
        parser(stringVec);
    }
    return 0;
}