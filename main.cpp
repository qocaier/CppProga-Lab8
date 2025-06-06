#include <iostream>
#include <clocale>
#include "Apartment.h"
#include "Car.h"
#include "CountryHouse.h"
#include "Owner.h"
#include "TaxService.h"
#include <fstream>
#include <filesystem>

using namespace std;

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
	APARTMENT_,
	CAR_,
	COUNTRY_HOUSE
};

enum file_type {
	XML,
	JSON,
	ANOTHER,
	NONE
};

const string main_tutorial_str = "[0] exit - выйти из программы\n[1] tutorial - включить или выключить вывод инструкции\n"
"[2] owner_choice [n] - выбрать собственника под номером n\n[3] add_property - добавить собственность\n[4] del_property [n] - удалить собственность под номером n\n"
"[5] add_owner - добавить собственника\n[6] del_owner [n] - удалить собственника под номером n\n\n";

const string prop_tutorial_str = "[0] Квартира	[1] Тачка	[2] Вилла ";

vector<Owner> a = {
	Owner("Хараев Макс Александрович", "156234897956"),
	Owner("Бушуев Миша _", "489123785263"),
	Owner("Кетов Кир _", "874451223588")
};

int owner_choice();
void print_console();
void base_interface();
int exe_interface();
file_type file_recognition(string fn, bool inp);

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "RU");
	if (argc == 1) return exe_interface();
	if (argc == 2) {
		clog << "Недостаточное количество параметров!\n";
		return -1;
	}
	filesystem::current_path("../../");

	file_type ft1 = file_recognition(argv[1], 1);
	file_type ft2 = file_recognition(argv[2], 0);
	TaxService a;

	switch (ft1)
	{
	case XML: {
		pugi::xml_document xml;
		pugi::xml_parse_result result1 = xml.load_file(argv[1]);
		if (!result1) {
			clog << "Некорректные данные для xml!\n";
			return -1;
		}
		const pugi::xml_node root1 = xml.child("owners");
		a.fromXml(root1);
		break;
	}
	case JSON: {
		ifstream fin(argv[1]);
		nlohmann::json json = nlohmann::json::parse(fin);
		fin.close();
		a.fromJson(json);
		break;
	}
	case ANOTHER: {
		clog << "Некорректный тип файла!\n";
		return -1;
	}
	case NONE: {
		clog << "Файла " << argv[1] << " нет!\n";
		return -1;
	}
	}

	switch (ft2)
	{
	case XML: {
		pugi::xml_document doc;
		pugi::xml_node root2 = doc.append_child("owners");
		a.toXml(root2);
		bool result2 = doc.save_file(argv[2]);
		if (!result2) {
			clog << "Некорректное имя файла: " << argv[2] << '\n';
			return -1;
		}
		break;
	}
	case JSON: {
		nlohmann::json obj = a.toJson();
		ofstream fout(argv[2]);
		if (!fout.good()) {
			clog << "Некорректное имя файла: " << argv[2] << '\n';
			return -1;
		}
		fout << obj;
		fout.close();
		break;
	}
	case ANOTHER:
		clog << "Некорректный тип файла!\n";
		return -1;
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

void base_interface()
{
	setlocale(LC_ALL, "RU");
	bool z = true, tutorial = true, zz = false;
	int k, f, n;
	unsigned int v, s;
	double p;
	string fn1, fn2, fn3, nn;

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
			case APARTMENT_:
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
			case CAR_:
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
				cout << "Введите ФИО собственника: ";
				cin >> fn1 >> fn2 >> fn3;
				while (cin.fail()) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Некорректный ввод. Введите еще раз: ";
					cin >> fn1 >> fn2 >> fn3;
				}
				cout << "Введите ИНН собственника: ";
				cin >> nn;
				while (cin.fail() || nn.length() != 12) {
					cin.clear();
					cin.ignore(numeric_limits<streamsize>::max(), '\n');
					cout << "Некорректный ввод. Введите еще раз: ";
					cin >> nn;
				}
				a.push_back(Owner(fn1 + ' ' + fn2 + ' ' + fn3, nn));
			}
			catch (exception e) {
				cout << e.what();
				/*cout << "Введите ФИО собственника: ";
				getline(cin, fn, '\n');
				cout << "Введите ИНН собственника: ";
				cin >> nn;
				a.push_back(Owner(fn, nn));*/
			};
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

int exe_interface()
{
	string inp, outp;
	cout << "Введите имя входного файла: ";
	cin >> inp;

	cout << "Введите имя выходного файла: ";
	cin >> outp;

	file_type ft1 = file_recognition(inp, 1);
	file_type ft2 = file_recognition(outp, 0);
	TaxService a;

	switch (ft1)
	{
	case XML: {
		pugi::xml_document xml;
		pugi::xml_parse_result result1 = xml.load_file(inp.c_str());
		if (!result1) {
			clog << "Некорректные данные для xml!\n";
			return -1;
		}
		const pugi::xml_node root1 = xml.child("owners");
		a.fromXml(root1);
		break;
	}
	case JSON: {
		ifstream fin(inp);
		nlohmann::json json = nlohmann::json::parse(fin);
		fin.close();
		a.fromJson(json);
		break;
	}
	case ANOTHER: {
		clog << "Некорректный тип файла!\n";
		return -1;
	}
	case NONE: {
		clog << "Файла " << inp << " нет!\n";
		return -1;
	}
	}

	switch (ft2)
	{
	case XML: {
		pugi::xml_document doc;
		pugi::xml_node root2 = doc.append_child("owners");
		a.toXml(root2);
		bool result2 = doc.save_file(outp.c_str());
		if (!result2) {
			clog << "Некорректное имя файла: " << outp << '\n';
			return -1;
		}
		break;
	}
	case JSON: {
		nlohmann::json obj = a.toJson();
		ofstream fout(outp);
		if (!fout.good()) {
			clog << "Некорректное имя файла: " << outp << '\n';
			return -1;
		}
		fout << obj;
		fout.close();
		break;
	}
	case ANOTHER:
		clog << "Некорректный тип файла!\n";
		return -1;
	}
}

file_type file_recognition(string fn, bool inp)
{
	if (inp) {
		string c1, c2;
		ifstream fin(fn);
		if (!fin.good()) return NONE;
		if (fn.substr(fn.size() - 4) == ".xml") {
			fin >> c1 >> c2;
			fin.close();
			if (c1 == "<?xml" && c2 == "version=\"1.0\"?>") return XML;
		}
		else if (fn.substr(fn.size() - 5) == ".json") {
			fin >> c1 >> c2;
			fin.close();
			if (c1 == "[" && c2 == "{") return JSON;
		}
		if (fin.is_open()) fin.close();
	}
	else {
		if (fn.substr(fn.size() - 4) == ".xml") return XML;
		else if (fn.substr(fn.size() - 5) == ".json") return JSON;
	}
	return ANOTHER;
}