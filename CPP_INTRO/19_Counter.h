class Counter {
    protected:
        int val;  // カウンタの値を格納
    public:
        void resetVal();
        void upVal();
        int getVal();
        Counter();  // コンストラクタ
};
