#include <iostream>
#include <fstream>
#include <string>
#include<algorithm>
using namespace std;
class Address
{
private:
	string city;
	string street;
	string house;
	string flat;
public:
	Address() {};
	Address(ifstream& data)
	{
		data >> city;
		data >> street;
		data >> house;
		data >> flat;
	}
	string get_output_address()
	{
		return city + ", " + street + ", " + house + ", " + flat;
	}
	string Sort(Address* address, int n)
	{
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < n - i - 1; j++)
				if (address[j].city > address[j + 1].city)
					swap(address[j], address[j + 1]);
		return city + ", " + street + ", " + house + ", " + flat;
	}
};
int main() {
	setlocale(LC_ALL, "Russian");
	int n;
	ifstream file("in.txt");
	if (!file)
	{
		cout << "Не удалось открыть файл!";
		return 0;
	}
	file >> n;
	Address* mass = new Address[n];
	for (int i = 0; i < n; i++)
	{
		mass[i] = Address(file);
	}
	file.close();

	ofstream fout("out.txt");
	fout << n << endl;
	for (int i = 0; i < n; i++)
	{
		fout << mass[i].Sort(mass, n) << endl;
	}

	fout.close();
	delete[] mass;
}