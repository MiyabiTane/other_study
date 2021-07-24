#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct Card {
    char mark, number;
};

void bubbleSort(Card lst[], int n){
    int i, j;
    for (i=0; i<n; i++){
        for (j=n-1; j>i; j--){
            if (lst[j].number < lst[j-1].number){
                swap(lst[j], lst[j-1]);
            } 
        }
    }
}

void selectionSort(Card lst[], int n){
    int i, j, minj;
    for (i=0; i<n; i++){
        minj = i;
        for (j=i+1; j<n; j++){
            if (lst[j].number < lst[minj].number){
                minj = j;
            }
        }
        if (minj != i) swap(lst[i], lst[minj]);
    }
}

bool stableCheck(Card lst[], Card new_lst[], int n){
    int i;
    for (i=0; i<n; i++){
        if (lst[i].mark != new_lst[i].mark){
            cout << "Not stable" << endl;
            return false;
        }
    }
    cout << "Stable" << endl;
    return true;
}

void trace(Card lst[], int n){
    int i;
    for (i=0; i<n; i++){
        if (i == n-1){
            cout << lst[i].mark << lst[i].number << endl;
        }
        else cout << lst[i].mark << lst[i].number << " ";
    }
}
    
int main(){
    int n, i;
    Card lst_1[100], lst_2[100];
    cin >> n;
    for (i=0; i<n; i++){
        cin >> lst_1[i].mark >> lst_1[i].number;
    }
    for (i=0; i<n; i++){
        lst_2[i] = lst_1[i];
    }

    bubbleSort(lst_1, n);
    trace(lst_1, n);
    cout << "Stable" << endl;

    selectionSort(lst_2, n);
    trace(lst_2, n);
    stableCheck(lst_1, lst_2, n);
}
