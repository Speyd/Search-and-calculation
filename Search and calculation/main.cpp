#include "Search.h"
#include "Calculation.h"
#include <iostream>
#include <string>

using namespace std;

#pragma region Special_Abilities

void ClearScrean() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	cout << "\tSearch & Calculation" << endl;
}

void Enter() {
	string enter;
	do {

		cout << "Press enter to continue: "; getline(cin, enter);

	} while (!enter.empty());
}
#pragma endregion


int main()
{
	int choice{ 1 };
	do {

		do {

			ClearScrean();
			cout << "Choice task!\n[1] - Search substring\n[2] - Calculation string" << endl;

			if (choice >= 1 && choice <= 2)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;
		} while (choice < 1 || choice > 2);

		if (choice == 1)Search();
		else if (choice == 2)Calculation();

	} while (choice != 2);

	return 0;
}
