#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>

using namespace std;

int main()
{
	int x, y, i = 2;
	int t[1];
	t[0] = 0;

	do {
		system("cls");
		cout << "Podaj zakres liczb dodatnich\n";
		cout << "------------\n";
		cout << "od: ";
		cin >> x;
		cout << "do: ";
		cin >> y;
		cout << "------------\n";
		cout << "Liczby pierwsze z zakresu od: " << x << " do: " << y << endl << endl;
	} while ((x > y) || (y < 2));

	fstream plik;
	plik.open("liczby.txt", ios::trunc | ios::out);
	plik << "Liczby pierwsze z zakresu od:  " << x << " do:  " << y << endl;

	if (x < 3)
	{
		cout << i << endl;
		plik << i << endl;
	}
	do
	{
		while (x > i)
		{
			if (x % i == 0)
				break;
			else if (x == i + 1) {
				cout << x << endl;
				fstream plik;
				plik.open("liczby.txt", ios::out | ios::app);
				plik << x << endl;
				t[0] = x;
				break;
			}
			else
				i++;
		}
		i = 2;
		x++;
	} while (x <= y);
	plik.close();
	cout << endl;

	if ((t[0] == 0) && (y != 2)) {
		cout << "W podanym zakresie brak liczb pierwszych\n";
		fstream plik;
		plik.open("liczby.txt", ios::out | ios::app);
		plik << "W podanym zakresie brak liczb pierwszych\n";
		plik.close();
		cout << endl;
	}

	system("pause");
	return 0;
}
//by njumen72