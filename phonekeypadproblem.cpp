#include <iostream>
using namespace std;
#include <string>
#include <vector>

void solve(string str,vector<string> &ans,string & output,int index,string *mapping) 
{
    if (index>=str.length())
    {
        ans.push_back(output);
        return;
    }

    int number=str[index]-'0';
    string value=mapping[number];

    for(int i=0;i<value.length();i++)
    {
        output.push_back(value[i]);
        solve(str,ans,output,index+1,mapping);
        output.pop_back();
    }

}



vector<string> lettercombination(string& str)
{
    vector<string> ans;
    if(str.length()==0)
    {
        return ans;
    }
    string output="";
    int index=0;
    string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};    
    solve(str,ans,output,index,mapping);
    return ans;


}

void printVector(const vector<string>& vec) 
{
    for (const auto& digits : vec) 
    {
        cout << "\"" << digits << "\"" << endl;
    }
}

int main() 
{
    string digits = "23";
    vector<string> string_list = lettercombination(digits);

    printVector(string_list);

    return 0;
}