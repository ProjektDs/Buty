#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
	ifstream file("ProjektInformatyka.txt");
	
	vector<string>names;

	string input;
	while (file>>input)//return file
	{
		names.push_back(input);
	}
	for (string name : names)
	{
		cout << name << endl;
	}
}