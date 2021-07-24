#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

void trace(int lst[], int n){
    int i;
    for (i=0; i<n; i++){
        if (i == n-1) printf("%d\n", lst[i]);
        else printf("%d ", lst[i]);
    }
}

int main(){
    int n, i, head, count = 0;
    bool flag;
    int lst[200];
    cin >> n;
    for (i=0; i<n; i++){
        cin >> lst[i];
    }
    //trace(lst, n);

    flag = true;
    head = 0;
    while (flag){
        flag = false;
        for (i=n-1; i>head; i--){
            if (lst[i] < lst[i-1]){
                swap(lst[i], lst[i-1]);
                count++;
                flag = true;
            }
        }
        head ++;
        //trace(lst, n);
    }
    trace(lst, n);
    cout << count << endl;
}