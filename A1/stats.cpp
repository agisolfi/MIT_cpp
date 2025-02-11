 #include <iostream>
 using namespace std;

 int main ()
 {
int N=0;
cout << "Length of List:";
cin>>N;
int array[N];

for (int i=0;i<N;i=i+1) {
    cout << "Enter a number:";
    cin>>array[i];
}
int range = 0;
double mean = 0.0;
int min = array[0];
int max = array[0];

int sum = 0;
for (int number : array) {

    sum += number;
    if(number>max){
        max=number;
    }
    if(number<min) {
        min=number;
    }
}

range = max-min;
mean = sum/N;

cout<<"Mean:"<<mean<<"\n";
cout<<"Max:"<<max<<"\n";
cout<<"Min:"<<min<<"\n";
cout<<"Range:"<<range<<"\n";

 }

