#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

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