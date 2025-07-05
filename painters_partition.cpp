#include<iostream>
using namespace std; 
bool ispossible (int arr[],int m,int n,int mid){
    int painters =1;
    int wallcount =0;
    for (int i=0;i<n;i++){
        if (arr[i]+wallcount <=mid){
            wallcount +=arr[i];
        }
        else{
            painters++;
            if (arr[i]>mid || painters>m){
                return false ;
            }
            wallcount = arr[i];
        }
    }return true;
}

int partition(int arr[],int m,int n){
    int s=0;
    int sum=0;
    for (int i=0;i<n;i++){
        sum+=arr[i];
    }
    int end=sum;
    int ans =-1;
    int mid=s+(end-s)/2;
    
    while (s<=end){
        if (ispossible(arr,m,n,mid)){
           ans = mid;
           end = mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(end-s)/2;
    }return ans;
}
int main(){
int n,m,arr[n];
    cout <<"enter no of rooms " ;
    cin >> n;
    cout << "enter no of painters ";
    cin >> m;
    for (int i=0;i<n;i++){
        cout << "enter wallcount "<< i+1<<endl;
        cin >> arr[i];
    }
    int ans = partition(arr,m,n);
    cout << "maximum no of walls assigned for minimum time "<< endl << ans;
}