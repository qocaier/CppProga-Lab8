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
void exe_interface();

int main(int argc, char* argv[]) {
	setlocale(LC_ALL, "RU");
	if (argc == 1) {
		exe_interface();
		return 0;
	}
	if (argc == 2) {
		clog << "Недостаточное количество параметров!\n";
		return -1;
	}
	filesystem::current_path("../../");

	/*string name1 = argv[1]
	if (.substr())*/
	//// json
	//ifstream fin(argv[1]);
	//if (!fin.good()) {
	//	clog << "Файла " << argv[1] << " нет!\n";
	//	return -1;
	//}

	//nlohmann::json json = nlohmann::json::parse(fin);
	//fin.close();

	//TaxService a;
	//a.fromJson(json);
	//nlohmann::json obj = a.toJson();

	///*Owner ownr;
	//ownr.fromJson(json);
	//nlohmann::json obj = ownr.toJson();*/

	//ofstream fout(argv[2]);
	//if (!fout.good()) {
	//	clog << "Некорректное имя файла: " << argv[2] << '\n';
	//	return -1;
	//}
	//fout << obj;
	//fout.close();


	// xml
	pugi::xml_document xml;
	pugi::xml_parse_result result1 = xml.load_file(argv[1]);
	if (!result1) {
		clog << "Файла " << argv[1] << " нет!\n";
		return -1;
	}

	TaxService a;
	const pugi::xml_node root1 = xml.child("owners");
	a.fromXml(root1);

	pugi::xml_document doc;
	pugi::xml_node root2 = doc.append_child("owners");
	a.toXml(root2);
	bool result2 = doc.save_file(argv[2]);
	if (!result2) {
		clog << "Некорректное имя файла: " << argv[2] << '\n';
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

void exe_interface()
{
	//string inp, outp;
	//cout << "Введите имя входного файла: ";
	//cin >> inp;
	//ifstream fin(inp);
	///*while (cin.fail() || !fin.good()) {
	//	if (!cin.fail()) clog << "Файла " << inp << " нет!\n";
	//	cin.clear();
	//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//	cout << "Некорректный ввод! Введите еще раз: ";
	//	cin >> inp;
	//	ifstream fin(inp);
	//}*/
	//if (!fin.good()) {
	//	clog << "Файла " << inp << " нет!\n";
	//	return;
	//}
	//nlohmann::json json = nlohmann::json::parse(fin);
	//fin.close();

	//TaxService a;
	//a.fromJson(json);
	//nlohmann::json obj = a.toJson();

	///*Owner ownr;
	//ownr.fromJson(json);
	//nlohmann::json obj = ownr.toJson();*/

	//cout << "Введите имя выходного файла: ";
	//cin >> outp;
	//ofstream fout(outp);
	///*while (cin.fail() || !fout.good()) {
	//	if (!cin.fail()) clog << "Некорректное имя файла: " << outp << '\n';
	//	cin.clear();
	//	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	//	cout << "Некорректный ввод! Введите еще раз: ";
	//	cin >> outp;
	//	ofstream fout(outp);
	//}*/
	//if (!fout.good()) {
	//	clog << "Некорректное имя файла: " << outp << '\n';
	//	return;
	//}
	//fout << obj;
	//fout.close();


	string inp, outp;
	cout << "введите имя входного файла: ";
	cin >> inp;
	pugi::xml_document xml;
	pugi::xml_parse_result result1 = xml.load_file(inp.c_str());
	if (!result1) {
		clog << "Файла " << inp << " нет!\n";
		return;
	}

	TaxService a;
	const pugi::xml_node root1 = xml.document_element();
	a.fromXml(root1);

	cout << "Введите имя выходного файла: ";
	cin >> outp;

	pugi::xml_document doc;
	pugi::xml_node root2 = doc.append_child("owners");
	a.toXml(root2);
	bool result2 = doc.save_file(outp.c_str());
	if (!result2) {
		clog << "Некорректное имя файла: " << outp << '\n';
		return;
	}
}