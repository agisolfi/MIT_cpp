#include <iostream>

//4.1
int int_sum(const int x, const int y) {
    return x+y;
}

//4.1
double double_sum(const double x, const double y) {
    return x+y;
}

//4.3 & 4.4
int int_multiple_sum(const int x, const int y,const int z=0, const int a=0) {
    return x+y+z+a;
}

//4.3
double double_multiple_sum(const double x, const double y,const double z=0, const double a=0) {
    return x+y+z+a;
}

//4.5
int arb_int_sum(const int numbers[], const int length)
{
    int sum=0;
    for(int i=0;i<length;++i){
        sum+=numbers[i];
    }
    return sum;
}

//4.6
int rec_int_sum(const int numbers[], const int length)
{
   return length==0 ? 0 : numbers[0]+ rec_int_sum(numbers+1, length-1);
}


int main() {
    std::cout<<int_sum(2,3)<<"\n";
    std::cout<<double_sum(2.2,3.0)<<"\n";;

    std::cout<<int_multiple_sum(2,3,4)<<"\n";

    int numbers[]={1,2,3,4,5,6};
    std::cout<<arb_int_sum(numbers,6)<<"\n";
    std::cout<<rec_int_sum(numbers,6)<<"\n";


    
}