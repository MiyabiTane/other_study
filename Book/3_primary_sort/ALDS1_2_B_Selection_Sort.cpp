#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

void trace(int lst[], int n){
    int i;
    for (i=0; i<n; i++){
        if (i==n-1) printf("%d\n", lst[i]);
        else printf("%d ", lst[i]);
    }
}

int main(){
    int n, i, j, count=0, minj;
    int lst[100];
    // input
    cin >> n;
    for (i=0; i<n; i++){
        cin >> lst[i];
    }
    //sort
    for (i=0; i<n; i++){
        minj = i;
        for (j=i+1; j<n; j++){
            if (lst[j] < lst[minj]){
                minj = j; 
            }           
        }
        if (minj != i){
            swap(lst[i], lst[minj]);
            count++;
        }
    }
    trace(lst, n);
    cout << count << endl;
}