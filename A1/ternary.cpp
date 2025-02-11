#include <iostream>
using namespace std;

int main ()
{
bool run = true;
int N;

while(run)
{
cin >> N;
int val;
val = (N%5==0)?N/5:-1;
cout<<"Value:"<<val<<"\n";
}
}