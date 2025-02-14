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

class Polygon{
    protected:
        PointArray points;
        static int polygon_count;

    public:
        Polygon(const PointArray &pa);
        Polygon(const Point points[], const int numPoints);
        ~Polygon() {--polygon_count;}

        virtual double area() const = 0;
        static int getNumPolygons() {return polygon_count;}
        int getNumSides() const {return points.getSize();}
        const PointArray *getPoints() const {return &points;}
};

class Rectangle : public Polygon {

    public:
        Rectangle(const Point &a, const Point &b);
        Rectangle(const int a, const int b, const int c, const int d);
        virtual double area() const;
};

class Triangle: public Polygon {
    public:
        Triangle(const Point &a, const Point &b, const Point &c);
        virtual double area() const;

};