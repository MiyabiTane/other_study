#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
int cnt=0;
vector<int> G;

void insertionSort(int lst[], int n, int g){
    int i, j, v;
    for (i=g; i<n; i++){
        v = lst[i];
        j = i - g;
        while (j >= 0 && lst[j] > v){
            lst[j+g] = lst[j];
            j -= g;
            cnt++;
        }
        lst[j+g] = v;
    }
}

void shellSort(int lst[], int n){
    int h = 1, i;
    while (true){
        if (h>n) break;
        G.push_back(h);
        h = 3*h + 1;
    }
    for (i=G.size()-1; i>=0; i--){
        insertionSort(lst, n, G[i]);
    }
}

int main(){
    int i;
    int n, lst[1000000];
    cin >> n;
    for (i=0; i<n; i++) scanf("%d", &lst[i]);

    shellSort(lst, n);

    cout << G.size() << endl;
    for (i=G.size()-1; i>=0; i--){
        if (i == 0) printf("%d\n", G[i]);
        else printf("%d ", G[i]);
    }
    cout << cnt << endl;
    for (i=0; i<n; i++){
        printf("%d\n", lst[i]);
    }
}
