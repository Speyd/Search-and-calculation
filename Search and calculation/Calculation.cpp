#include <iostream>
#include <string>

using namespace std;

#pragma region Special_Abilities

void ClearScrean_Task2() {
#ifdef _WIN32
	system("cls");
#else
	system("clear");
#endif
	cout << "\tCalculation" << endl;
}

extern void Enter();
#pragma endregion

char FindSymbol(const string text, const int indexFind) {

	size_t minIndex{ string::npos };

	if (text.find('+', indexFind) != string::npos)minIndex = text.find('+', indexFind);

	if (text.find('-', indexFind) != string::npos
		&& minIndex > text.find('-', indexFind))minIndex = text.find('-', indexFind);

	if (text.find('*', indexFind) != string::npos
		&& minIndex > text.find('*', indexFind))minIndex = text.find('*', indexFind);

	if (text.find('/', indexFind) != string::npos
		&& minIndex > text.find('/', indexFind))minIndex = text.find('/', indexFind);

	if (text.find('%', indexFind) != string::npos
		&& minIndex > text.find('%', indexFind))minIndex = text.find('%', indexFind);

	return minIndex != string::npos ? text[minIndex] : string::npos;
}

void FindNumbers(string& num1, string& num2, const string text, const int indexFind) {

	for (int i{ indexFind - 1 }; i >= 0; i--)
	{

		if (isdigit(text[i]))num1 += text[i];
		else break;

	}

	for (int i{ indexFind + 1 }; i < text.size(); i++)
	{

		if (isdigit(text[i]))num2 += text[i];
		else break;

	}

}

string Result(const string num1, const string num2, const char symbol) {

	if (symbol == '+') return to_string(stoi(num1) + stoi(num2));
	else if (symbol == '-') return to_string(stoi(num1) - stoi(num2));
	else if (symbol == '*') return to_string(stoi(num1) * stoi(num2));
	else if (symbol == '/') return to_string(stoi(num1) / stoi(num2));
	else if (symbol == '%') return to_string(stoi(num1) % stoi(num2));

}

string CalculationString(string& text) {

	if (text.find('+') != string::npos || text.find('-') != string::npos
		|| text.find('*') != string::npos || text.find('/') != string::npos
		|| text.find('%') != string::npos)
	{
		char symbol{ FindSymbol(text,0) };
		size_t index{ 0 };

		while (symbol != string::npos || text.find(symbol, index) != string::npos)
		{

			string num1{ "" }, num2{ "" };
			size_t indexFind{ text.find(symbol, index) };

			if (indexFind != string::npos && indexFind - 1 >= 0 && indexFind + 1 < text.size())
			{
				FindNumbers(num1, num2, text, indexFind);
				if (num1.empty() == false && num2.empty() == false) {

					string result{ Result(num1, num2, symbol) };
					text.replace(text.begin() + indexFind - num1.size(), text.begin() + indexFind + num2.size() + 1, result);

				}
				else indexFind++;

			}
			else break;

			symbol = FindSymbol(text, indexFind);
		}

	}

	return text;

}

int Calculation()
{
	int choice{ 1 };
	string text{ "" }, substring{ "" };
	do {

		ClearScrean_Task2();
		cout << "Enter text: "; cin.ignore(); getline(cin, text);


		ClearScrean_Task2();
		cout << "Result: " << CalculationString(text) << endl;
		Enter();

		do {

			ClearScrean_Task2();
			cout << "Do you want to find a substring in a new line?\n"
				<< "[1] - Yes\n[2] - No" << endl;

			if (choice >= 1 && choice <= 2)cout << "Enter your choice: ";
			else cout << "There is no such choice!\nEnter your choice again: ";

			cin >> choice;
		} while (choice < 1 || choice > 2);

	} while (choice != 2);

	return 0;
}
