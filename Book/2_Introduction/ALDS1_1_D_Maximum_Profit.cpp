#include<iostream>
#include<algorithm>
using namespace std;
static const int MAX = 200000;

int main(){
    int lst[MAX], n, i;
    int max_profit = -100000000;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> lst[i];
    }
    int min_ = lst[0];
    for (int i = 1; i < n; i++){
        if (lst[i] - min_ > max_profit){
            max_profit = lst[i] - min_;
        }
        if (lst[i] < min_){
            min_ = lst[i];
        }
    }
    cout << max_profit << endl;
    return 0;
}