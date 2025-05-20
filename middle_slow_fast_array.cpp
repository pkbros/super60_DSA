#include <iostream>
using namespace std;

int main(){

    int arr[] = {1,2,3,4,5};

    int i=-1, j; // bcz i should go to 1 when j goes to 2
    for(j = 0; j < sizeof(arr)/sizeof(arr[0]);j=j+2){
        // cout<<j<<endl;
        i = i + 1;
        // cout<<i<<endl;
    }
    cout<<arr[i];


    return 0;
}