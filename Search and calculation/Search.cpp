#include <iostream>
#include <string>

using namespace std;

#pragma region Special_Abilities

extern void ClearScrean_Task1() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	cout << "\tSearch" << endl;
}

extern void Enter();
#pragma endregion

string FindSubstring(string& text, const string substring)
{
	if (text.find(substring) != string::npos)
	{
		size_t index{ 0 };

		while (text.find(substring, index) != string::npos)
		{
			text.insert(text.begin() + text.find(substring, index), '(');
			text.insert(text.begin() + text.find(substring, index) + substring.size(), ')');

			index = text.find(substring, index) + substring.size();

		}

		return text;

	}
	else return "No substring found";

}

int Search()
{
	int choice{ 1 };
	string text{ "" }, substring{ "" };
	do {

		ClearScrean_Task1();
		cout << "Enter text: "; cin.ignore(); getline(cin, text);
		cout << "Enter substring: "; getline(cin, substring);

		ClearScrean_Task1();
		cout << "Result: " << FindSubstring(text, substring) << endl;
		Enter();

		do {

			ClearScrean_Task1();
			cout << "Do you want to find a substring in a new line?\n"
				<< "[1] - Yes\n[2] - No" << endl;

			if (choice >= 1 && choice <= 2)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;
		} while (choice < 1 || choice > 2);

	} while (choice != 2);

	return 0;
}
