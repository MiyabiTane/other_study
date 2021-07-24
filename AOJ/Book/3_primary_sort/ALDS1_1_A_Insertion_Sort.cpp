#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

void trace(int lst[], int n){
    int i;
    for (i=0; i<n; i++){
        if (i == n-1){
            printf("%d\n", lst[i]);
        }else{
            printf("%d ", lst[i]);
        }
    }
}

int main(){
    int n, i, j, v;
    int lst[100];

    cin >> n;
    for (i = 0; i < n; i++){
        cin >> lst[i];
    }
    trace(lst, n);

    for (i = 1; i < n; i++){
        j = i - 1;
        v = lst[i];
        while (j >= 0 && lst[j] > v){
            lst[j+1] = lst[j];
            j -= 1;
        }
        lst[j+1] = v;
        trace(lst, n);
    }
}
