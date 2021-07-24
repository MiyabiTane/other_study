#include <iostream>
#include <string>
using namespace std;

int main() {
    int channel;
    string stationName;

    cout << "チャンネル名を入力してください: ";
    cin >> channel;

    switch (channel) {
        case 1:
            stationName = "NHK総合";
            break;
        case 3:
            stationName = "NHK教育";
            break;
        case 4:
            stationName = "日本テレビ";
            break;
        case 6:
            stationName = "TBSテレビ";
            break;
        case 8:
            stationName = "フジテレビ";
            break;
        case 10:
            stationName = "テレビ朝日";
            break;
        case 12:
            stationName = "テレビ東京";
            break;
        default:
            stationName = "割り当てなし";
            break;
    }
    cout << stationName << endl;
    return 0;
}