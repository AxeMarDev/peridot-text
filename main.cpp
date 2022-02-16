#include "mainPre.cpp"

// global string holder
// stringHold objectString;
// intHold objectInt;

// function to parse and store string values
void varString(string &input, stringHold &objectString, intHold &objectInt)
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
void varInt(string &input, stringHold &objectString, intHold &objectInt)
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

void varAssign(string &input, stringHold &objectString, intHold &objectInt)
{

    if (input[4] == 's')
    {

        varString(input, objectString, objectInt);
    }
    else if (input[4] == 'i')
    {

        varInt(input, objectString, objectInt);
    }
    else if (input[4] == 'c')
    {
    }
}

void findVar(string &target, stringHold &objectString, intHold &objectInt)
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

void sysOut(string &input, stringHold &objectString, intHold &objectInt)
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
    findVar(target, objectString, objectInt);
}

void batchEnd(string &input)
{
}

void perserChar(string &input, stringHold &objectString, intHold &objectInt)
{

    if (input[0] == 'v')
    {

        if (input[1] == 'a')
        {

            if (input[2] == 'r')
            {

                varAssign(input, objectString, objectInt);
            }
        }
    }
    else if (input[0] == 'o')
    {

        if (input[1] == 'u')
        {

            if (input[2] == 't')
            {

                sysOut(input, objectString, objectInt);
            }
        }
    }
    else if (input[0] == 'e')
    {
        if (input[1] == 'n')
        {

            if (input[2] == 'd')
            {

                batchEnd(input);
            }
        }
    }
    else if (input[0] == 'i')
    {

        if (input[1] == 'f')
        {
        }
    }
}

void parser(vector<string> &input, stringHold &objectString, intHold &objectInt)
{
    for (int i = 0; i < input.size(); i++)
    {

        string stringIn = input[i];
        perserChar(stringIn, objectString, objectInt);
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
    stringHold objectString;
    intHold objectInt;
    charHold objectChar;

    if (fin.is_open())
    {
        string line;
        while (getline(fin, line))

        {
            stringVec.push_back(line);
        }
        fin.close();
        parser(stringVec, objectString, objectInt);
    }
    return 0;
}