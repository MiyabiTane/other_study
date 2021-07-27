using namespace std;

// 健康診断のデータを格納する構造体
struct HealthData {
    string name;
    double height;
    double weight;
    double bmi;
};

double getBmi_func(double height, double weight);  //8_getBmi.cppより
double getBmi_struct(const HealthData *phc);
