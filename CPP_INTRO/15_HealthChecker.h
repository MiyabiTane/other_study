using namespace std;

// メンバ変数のみ▷struct
// メンバ関数＋メンバ変数▷class
class HealthChecker {
    private:
        static const int STD_BMI;  // staticを指定すること全てのでインスタンスから共有される。無駄にメモリを食わない。
        string name;
        double height;
        double weight;
        double bmi;

    public:
        static int getStdBmi();
        double getStdWeight();  // 標準BMIを返すメンバ変数
        double getBmi();  //BMIを返すメンバ関数
        // private変数なのでthis.nameのような呼び出し方ができない
        string getName();  //氏名を返すメンバ関数
        HealthChecker(string name, double height, double weight);  // コンストラクタ
};
