#include <iostream>

int array[]={1,2,2,3,4,5};
//6.1
void printArray(int array[],int length)
{
    for(int i=0;i<length;++i)
    {
        if(i==(length-1))
        {
            std::cout<<array[i];  
        }
        else
        {
            std::cout<<array[i]<<", ";
        }
    }
}

//6.2
void reverse(int arr[],int length)
{
    int temparray[length];

    for(int i=0;i<length;++i)
    {
        temparray[i]=(arr[length-1-i]);
    }
    for(int i=0;i<length;++i)
    {
        array[i]=temparray[i];
    }
}

//6.3
const int LENGTH = 4;
const int WIDTH = 5;
void transpose ( const int input [][LENGTH] , int output [][WIDTH]) {
    for(int i = 0; i < WIDTH ; ++ i ) {
        for (int j = 0; j < LENGTH ; ++ j ) 
        {
            output [ j ][ i ] = input [ i ][ j ];
        }   
    }
}
 
 //6.5
void reverse2(int *arr, int length) {
    int tempArray[length];

    for (int i = 0; i < length; ++i) {
        *(tempArray + i) = *(arr + (length - 1 - i));  

    for (int i = 0; i < length; ++i) {
        *(arr + i) = *(tempArray + i);
    }
}
}

int main() {
    // printArray(array,6);
    reverse2(array,6);
    printArray(array,6);

}