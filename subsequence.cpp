#include <iostream>
using namespace std;
#include <vector>
#include<string>
vector<string> subsequence(string& str)
{
    int n=str.size();
    vector<string> subseq_list;
    for (int i=1;i<(1<<n);++i)
    {
        string subseq;
        for(int j=0;j<n;++j)
        {
            if (i&(1<<j)){
                subseq.push_back(str[j]);
            }
           
        } subseq_list.push_back(subseq);

    }
    return subseq_list;

}
void printVector(const vector<string>& vec) {
    for (const auto& str : vec) {
        cout << "\"" << str << "\"" << endl;
    }
}

int main() {
    string str = "23";
    vector<string> subsequences_list = subsequence(str);

    printVector(subsequences_list);

    return 0;
}