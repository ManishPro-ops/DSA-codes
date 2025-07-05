#include <iostream>
using namespace std;
#include <vector>

void solve(vector<int> nums,vector<int> output,int index,vector <vector<int>>& ans )
{
    if(index>=nums.size()){
        ans.push_back(output);
        return;
    }
    // to exclude array elements
    solve(nums,output,index+1,ans);

    // to include array elements
    int element =nums[index];
    output.push_back(element);
    solve(nums,output,index+1,ans);
    
}
int main()
{
    vector<int> nums={1,2,3};
    vector< vector<int>>ans ;
    vector<int>output ;
    int index=0;
    solve(nums,output,index,ans);
    // 
    return ans;
}