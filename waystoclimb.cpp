#include <iostream >
using namespace std;

int ways(int nstair ){
    if (nstair<0){
        return 0;
    }
    if (nstair==0){
        return 1;
    }
    int steps=ways(nstair -1)+ways(nstair -2);
    return steps;
}
int main(){
    int n;
    cout << "enter the no :"<< endl;
    cin >> n;
    int steps=ways(n);
    cout << steps; 
}