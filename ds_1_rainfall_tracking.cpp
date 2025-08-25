#include <iostream>
using namespace std;

int main(){
	int rainfall[3][4];
	float avg;
	for(int i =0;i<3;i++){
		cout<<"\nEnter rainfall data for city: "<<i+1<<"\n";
		for(int j=0;j<4;j++){
		cout<<"Enter rainfall data for "<<j+1<<" month: ";
		cin>>rainfall[i][j];			
		}
	}
	cout<<"\nRainfall data: \n";
	cout<<"\ncity\tMonth 1\tMonth 2\tMonth 3\tMonth 4\tavg "<<endl;
    for(int i =0;i<3;i++){
		float sum=0;
		cout<<"city "<<i+1<<"\t";
		for(int j =0;j<4;j++){
		cout<<rainfall[i][j]<<"\t";
		sum+=rainfall[i][j];
	}
	avg=sum/4;
	cout<<avg<<endl;
}
return 0;
}