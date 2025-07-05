#include<iostream>
using namespace std;
// int get_max( int arr[],int n)
// {
//     int max=INT_MIN;
//     for (int i=0;i<n;i++)
//     {
//         if (arr[i]>max)                                              //max value in array
//         {
//             max=arr[i];
//         }
//     }
//     return max;
// }
// int get_min( int arr[],int n)
// {
//     int min=INT_MAX;
//     for (int i=0;i<n;i++)
//     {                                                                 //min value in array
//         if (arr[i]<min)
//         {
//             min=arr[i];
//         }
//     }
//     return min;
// }
// int main ()
// {
//     int n,arr[n]; 
//     cout<< "enter size of array"<< endl;
//     cin >> n;
//     for (int i=0;i<n;i++)
//     {
//         cout << "enter value"<< i+1<<"  ";                             //dynamic initialization
//         cin >> arr[i];
//     }
//     int c=get_max(arr,n);
//     int d=get_min(arr,n);
//     cout<< "maximum value is :"<< endl << c << endl;
//     cout<< "minimum value is :"<< endl << d;  
//     return 0;
// } 
// int sum(int arr[], int n){
//     int sum_=0;
//     for (int i=0;i<n;i++)
//     {
//         sum_+=arr[i];
//     }                                                           //sum of all the elements in an array
//     return sum_;
// }
// int main ()
// {
//     int n,arr[n]; 
//     cout<< "enter size of array"<< endl;
//     cin >> n;
//     for (int i=0;i<n;i++)
//     {
//         cout << "enter value"<< i+1<<"  ";                
//         cin >> arr[i];
//     }  
//     int c=sum(arr,n);
//     cout<< "sum of all the elements in array is:"<< endl<<c; 
// }



// bool linear(int arr[],int n,int key)
// {
//    for (int i=0;i<n;i++){
//     if(arr[i]==key)
//     {
//        return 1;
//     }
//    }
//    return 0;
// }
// int main ()
// {
//     int n,arr[n],key; 
//     cout<< "enter size of array"<< endl;
//     cin >> n;
//     for (int i=0;i<n;i++)
//     {
//         cout << "enter value"<< i+1<<"  ";                //linear search
//         cin >> arr[i];
//     }
//     cout<< endl;
//     cout << "enter element to be searched :";
//     cin >> key;
//     int c=linear(arr,n,key) ;
//     if (c==true){
//         cout<< "key is present (:<)";
//     }
//     else
            
//     {
//        cout<<"key is absent (:<(";
//     }
//     return 0;
// }
// void swap_array( int arr[], int n)
// {
//     int start=0,end=n-1;
//     for(int i=0;start<end;i++)
//     {
//         int temp=arr[start];
//         arr[start]=arr[end];
//         arr[end]=temp;
//         start++;                              //swapping any array
//         end--;
//     }
//     for (int i=0;i<n;i++)
//     {
//         cout << arr[i]<< "  ";
//     }
// }
    
// int main ()
// {
//     int n,arr[n],key; 
//     cout<< "enter size of array"<< endl;
//     cin >> n;
//     for (int i=0;i<n;i++)
//     {
//         cout << "enter value"<< i+1<<"  ";               
//         cin >> arr[i];
//     }
//     for (int i=0;i<n;i++)
//     {
//         cout << arr[i]<< "  ";
//     }
//     cout<<endl;
//     swap_array(arr,n);

// }
// void swap_alt(int arr[],int n){
//     if (n%2==0){
//         for(int i=0;i<n;i+=2)
//         {
//             int temp=arr[i];
//             arr[i]=arr[i+1];
//             arr[i+1]=temp;
//         }
//     }
//     else
//     {
//       for(int i=0;i<n-1;i+=2)
//     {
//         int temp=arr[i];                                           //swapping in alternate keys
//         arr[i]=arr[i+1];
//         arr[i+1]=temp;
//     }  
//     }
//     for (int i=0;i<n;i++)
//     {
//         cout << arr[i]<< "  ";
//     }
// }
// int main ()
// {
//     int n,arr[n],key; 
//     cout<< "enter size of array"<< endl;
//     cin >> n;
//     for (int i=0;i<n;i++)
//     {
//         cout << "enter value"<< i+1<<"  ";               
//         cin >> arr[i];
//     }
//     for (int i=0;i<n;i++)
//     {
//         cout << arr[i]<< "  ";
//     }
//     cout<<endl;
//     swap_alt(arr,n);

// }
// int unique(int arr[],int n){
//     int ans=0;
//     for (int i=0;i<n;i++)
//     {
//         ans = ans^arr[i];
//     }
//     return ans;
// }                                             //unique value in 2m+1 array where only one value is unique
// int main()
// {
//     int n,arr[n],key; 
//     cout<< "enter size of array"<< endl;
//     cin >> n;
//     for (int i=0;i<n;i++)
//     {
//         cout << "enter value"<< i+1<<"  ";               
//         cin >> arr[i];
//     }
//     int x= unique(arr,n);
//     cout <<"unique value in array is :"<< endl << x ;  
    
// }

int no_of_unique(int arr[],int n){
    int count=1;
    int j;
    for (int i=1;i<n;i++)
    {
        for (j=0;j<i;j++)
        {
            if (arr[i]==arr[j])
            {
                break;              //to stop iteration in this loop
            }   
        }
        if(i==j){
            count+=1;               //whenever i!=j count value stays same 
        }                                              
}                                                         //no of distinct values
    return count;
}               
int main()
{
    int n,key; 
    cout<< "enter size of array"<< endl;
    cin >> n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cout << "enter value"<< i+1<<"  ";               
        cin >> arr[i];
    }
    int x= no_of_unique(arr,n);
    cout <<" no of unique values in array  :"<< endl << x ;  
    
}
// int main(){
//     int n,m;
//     cout<< "enter the size of array1"<<endl;
//     cin>> m;
//     int arr1[m];
//     for (int i=0;i<m;i++)
//     {
//         cout << "enter element no :"<< i+1<< "  ";
//         cin>> arr1[i];
//     }
//     cout <<"array1 " << "  ";
//     for ( int i=0;i<m;i++){
//         cout<< arr1[i]<<" ";
//     }
//     cout<<endl;
//     cout<< "enter the size of array2"<<endl;
//     cin>> n;
//     int arr2[n];
//     for (int i=0;i<n;i++){
//         cout << "enter element no :"<< i+1<< "  ";
//         cin>> arr2[i];
//     }
    
//     cout << "array2" << "  ";
//     for ( int i=0;i<m;i++){
//         cout<< arr2[i]<<" ";
//     }
//      return 0;
// }
