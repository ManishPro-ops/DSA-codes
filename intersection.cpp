#include<iostream>
using namespace std;
#include<vector>
vector<int> intersection(int arr1[],int arr2[])
{
    int i=0,j=0;
    vector<int> ans;
    while(i<6 && j<6)
    {
        if (arr1[i]==arr2[j]){
            ans.push_back(arr1[i]);
            i++;
            j++;
        }
        else if(arr1[i]<arr2[j]){
             i++;
        }
        else{
            j++;
        }
    }
    return ans;
}


int main(){
    int arr1[6]={1,3,4,4,5,7};
    int arr2[6]={2,3,4,4,7,9};
    vector<int> ans=intersection(arr1, arr2) ;
    cout <<"no of intersections---> " <<ans.size()<<endl;
    cout << "intersection elements in array are---> " ;
    for (int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
} 