class Point {
    private:
        double x;
        double y;
    public:
        Point(double z = 0, double y = 0);  // コンストラクタ
        double getX();
        double getY();
        Point operator+(const Point &p);  // +演算子のオーバーロード
        Point operator-(const Point &p);  // -演算子のオーバーロード
        bool operator==(const Point &p);  // ==演算子のオーバーロード
        bool operator!=(const Point &p);  // !=演算子のオーバーロード
        // フレンド関数：メンバ関数ではないが、private変数にアクセスできる関数
        friend istream &operator>>(istream &is, Point &p);  // >>演算子のオーバーロード
        friend ostream &operator<<(ostream &os, const Point &p); // <<演算子のオーバーロード
};

