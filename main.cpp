#include <iostream>
#include <clocale>
#include "Apartment.h"
#include "Car.h"
#include "CountryHouse.h"
#include "Owner.h"

enum functions {
	EXIT,
	TUTORIAL,
	OWNER_CHOICE,
	ADD_PROPERTY,
	DEL_PROPERTY,
	ADD_OWNER,
	DEL_OWNER
};

enum property_types {
	APARTMENT,
	CAR,
	COUNTRY_HOUSE
};

const string main_tutorial_str = "[0] exit - выйти из программы\n[1] tutorial - включить или выключить вывод инструкции\n"
"[2] owner_choice [n] - выбрать собственника под номером n\n[3] add_property - добавить собственность\n[4] del_property [n] - удалить собственность под номером n\n"
"[5] add_owner - добавить собственника\n[6] del_owner [n] - удалить собственника под номером n\n\n";

const string prop_tutorial_str = "[0] Квартира	[1] Тачка	[2] Вилла ";

vector<Owner> a = {
	Owner("Макс Хараев", "156234897956"),
	Owner("Миша Бушуев", "489123785263"),
	Owner("Кир Кетов", "874451223588")
};

int owner_choice();
void print_console();

int main() {
	setlocale(LC_ALL, "RU");
	bool z = true, tutorial = true, zz = false;
	int k, f, n;
	unsigned int v, s;
	double p;

	a[0].addProperty(new Apartment(45610565, 1462.55));
	a[0].addProperty(new Car(5462385, 256.88));
	a[0].addProperty(new Car(1047000, 90.01));
	a[0].addProperty(new CountryHouse(525000, 3));

	a[1].addProperty(new Apartment(26689575, 892.36));
	a[1].addProperty(new Apartment(10462381, 100.07));
	a[1].addProperty(new Car(5462463, 147.246));
	a[1].addProperty(new Car(489900, 72.95));

	a[2].addProperty(new Apartment(39564622, 1014.46));
	a[2].addProperty(new Apartment(7346358, 125.94));
	a[2].addProperty(new CountryHouse(5489243, 198));
	a[2].addProperty(new CountryHouse(2858346, 26));

	print_console();
	k = owner_choice();

	while (z) {
		print_console();
		if (tutorial) cout << main_tutorial_str;
		if (zz) { cout << "Такой функции нет! "; zz = false; }
		cout << "Выберите функцию: ";
		cin >> f;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Некорректный ввод! Введите еще раз: ";
			cin >> f;
		}
		switch (f) {
		case EXIT: z = false; break;
		case TUTORIAL: tutorial = !tutorial; break;
		case OWNER_CHOICE: k = owner_choice(); break;
		case ADD_PROPERTY:
			cout << prop_tutorial_str << "Введите тип и стоимость собственности: ";
			cin >> n >> v;
			while (cin.fail() || n < 0 || n > 2) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Некорректный ввод! Введите еще раз: ";
				cin >> n >> v;
			}

			switch (n) {
			case APARTMENT:
				cout << "Введите площадь квартиры: ";
				cin >> p;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Некорректный ввод! Введите еще раз: ";
					cin >> p;
				}
				a[k].addProperty(new Apartment(v, p));
				break;
			case CAR:
				cout << "Введите мощность: ";
				cin >> p;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Некорректный ввод! Введите еще раз: ";
					cin >> p;
				}
				a[k].addProperty(new Car(v, p));
				break;
			case COUNTRY_HOUSE:
				cout << "Введите удаленность от города: ";
				cin >> s;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Некорректный ввод! Введите еще раз: ";
					cin >> s;
				}
				a[k].addProperty(new CountryHouse(v, s));
				break;
			}
			break;
		case DEL_PROPERTY: 
			cout << "Введите номер собственности: ";
			cin >> v;
			while (cin.fail() || v < 0 || v >= a[k].getProperties().size()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Некорректный ввод! Введите еще раз: ";
				cin >> v;
			}
			a[k].delProperty(v);
			break;
		case ADD_OWNER:
			try {
				string fn, nn;
				cout << "Введите ФИО собственника: ";
				cin >> fn;
				cout << "Введите ИНН собственника: ";
				cin >> nn;
				a.push_back(Owner(fn, nn));
			} catch (exception e) { cout << e.what(); };
			break;
		case DEL_OWNER:
			cout << "Введите номер собственника: ";
			cin >> n;
			while (cin.fail() || n < 0 || n >= a.size()) {
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "Некорректный ввод! Введите еще раз: ";
				cin >> n;
			}
			a.erase(a.begin() + n);
			if (n == k) { print_console(); cout << "Выбранный собственник был удален. "; k = owner_choice(); }
			if (n < k) k--;
			break;
		default: zz = true;
		}
		cout << '\n';
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
	}
}

int owner_choice()
{
	int n;
	cout << "Введите номер собственника: ";
	cin >> n;
	while (cin.fail() || n < 0 || n >= a.size()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Некорректный ввод! Введите еще раз: ";
		cin >> n;
	};
	return n;
}

void print_console()
{
	system("cls");
	for (Owner owner : a) {
		cout << owner.getData();
		for (Property* prop : owner.getProperties()) cout << prop->getData();
	}
	cout << '\n';
}