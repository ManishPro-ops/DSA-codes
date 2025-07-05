#include <iostream>
using namespace std;
// int bsearch( int arr[],int key){
//     int start=0;
//     int end=5,ans=-1;
//     int mid=start+(end-start)/2 ;
//     while(start<=end){
//         if (arr[mid]>key)
//         {
//             end=mid-1;                                                               //binary_search
//         }
//         else if (arr[mid]==key)
//         {
//             int ans= mid;
//             return ans;
//         }
//         else if (arr[mid]<key){
//             start=mid+1;
//         }
//         mid=start+(end-start)/2 ;
//     }
//     return ans;
// }

// int main(){
//     int arr[6]={1,2,3,3,4,4};
//     int key;
//     cout<< "enter key to search "<<endl;
//     cin>> key;
//     int x=bsearch(arr,key);
//     cout << "key value is at index ---> "<< x;
// }
// int first_occ( int arr[],int key){
//     int start=0;
//     int end=5,ans=-1;
//     int mid=start+(end-start)/2 ;
//     while(start<=end){
//         if (arr[mid]==key){
//             ans=mid;
//             end=mid-1;                                //first and last occurences in any sorted array
//         }
//         else if (arr[mid]>key){
//             end=mid-1;
//         }
//         else if (arr[mid]<key){
//             start=mid+1;
//         }
//         mid=start+(end-start)/2 ;
//     }return ans;
//     }

// int last_occ( int arr[],int key){
// int start=0;
// int end=5,ans=-1;
// int mid=start+(end-start)/2 ;
// while(start<=end)
// {
//     if (arr[mid]==key){
//         ans=mid;
//         start=mid+1;
//     }
//     else if (arr[mid]>key){
//         end=mid-1;
//     }
//     else if (arr[mid]<key){
//         start=mid+1;
//     }
//     mid=start+(end-start)/2 ;
// }
// return ans;
// }
    
// int main(){
//     int arr[6]={1,2,3,3,4,4};
//     int key;
//     cout<< "enter key to search "<<endl;
//     cin>> key;
//     int x=first_occ(arr,key);
//     int y=last_occ(arr,key);
//     int z=(y-x)+1;                                                      //no of occurence
//     cout << "first occurence is at index---> "<< x<< endl;
//     cout << "last occurence is at index---> "<< y<< endl;
//     cout << "no of occurence is ----> "<< z;
//  } 

// int peak_value(int arr[]){
//     int s=0;
//     int e=5;
//     int m=s+(e-s)/2;
//     while(s<e){                                                          //peak value for any array
//         if (arr[m]<arr[m+1])
//         {
//             s=m+1;
//         }
//         else
//         {
//            e=m;
//         }
//         m=s+(e-s)/2;
//     }
//     return s;
// }
// int main(){
//     int arr[6]={1,2,17,14,6,5};
//     int x=peak_value(arr);
//     cout << "peak value for given array is at index---> "<< x << endl;
//     cout << "its value is ---> "<< arr[x];
// }

