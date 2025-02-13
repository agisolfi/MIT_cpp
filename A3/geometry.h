class Point
{
    private:
        int x;
        int y;

    public:
        Point(int X=0,int Y=0) {x=X; y=Y;}
        int getX() const {return x;}
        int getY() const {return y;}
        void setX(const int newX) {x=newX;}
        void setY(const int newY) {y=newY;}
};

class PointArray
{
    private:
        Point *points;
        int size;
        
        void resize(int size);

    public:
        PointArray();
        PointArray(const Point points[], const int size);
        PointArray(const PointArray& pv);
        ~PointArray();

        void clear();
        void push_back(const Point &p);
        void insert(const int pos, const Point &p);
        void remove(const int pos);
        int getSize() const {return size;}
        Point *get(const int pos);
        const Point *get(const int pos) const;

};