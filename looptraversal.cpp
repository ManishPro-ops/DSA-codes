#include<iostream>
using namespace std;
#include<vector>

//array traversal

void wave(vector<vector<int>>& arr)
{
    int row=arr.size();
    int col=arr[0].size();
    int j=0;
    int i;
    while(j!=col)
    {
        if(j%2==0)
        {
            i=0;
            while(i!=row)
            {
                cout<< arr[i][j] ;
                i++;
            }
            
        }
        else{
            i= row-1;
            while(i>=0)
            {
                cout<< arr[i][j] ;
                i--;
            }
            
        }
        //cout<< endl;
        j++;

    }
}

vector<vector<int>> spiral(vector<vector<int>>& arr)
{
    vector<vector<int>> ans;
    int row=arr.size();
    int col=arr[0].size();
    int startrow=0;
    int startcol=0;
    int endrow=row-1;
    int endcol=col-1;
    int count=0;
    int total=row*col;
    while(count<total)
    {
        for(int i=startcol; count<total && i<endcol;i++)
        {
            cout<<ans.push_back(arr[startrow][i]);
            count++;
        }
        startrow++;


        for(int i=startrow; count<total && i<endrow;i++)
        {
            ans.push_back(arr[i][endcol]);
            count++;
        }
        endcol--;


        for(int i=endcol-1; count<total && i<startcol;i--)
        {
            ans.push_back(arr[endrow][i]);
            count++;
        }
        endrow--;


        for(int i=endrow-1; count<total && i<startrow;i--)
        {
            ans.push_back(arr[i][startcol]);
            count++;
        }
        startcol++;

    }return ans;
   
}
int main()
{
    vector<vector<int>> arr1{{1,2,3},{4,5,6},{7,8,9}};
    // arr[0].push_back({1,2,3});
    // arr[1].push_back({4,5,6});
    // arr[2].push_back({7,8,9});
    wave(arr1);
    spiral(arr1);
    return 0;
}