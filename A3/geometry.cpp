#include "geometry.h"
#include <stdlib.h>
#include <cmath>
#include <iostream>

//default constructor
PointArray::PointArray(){
    size=0;
    points=new Point[0];
}

//constructor
PointArray::PointArray(const Point pts[], const int copysize){
    size=copysize;
    points=new Point[size];
    for(int i=0;i<size;i++){
        points[i]=pts[i];
    }
}

//copy
PointArray::PointArray(const PointArray &someArray){
    size=someArray.size;
    points=new Point[size];
    for(int i=0;i<size;i++){
        points[i]=someArray.points[i];
    }
}

PointArray::~PointArray()
{
    delete[] points;
}

void PointArray::resize(int newSize){
    Point *pts= new Point[newSize];
    int minSize = ( newSize > size ? size : newSize );
    for(int i = 0; i<minSize; i++){
        pts[i]=points[i];
    }
    delete[] points;
    size=newSize;
    points=pts;
}

void PointArray::clear(){
    resize(0);
}

void PointArray::push_back(const Point &p){
    resize(size+1);
    points[size-1]=p;
}

void PointArray::insert(const int pos, const Point &p){
    resize(size+1);

    for(int i=size-1;i<pos;i--)
    {
        points[i]=points[i-1];
    }
    points[pos]=p;
}


void PointArray::remove(const int pos){
    if( pos >= 0 && pos < size ) { 

    for(int i = pos; i < size - 2; i++) {
        points [i] = points [i + 1];
    }
    resize ( size - 1);
    }
}

Point *PointArray::get(const int pos) {
    return pos>=0 && pos < size ? points + pos : NULL;
}

const Point *PointArray::get( const int pos) const {
    return pos >= 0 && pos < size ? points + pos : NULL;
}

int Polygon::polygon_count=0;

Polygon::Polygon(const PointArray &pa) : points(pa) {
    polygon_count++;
}

Polygon::Polygon(const Point array[], const int numPoints) : points(array,numPoints){
    polygon_count++;
}


Point constructorPoints [4];

Point * updateConstructorPoints ( const Point &p1 , const Point &p2 ,
const Point &p3 , const Point &p4 = Point (0 ,0)) {
constructorPoints [0] = p1;
constructorPoints [1] = p2;
constructorPoints [2] = p3;
constructorPoints [3] = p4;
return constructorPoints ;
}

Rectangle::Rectangle(const Point &lower_left, const Point &top_right) :
    Polygon(updateConstructorPoints(lower_left, Point(lower_left.getX(),top_right.getY()), top_right, Point(top_right.getX(),lower_left.getY())),4) {}

Rectangle::Rectangle(const int lower_left_x, const int lower_left_y,const int top_right_x, const int top_right_y):
    Polygon(updateConstructorPoints(Point(lower_left_x,lower_left_y), Point(lower_left_x, top_right_y),Point(top_right_x,top_right_y),Point(top_right_x,lower_left_y)),4) {}


double Rectangle::area() const {
    int length = points.get(1)->getY() - points.get(0)->getY();
    int width =  points.get(2)->getX() - points.get(1)->getX();
    return std::abs((double)length * width);
}

Triangle::Triangle(const Point &p1, const Point &p2,const Point &p3) :
    Polygon(updateConstructorPoints(p1, p2,p3),3) {}

double Triangle::area() const {
    int x0_1 = points.get(0)->getX() - points.get(1)->getX(),
        x1_2 = points.get(1)->getX() - points.get(2)->getX(),
        x2_0 = points.get(2)->getX() - points.get(0)->getX();
    int y0_1 = points.get(0)->getY() - points.get(1)->getY(),
        y1_2 = points.get(1)->getY() - points.get(2)->getY(),
        y2_0 = points.get(2)->getY() - points.get(0)->getY();

    double a = std::sqrt(x0_1 * x0_1 +y0_1 * y0_1),
           b = std::sqrt(x1_2 * x1_2 + y1_2 * y1_2),
           c = std::sqrt(x2_0 * x2_0 + y2_0 * y2_0);

    double s = (a+b+c)/2;

    return std::sqrt(s*(s-a)*(s-b)*(s-c));
}


void printAttributes(Polygon *p) {
    std::cout<<"Area: "<<p->area()<<"\n";

    const PointArray *pa = p->getPoints();

    for(int i=0; i<pa->getSize();++i) {
        std::cout<<"("<<pa->get(i)->getX()<<" , "<<pa->get(i)->getY()<<")\n";
    }

}



int main() {
    // Recatngle
    int lower_left_x = 0;
    int lower_left_y = 0;
    int top_right_x = 0;
    int top_right_y = 0;

    std::cout<<"Lower left (X,Y)";
    std::cin>>lower_left_x;
    std::cin>>lower_left_y;

    Point lower_left = Point(lower_left_x,lower_left_y);

    std::cout<<"Top Right (X,Y)";
    std::cin>>top_right_x;
    std::cin>>top_right_y;

    Point top_right = Point(top_right_x,top_right_y);
    Rectangle rect = Rectangle(lower_left,top_right);

    printAttributes(&rect);

    // Triangle
    int p1_x = 0;
    int p1_y = 0;
    int p2_x = 0;
    int p2_y = 0;
    int p3_x = 0;
    int p3_y = 0;

    std::cout<<"P1 (X,Y)";
    std::cin>>p1_x;
    std::cin>>p1_x;
    Point P1 = Point(p1_x,p1_x);

    std::cout<<"P2 (X,Y)";
    std::cin>>p2_x;
    std::cin>>p2_y;
    Point P2 = Point(p2_x,p2_y);

    std::cout<<"P3 (X,Y)";
    std::cin>>p3_x;
    std::cin>>p3_y;
    Point P3 = Point(p3_x,p3_x);

    Triangle tri = Triangle(P1,P2,P3);
    printAttributes(&tri);

}