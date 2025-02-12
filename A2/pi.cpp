#include <iostream>
#include <random>
#include <cmath>

int darts_in_circle=0;

double calc_pi(const int n)
{
    double pi = 4*(darts_in_circle/(double)n);
    return pi;
}


int main() {
    int n = 5000000;

    for(int i=0;i<n;++i){
        double x = rand () / ( double ) RAND_MAX, y = rand () / ( double ) RAND_MAX;
        double dsqrd = pow(x,2) + pow(y,2);
        double d = sqrt(dsqrd);
        if(d<=1)
        {
            ++darts_in_circle;
        }
    }

    std::cout<<darts_in_circle<<"\n";
    std::cout<<calc_pi(n)<<"\n";

}