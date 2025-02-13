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
    int temp = *ptr1;
    *ptr1=*ptr2;
    *ptr2=temp;
    std::cout<<*ptr1<<"\n"<<*ptr2;
}

//7.5
void multistep()
{
    char *oddOrEven = "Never odd or even ";
    char *nthCharPtr = &oddOrEven[5]; //1
    std::cout<<*nthCharPtr<<"\n"; //1

    nthCharPtr -= 2; //2
    std::cout<<*nthCharPtr<<"\n"; //3

    char ** pointerPtr = &nthCharPtr; //4
    std::cout<<*pointerPtr<<"\n"; //5

    std::cout<<**pointerPtr<<"\n"; //6

    nthCharPtr += 1; //7

    std::cout<<nthCharPtr - oddOrEven; //8
    

}


int main() {
    const char *phrase = "bar";
    std::cout<<length(phrase);
    int x = 3;
    int y = 6;
    swap_by_pointers(&x,&y);

    int *ptr1 = &x;
    int *ptr2 = &y;
    swap_by_pointers2(ptr1,ptr2);

    multistep();
    


}