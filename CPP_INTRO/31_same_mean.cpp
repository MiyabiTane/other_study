#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main() {
    char s1[] = "abcdefg";
    char s2[] = "abcdefg";
    if (strcmp(s1, s2) == 0) {
        cout << "等しい" << endl;
    } else {
        cout << "等しくない" << endl;
    }

    // 上記と同様の内容を==演算子で書く
    string s3 = "abcdefg";
    string s4 = "abcdefg";
    if (s3 == s4) {
        cout << "等しい" << endl;
    } else {
        cout << "等しくない" << endl;
    }

    return 0;
}
