#include <iostream>
#include <fstream> 
using namespace std;

void checkValidInput()
{
	setlocale(LC_ALL, "Ukrainian");

	if (cin.fail())
	{
		throw "Введенi некоректнi данi.";
	}
}

void checkParamN(int n)
{
	setlocale(LC_ALL, "Ukrainian");

	if (n <= 0)
	{
		throw "Параметр n має бути бiльше 0.";
	}
}

void checkParamsFT(int from, int to)
{
	setlocale(LC_ALL, "Ukrainian");

	if (to < from)
	{
		throw "Параметр a має бути менше параметра b.";
	}
}

void checkParamStep(int step)
{
	setlocale(LC_ALL, "Ukrainian");

	if (step <= 0)
	{
		throw "Параметр step має бути бiльше 0.";
	}
}

int calc(int n, int x) {
	int from = 0, to = 1, step = 1;
	if (from < 0 || to < 0 || from >= to || step <= 0){
		cout << "Неправильнi данi";
	}
	else {
		if (x < 0) {
			double dobsum = 1;
			for (int i = 1; i < n; i++) {
				int e = 0;
				for (int j = 1; j <= n; j++) {
					e += (x - i * i + j);
				}
				dobsum += e;
			}
			cout << "x = " << x << endl;
			cout << "y = " << dobsum << endl << endl;
		}
		else {
			double sum = 0;
			for (int i = 0; i < n; i++) {
				sum += (x - 1) / (i + 1);
			}
			cout << "x = " << x << endl;
			cout << "y = " << sum << endl << endl;
		}
	
	}
	return 0;
}

int main() {
	setlocale(LC_ALL, "UKRAINIAN");
	try {
		int n, lang;
		cout << "Chouse the language (Оберіть мову): 1 - English, 2 - Українська" << endl;
		cin >> lang;
		double x;
		if (lang == 2) {
			cout << "Введіть значення n: ";
		}
		if (lang == 1) {
			cout << "Enter the value n: ";
		}
		cin >> n;
		checkValidInput();
		checkParamN(n);
		int from, to, step;
		checkValidInput();
		checkParamsFT(from = 0, to = 1);
		checkParamStep(step = 1);
		if (lang == 2) {
			cout << "Введiть ліву границю, праву границю i крок аргументу: ";
		}
		if (lang == 1) {
			cout << "Enter the left border, right border and step of the argument: ";
		}
		cin >> from >> to >> step;
		double sum = 0;
		double dobsum = 1;
		if (n > 3 && from < to && step > 0) {
			x = from;
			while (x <= to) {
				calc(n, x);
				x += step;
			}
		}
		else {
			cout << "Неправильнi данi" << endl;
		}
		int saveChoice;
		if (lang == 2) {
			cout << "Бажаєте зберегти результати у файл? (1 - Так, 0 - Ні): ";
		}
		if (lang == 1) {
			cout << "Want to save the data to a file? (1 - Yes, 0 - No): ";
		}
		cin >> saveChoice;
		if (saveChoice == 1) {
			string filename;
			cout << "Введіть ім'я файлу для збереження результатів: ";
			cin >> filename;

			ofstream outFile(filename);

			if (outFile.is_open()) {
				streambuf* coutbuf = cout.rdbuf();
				cout.rdbuf(outFile.rdbuf());

				x = from;
				while (x <= to) {
					calc(n, x);
					x += step;
				}

				outFile.close();
				cout.rdbuf(coutbuf);
				if (lang == 2) {
					cout << "Результат збережено у файлі " << filename << "." << endl;

					if (lang == 1) {
						cout << "Result saved in the file " << filename << "." << endl;
					}
				}
			}
		}

	}
	catch (const char* ex)
	{
		cout << "\n";
		cout << ex << endl;
		cerr << "Error." << endl;
		return 1;
	}
	catch (...)
	{
		cout << "\n";
		cout << "Error." << endl;
		return 1;
	}


	return 0;
}

//C:\Users\timat\OneDrive - Нацiональний технiчний унiверситет Харкiвський полiтехнiчний iнститут\VUS\PO\OIPZ.LAB.3\OIPZ.LAB.3\OIPZ.LAB.3.cpp