#include <iostream>
using namespace std;
int main(){
float temperature[3][7];
float avg;
for(int i =0;i<3;i++){
cout<<"\nEnter temperature data for city: "<<i+1<<"\n";
for(int j=0;j<7;j++){
cout<<"Enter temperature data for day "<<j+1<<" of the week: ";
cin>>temperature[i][j];
}
}
cout<<"\nTemperature data of 3 cities for whole week: \n";
cout<<"\ncity\tDay 1\tDay 2\tDay 3\tDay 4\tDay 5\tDay 6\tDay 7\tAverage "<<endl;
for(int i =0;i<3;i++){
float sum=0;
cout<<"city "<<i+1<<"\t";
for(int j =0;j<7;j++){
cout<<temperature[i][j]<<"\t";
sum+=temperature[i][j];
}
avg=sum/7;
cout<<avg<<endl;}
cout << "Day Avg";
for (int j = 0; j < 7; j++) {
float daySum = 0;
for (int i = 0; i < 3; i++) {
daySum += temperature[i][j];
}
float dayAvg = daySum / 3.0;
cout << dayAvg << "\t";
}
return 0;
}
