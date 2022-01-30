#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

//klasa Produkt - instrukcja jak powinien wyglądać produkt, analogia tłoczni - dprasa ma stemel, który jak spadnie to wytłoczy się w materiale
class Produkt
{
public:
	string opis;
	string kolor;
	string numberButa;
};

int main()
{
	int a = 0;

	ifstream file("Zrodlo.txt");

	vector<Produkt> names;

	string input;
	string opisProduktu = "";
	while (file >> input)
	{
		if (input[0] == '-')
		{
			// Produkt() to tzwm. konstruktor, czyli stwórz mi konkretny produkt na podstawie klasy, analogia do łtoczni - wybij stempel tworząc pojemik
			Produkt prod = Produkt();
			prod.opis = opisProduktu;
			names.push_back(prod);
			opisProduktu = "";
		}
		else {
			opisProduktu = opisProduktu + " " + input;
		}

	}

	for (Produkt& pr : names)
	{
		// cout << pr.opis.find("kolor") + 6 << endl;
		size_t poczatek = pr.opis.find("kolor") + 6;
		size_t koniec = pr.opis.find("Rozmiary") - 1;
		// cout << pr.opis.find("Rozmiary") << endl;
		//cout << pr.opis.substr(poczatek, koniec - poczatek);
		pr.kolor = pr.opis.substr(poczatek, koniec - poczatek);

		size_t poczatek1 = pr.opis.find("Rozmiary") + 9;
		size_t koniec1 = pr.opis.find("stopa");
		pr.numberButa = pr.opis.substr(poczatek1, koniec1 - poczatek1);

		//cout << pr.kolor;
		//cout << endl;
	}


	while (true)
	{
		cout << "Wybierz opcje: \n1 - sortowanie po kolorze; \n2 - sortowanie po rozmiarze; \n3 - filtrowanie po kolorze; \n4 - filtrowanie po rozmiarze; \n5 - close\nTwoj wybor to: ";
		cin >> a;

		if (a == 1) {
			sort(
				names.begin(),
				names.end(),
				// technicznie mówiąc, tzw labda, która jest komparatorem, czyli mówi jak posortować dany vector
				[](Produkt a, Produkt b) {return a.kolor > b.kolor; });

			for (Produkt pr : names)
			{
				cout << pr.opis << "\n" << endl << endl;
			}
		}

		else if (a == 2) {
			sort(
				names.begin(),
				names.end(),
				// technicznie mówiąc, tzw labda, która jest komparatorem, czyli mówi jak posortować dany vector
				[](Produkt a, Produkt b) {return a.numberButa > b.numberButa; });

			for (Produkt pr : names)
			{
				cout << pr.opis << "\n" << endl << endl;
			}
		}

		else if (a == 3) {

			// Show by color
			string color;
			cout << "Enter color: ";
			cin >> color;
			cout << "\n\n";

			for (Produkt& pr : names)
			{
				if (pr.kolor == color)
				{
					cout << "\t" << pr.opis << "\n" << endl << endl;
				}
			}
		}

		else if (a == 4) {
			// Show by size
			int min_size = 0, max_size = 0;
			cout << "Enter min size: ";
			cin >> min_size;
			cout << "Enter max size: ";
			cin >> max_size;
			//cout << "Enter size: ";
			//scanf_s("%d-%d", &min_size, &max_size);
			cout << "You choosed: " << min_size << "-" << max_size << "\n\n";

			int size = 0;
			for (Produkt& pr : names)
			{
				size = stoi(pr.numberButa);
				if (size >= min_size && size <= max_size)
				{
					cout << "\t" << pr.opis << "\n" << endl << endl;
				}
			}
		}

		else if (a == 5)
		{
			break;
		}
	}
}
