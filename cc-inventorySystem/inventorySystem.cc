#include <iostream>
#include <iomanip>
#include <string.h>
#include <stdlib.h>

const int nmin = 0;
const int nmax = 1000;

typedef char string60[61];
typedef char string10[11];
typedef char string5[6];

typedef struct
{
	string5 code;
	string60 name;
	float quantitykg;
	unsigned traveldays;
	char type;
	string10 date;
	string10 pos;
	float temperature;
} article;

typedef article array_1[nmax + 1];

void inputInventoryItem(array_1 z, int n)
{
	for (int i = 1; i <= n; i++)
	{
		std::cout << "\nInsert the Code: ";
		std::cin >> z[i].code;

		std::cout << "\nInsert the Name: ";
		std::cin >> z[i].name;

		std::cout << "\nInsert the Quantity in kg: ";
		std ::cin >> z[i].quantitykg;

		std::cout << "\nInsert the Traveling time in Days: ";
		std::cin >> z[i].traveldays;

		std::cout << "\nInsert the Type of Article: ";
		std::cin >> z[i].type;

		std::cout << "\nInsert the Date: ";
		std::cin >> z[i].date;

		std::cout << "\nInsert the Position: ";
		std::cin >> z[i].pos;

		if (z[i].type == 'S')
		{
			std::cout << "\nInsert the Temperature: ";
			std::cin >> z[i].temperature;
		}
	}
}

void displayInventoryList(array_1 z, int n)
{
    for (int i = 1; i <= n; i++)
    {
        std::cout << z[i].pos << ", " << z[i].code << ", "
                  << z[i].name << ", " << std::fixed << std::setprecision(0)
                  << z[i].quantitykg << " kg., " << z[i].date << ", "
                  << z[i].traveldays;

        if (z[i].type == 'S')
        {
            std::cout << ", tC=" << std::fixed << std::setprecision(1)
                      << z[i].temperature;
        }
        std::cout << std::endl;
    }
}

void sortByStoragePosition(array_1 z, int n)
{
	article tempVar;
	for (int i = 2; i <= n; i++) {
		for (int j = n; j >= i; j--) {
			if (strcmp(z[j - 1].pos, z[j].pos) > 0)
			{
				tempVar = z[j - 1];
				z[j - 1] = z[j];
				z[j] = tempVar;
			}
		}
	}
}

void filterAndSortSItems(array_1 z, array_1 a, int n, int& m)
{
	m++;
	for (int i = 1; i <= n; i++){
		if (z[i].type == 'S')
		{
			m++;
			a[m] = z[i];
		}
	}

	article tempVar;
	for (int i = 2; i <= m; i++){
		for (int j = m; j >= i; j--){
			if (strcmp(a[j - 1].date, a[j].date) > 0
			|| strcmp(a[j - 1].date, a[j].date) == 0
			&& a[j - 1].traveldays < a[j].traveldays)
			{
				tempVar = a[j - 1];
				a[j - 1] = a[j];
				a[j] = tempVar;
			}
		}
	}
}

void searchByItemCode(array_1 z, int n)
{
	float sum = 0;
	int mintemperature = 100;
	string5 codetoCheck;

	std::cout << "\nInsert the Code: ";
	std::cin >> codetoCheck;

	for (int i = 1; i <= n; i++){
		if (strcmp(z[i].code, codetoCheck) == 0) {
			std::cout << z[i].name << z[i].pos;
			sum = sum + z[i].quantitykg;

			if (z[i].temperature < mintemperature) {
				mintemperature = z[i].temperature;
			}
		}
	}
}

int main()
{
	int n = 0, m = 0;
	array_1 z, a;

	do
	{
		std::cout << "Insert the value of the number n: ";
		std::cin >> n;
	} while (n < nmin || n > nmax);

	inputInventoryItem(z, n);
	sortByStoragePosition(z, n);
	displayInventoryList(z, n);
	filterAndSortSItems(z, a, n, m);
	displayInventoryList(a, m);
	searchByItemCode(z, n);
}
