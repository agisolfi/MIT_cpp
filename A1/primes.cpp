#include <iostream>
using namespace std;

int main ()
{
int N ;
cin >> N ;
for(int i = 2; N > 0; ++ i )
{
bool prime = true ; 
for (int j = 2; j < i ; ++ j )
{
if(i % j == 0)
    {
    prime = false ;
    break ;
    }
}
if( prime )
    {
    --N ;
    cout << i << " \n ";
    }
 }
 return 0;
}