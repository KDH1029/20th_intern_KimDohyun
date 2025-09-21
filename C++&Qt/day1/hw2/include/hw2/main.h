namespace dohyun
{
    class Points
    {
    private:
        int *x, *y;
        int min, max;
        int min_coor[2], max_coor[2];

    public:
        void set_x(int i, int n);
        void set_y(int i, int n);

        void dist(int j, int k);

        int get_min(void);
        int get_max(void);

        int get_min(int i);
        int get_max(int i);

        int get_x(int i);
        int get_y(int i);

        Points(int i);
        ~Points();
    };

    void Points::set_x(int i, int n)
    {
        this->x[i] = n;
    }
    void Points::set_y(int i, int n)
    {
        this->y[i] = n;
    }
    void Points::dist(int j, int k)
    {
        int dist = (this->x[j] - this->x[k]) * (this->x[j] - this->x[k]) + (this->y[j] - this->y[k]) * (this->y[j] - this->y[k]);
        if (j == 0 && k == 1)
        {
            this->min = dist;
            this->min_coor[0] = j;
            this->min_coor[1] = k;
            this->max = dist;
            this->max_coor[0] = j;
            this->max_coor[1] = k;
        }
        else
        {
            if (dist < this->min)
            {
                this->min = dist;
                this->min_coor[0] = j;
                this->min_coor[1] = k;
            }
            if (dist > this->max)
            {
                this->max = dist;
                this->max_coor[0] = j;
                this->max_coor[1] = k;
            }
        }
    }
    int Points::get_min(void)
    {
        return this->min;
    }
    int Points::get_max(void)
    {
        return this->max;
    }
    int Points::get_min(int i)
    {
        return this->min_coor[i];
    }
    int Points::get_max(int i)
    {
        return this->max_coor[i];
    }
    int Points::get_x(int i)
    {
        return this->x[i];
    }
    int Points::get_y(int i)
    {
        return this->y[i];
    }

    Points::Points(int i)
    {
        this->x = new int[i];
        this->y = new int[i];
    }
    Points::~Points()
    {
        delete[] this->x;
        delete[] this->y;
    }
}