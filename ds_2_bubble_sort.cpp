#include <iostream>
using namespace std;
class Bubble{
	public:
	int n;
	int players[20];
	void fun()
{
	cout<<"Enter the total number of players ";
	cin>>n;
	cout<<"Enter the Scores :\n";
	for(int i=0;i<n;i++){
		cout<<"Score "<<i+1<<" : ";
		cin>>players[i];
	}
	cout<<"\nStarting Level up process by Bubble Sort !!!\n";
	cout<<"\nThe Scores entered by players before sorting are ";
	for(int i=0;i<n;i++){
		cout<<players[i]<<" ";
	}
	int temp=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(players[j]>players[j+1]){
				cout<<"\n\nSwapping scores "<<players[j]<<" with "<<players[j+1]<<" - (Levelling Up) !";
				temp=players[j];
				players[j]=players[j+1];
				players[j+1]=temp;
			}
		}
	}
	cout<<"\n\nThe Scores entered by players after sorted are ";
	for(int i=0;i<n;i++){
		cout<<"\nScore "<<i+1<<" : "<<players[i]<<endl;
	}
}
};
int main(){
	Bubble obj;
	obj.fun();
	return 0;
}
