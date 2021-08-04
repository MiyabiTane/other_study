using namespace std;

class AccountEx : public Account {
    protected:
        string name;  // 口座名義人
    public:
        string getName();
        AccountEx(string number, string name, int balance);

};
