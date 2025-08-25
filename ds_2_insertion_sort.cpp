#include <iostream>
using namespace std;
class insertion{
public:
int t;
int key;
int player[20];
void fun() {
int j;
cout << "\nSorting of cards by Insertion Sort\n";
cout << "\nEnter the total number of players: ";
cin >> t;
cout << "Enter the numbers:\n";
for (int i = 0; i < t; i++) {
cin >> player[i];
}
cout << "The numbers entered by players before sorting are: ";
for (int i = 0; i < t; i++) {
cout << player[i] << " ";
}
for (int i = 1; i < t; i++) {
key = player[i];
j = i - 1;
while (j >= 0 && player[j] > key) {
player[j + 1] = player[j];
j = j - 1;
}
player[j + 1] = key;
}
cout << "\nThe numbers after sorting of cards are: ";
for (int i = 0; i < t; i++) {
cout << player[i] << " ";
}
}
};
int main() {
insertion obj;
obj.fun();
return 0;
}
