#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
using namespace std;


//klasa Produkt - instrukcja jak powinien wyglądać produkt, analogia tłoczni - dprasa ma stemel, który jak spadnie to wytłoczy się w materiale
class Produkt
{
public:
	string opis;
	string kolor;
	int numberButa;
};

int main()
{
	ifstream file("ProjektInformatyka.txt");

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

	for (Produkt &pr : names)
	{
		// cout << pr.opis.find("kolor") + 6 << endl;
		size_t poczatek = pr.opis.find("kolor") + 6;
		size_t koniec = pr.opis.find("Rozmiary");
		// cout << pr.opis.find("Rozmiary") << endl;
		//cout << pr.opis.substr(poczatek, koniec - poczatek);
		pr.kolor = pr.opis.substr(poczatek, koniec - poczatek);
		//cout << pr.kolor;
		//cout << endl;
	}

	std::sort(
		names.begin(),
		names.end(),
		// technicznie mówiąc, tzw labda, która jest komparatorem, czyli mówi jak posortować dany vector
		[](Produkt a, Produkt b) {return a.kolor > b.kolor; });


	for (Produkt pr : names)
	{
		cout << pr.opis << "\n" << pr.kolor << endl << endl;
	}
}
