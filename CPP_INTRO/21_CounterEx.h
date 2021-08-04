// 19_Counter.hで定義したCounterクラスをpublic継承
class CounterEx : public Counter {
    public:
        void downVal();  // カウンタの値を減らす
        CounterEx();  // コンストラクタ
};
