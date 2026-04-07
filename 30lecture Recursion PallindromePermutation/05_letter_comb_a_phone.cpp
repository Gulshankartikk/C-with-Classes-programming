#include<iostream>
#include<vector>
#include<string>
using namespace std;

void fun(string &digits, vector<string> &answer, vector<string> &mapping, string temp, int index)
{
    if(index == digits.size())
    {
        answer.push_back(temp);
        return;
    }

    int pos = digits[index] - '2';

    for(int i = 0; i < mapping[pos].size(); i++)
    {
        fun(digits, answer, mapping, temp + mapping[pos][i], index + 1);
    }
}

vector<string> letterCombinations(string digits)
{
    vector<string> answer;

    if(digits.size() == 0)
        return answer;

    vector<string> mapping(8);

    mapping[0] = "abc";
    mapping[1] = "def";
    mapping[2] = "ghi";
    mapping[3] = "jkl";
    mapping[4] = "mno";
    mapping[5] = "pqrs";
    mapping[6] = "tuv";
    mapping[7] = "wxyz";

    fun(digits, answer, mapping, "", 0);

    return answer;
}

int main()
{
    string digits = "23";

    vector<string> result = letterCombinations(digits);

    for(string s : result)
        cout << s << " ";

    return 0;
}