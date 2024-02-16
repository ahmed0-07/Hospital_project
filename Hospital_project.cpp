// Hospital_project.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <deque>

using namespace std;

class patient
{
public:
	string name;
	int statue;

	patient()
	{
		name = "";
		statue = -1;
	}

	void take_info(string name, int statue)
	{
		this->name = name;
		this->statue = statue;
	}
};

class spec
{
	deque<patient> patients;
public:

	bool isFull()
	{
		return patients.size() == 5;
	}

	bool isEmpty()
	{
		return patients.size() == 0;
	}

	int size()
	{
		return patients.size();
	}

	void display_patients()
	{
		for (int i = 0; i < patients.size(); i++)
		{
			cout << patients[i].name << ' ' << (patients[i].statue == 0 ? "regular" : "urgent") << '\n';
		}
	}
	
	void add_patient()
	{
		if (isFull())
		{
			cout << "Sorry this specialaization is full of patients\n";
			return;
		}

		cout << "Enter name, statue: \n";

		int statue;
		string name;

		cin >> name >> statue;

		patient p;
		p.take_info(name, statue);
		if (p.statue == 0)
		{
			patients.push_back(p);
		}
		else
		{
			patients.push_front(p);
		}
	}

	void treat_patient()
	{
		if (isEmpty())
		{
			cout << "No patients. Have a rest, Dr\n";
			return;
		}

		patients.pop_front();
	}
};

class hospital
{
	spec specs[5];
public:
	hospital()
	{
		
	}	

	int choice()
	{
		int choice = -1;
		while (choice == -1)
		{
			cout << "===================================================\n";
			cout << "Enter your choice:\n";
			cout << "1) Add new patient\n";
			cout << "2) print all patient\n";
			cout << "3) get next patient\n";
			cout << "4) exit\n";

			cin >> choice;

			if (!(choice <= 4 && choice >= 1))
			{
				cout << "invalid choice. try again \n";
				choice = -1;
			}
			
		}

		return choice;
	}

	void run()
	{

		while (true)
		{
			int ch = choice();
			int spec;

			
			if (ch == 1)
			{
				cout << "Enter spec: \n";
				cin >> spec;

				specs[spec].add_patient();
			}
			else if (ch == 2)
			{
				print_all_patients();
			}
			else if (ch == 3)
			{
				cout << "Enter specialaization: ";
				cin >> spec;
				specs[spec].treat_patient();
			}
			else
			{
				break;
			}
		}
	}

	void print_all_patients()
	{
		for (int i = 0; i < 5; i++)
		{
			if (!specs[i].size())
				continue;

			cout << "there are " << specs[i].size() << " patients in speclaization " << i + 1 << '\n';
			specs[i].display_patients();
			cout << "==============================================================================\n";
		}
	}

	
};

int main()
{
	hospital h;
	h.run();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
