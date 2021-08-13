class MyCircle {
    private:
        double r;
    public:
        MyCircle(double r) {
            this->r = r;
        }
        double getArea() {
            return this->r * this->r * 3.14;
        }
};
