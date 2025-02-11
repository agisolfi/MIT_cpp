#include <iostream>
#include <string>
using namespace std;

int main() 
{
string phrase = "Hello, World \n";
int n = 0;
cin>>n;

for (int i = 0;i<=n;i=i+1) {
cout<<phrase;
}

do {
cout<<phrase;
n=n+1;
}
while (n<5);
}