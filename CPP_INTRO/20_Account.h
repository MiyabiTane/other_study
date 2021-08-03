using namespace std;

class Account {
    protected:
        string number;  // 口座番号
        int balance;  // 残高
    public:
        string getNumber();  // 口座番号を返す
        int getBalance();  // 残高を返す
        void setBalance(int balance);  // 残高を設定する
        Account(string number, int balance);  // コンストラクタ
};
