#include <iostream>
#include <windows.h>
#include <employee3/employee3.h>
#include <stdexcept>
#include <string>


void menu() {
	system("cls");
	cout << "������������! ������� ����� �� 1 �� 6" << endl;
	cout << "1 - �������� ������� � ������ �� ���������� �������" << endl;
	cout << "2 - ������� ������� �� ������ �� ���������� �������" << endl;
	cout << "3 - ������� ������ �� �����" << endl;
	cout << "4 - ����� � ������ ������� ���������� � ������������ ���������� ������" << endl;
	cout << "5 - ������ ���������� �����" << endl;
	cout << "6 - ��������� ���������" << endl;
	cout << "> ";
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	EmployeeList EL = EmployeeList();
	shared_ptr<Staff> staff = make_shared<Staff>();
	shared_ptr<Freelance> freelance = make_shared<Freelance>();
	int input = 0;
	int idx, type;
	while (input != 6) {
		menu();
		cin >> input;
		switch (input) {
		case 1:
			system("cls");
			EL.show_all();
			cout << "������� ������: ";
			cin >> idx;
			cout << "������� ���: (0-Staff,1-Freelance) ";
			cin >> type;
			switch (type) {
			case 0:
				cin >> staff;
				EL.insert(idx, staff);
				break;
			case 1:
				cin >> freelance;
				EL.insert(idx, freelance);
				break;
			}
			break;
		case 2:
			system("cls");
			EL.show_all();
			cout << "������� ������: ";
			cin >> idx;
			EL.erase(idx);
			break;
		case 3:
			system("cls");
			EL.show_all();
			break;
		case 4:
			system("cls");
			EL.show_all();
			idx = EL.find_with_max_salary();
			cout << "������ ��������� � ������������ ���������� ������: " << idx << endl;
			break;
		case 5:
			system("cls");
			EL.show_all();
			cout << "������� ������: ";
			cin >> idx;
			EL[idx]->compute_salary();
			cout << "���������� �����: " << EL[idx]->compute_salary() << endl;
			break;
		}
		if (input != 6)
			system("pause");
	}
}