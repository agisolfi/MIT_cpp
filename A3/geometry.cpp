#include <geometry.h>

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
    
}

