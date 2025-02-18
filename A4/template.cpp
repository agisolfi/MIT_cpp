#include <iostream>



template <typename T, typename U> T min(const T a, const T b) {
    if(a<b) {
        return a;
    }
    else
        return b;
}

#define min2(x,y) (x<y?x:y) 

int main() {
    std::cout<<min<int,float>(5,3.0);
}