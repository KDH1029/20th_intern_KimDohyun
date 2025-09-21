namespace dohyun
{
    class Numbers
    {
    private:
        int *arr;
        int min, max, sum;

    public:
        void set(int i, int n);
        int get_min(void);
        int get_max(void);
        int get_sum(void);

        Numbers(int i, int n);
        ~Numbers();
    };

    void Numbers::set(int i, int n)
    {
        this->arr[i] = n;
        if (n < this->min)
            this->min = n;
        if (n > this->max)
            this->max = n;
        this->sum += n;
    }
    int Numbers::get_min(void)
    {
        return this->min;
    }
    int Numbers::get_max(void)
    {
        return this->max;
    }
    int Numbers::get_sum(void)
    {
        return this->sum;
    }

    Numbers::Numbers(int i, int n)
    {
        this->arr = new int[i];
        this->arr[0] = n;
        this->min = n;
        this->max = n;
        this->sum = n;
    }
    Numbers::~Numbers()
    {
        delete[] this->arr;
    }
}