#include <iostream>
using namespace std;

int main ()
{
bool run = true;
int N;

while(run)
{
cin >> N;
if(N<0)
{
    cout<<"Goodbye!";
    return 0;

}
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