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
if(N%5==0)
    {
    val = N/5;
    }
else 
    {
    continue;
    }
cout<<"Value:"<<val<<"\n";
}
}