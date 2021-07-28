using namespace std;

// メンバ変数のみ▷struct
// メンバ関数＋メンバ変数▷class
class HealthChecker {
    private:
        string name;
        double height;
        double weight;
        double bmi;

    public:
        double getBmi();  //BMIを返すメンバ関数
        // private変数なのでthis.nameのような呼び出し方ができない
        string getName();  //氏名を返すメンバ関数
        HealthChecker(string name, double height, double weight);  // コンストラクタ
};
