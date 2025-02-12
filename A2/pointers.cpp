#include <iostream>
//7.1
int length(const char *str){
    int str_length=0;
    while(*(str+str_length)!='\0'){
        ++str_length;
    }
    return str_length;
}

//7.2
void swap_by_reference(int &x,int &y){
    int temp = x;
    x=y;
    y=temp;
    std::cout<<x<<"\n"<<y;
}

//7.3
void swap_by_pointers(int *x,int *y){
    int temp = *x;
    *x=*y;
    *y=temp;
    std::cout<<*x<<"\n"<<*y;
}

//7.4
void swap_by_pointers2(int *ptr1,int *ptr2){
    int temp = *x;
    *x=*y;
    *y=temp;
    std::cout<<*x<<"\n"<<*y;
}

int main() {
    // const char *phrase = "bar";
    // std::cout<<length(phrase);
    int x = 3;
    int y = 6;
    // swap_by_pointers(&x,&y);

    int *ptr1 = &x;
    int *ptr2 = &y;


}