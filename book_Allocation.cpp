#include <iostream>
using namespace std;

bool isPossible (int arr[],int n,int m,int mid){
    int student=1;         //such that we can increase student in if condition 
    int pagecount =0;
    for (int i=0;i<n;i++){
        if (pagecount + arr[i]<=mid){
            pagecount+=arr[i];
        }
        else {
            student ++;
            if (arr[i]>mid || student >m){
                return false;
            } 
            pagecount =arr[i];
        }
    }return true;
}

int bookAllocation (int arr[],int m,int n){
    int s=0;
    int sum=0;
    for (int i=0; i<n;i++)
    {
        sum+=arr[i];
    }
    int e=sum;
    int ans =-1;
    int mid = s+(e-s)/2;

    while(s<=e){
        if (isPossible(arr,n,m,mid)){
            ans =mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }return ans;
}

int main(){
    int n,m,arr[n];
    cout <<"enter size of array " ;
    cin >> n;
    cout << "enter no of student ";
    cin >> m;
    for (int i=0;i<n;i++){
        cout << "enter page count "<< i+1<<endl;
        cin >> arr[i];
    }
    int ans = bookAllocation(arr,m,n);
    cout << "maximum no of pages allocated for minimum combination "<<ans;

}