#include<iostream>
#include <vector>
using namespace std;

vector<int> multipication(int arr[],int n){
    vector<int> ans1;
    for (int i=0;i<n;i++){
        int j=0;
        int ans=1;
        while(j<n){
            if (i!=j){
                ans = ans * arr[j];
                j++;
            }
            else
            {
                j++;
            }
            
        }
         ans1.push_back(ans);
    }return ans1;
}

int main (){
    int size,arr[size];
    cout <<" enter size of array  "<< endl;
    cin >> size;
    for (int i =0;i<size; i++){
        cout << " enter element " << i+1 << " ";
        cin >> arr[i];
    }
    vector<int> arrfinal=multipication(arr,size);
    for (int i=0; i<size;i++){
        cout<< arrfinal[i]<< " ";
    }
}