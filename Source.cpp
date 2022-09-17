#include <iostream>
#include<vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <conio.h>
using namespace std;

class Fabric
{
public:
	virtual void EnterData() = 0;
	virtual void Save() = 0;
	virtual void Read() = 0;
	virtual void SearchName() = 0;
	virtual void SearchDate() = 0;
	virtual void SearchTage() = 0;
	virtual void Print() = 0;
	virtual void Enter() = 0;

};

class CreateDe : public Fabric
{
public:

	vector<string> queue;
	struct delo
	{
		string name;
		string date;
		string tage;
	};
	delo D;
	vector<delo>delo;

	void Enter()override
	{
		EnterData();
	}

	void Print() override
	{
		for (int i = 0; i < delo.size(); i++)
		{
			cout << "--->>>" << i + 1 << "<<<---\n";
			cout << "Name: " << delo[i].name << "\n";
			cout << "Date: " << delo[i].date << "\n";
			cout << "Tage: " << delo[i].tage << "\n";
		}
	}

	void EnterData() override
	{
		cout << "Enter name business\n";
		getline(cin, D.name);
		cout << "Enter date business\n";
		getline(cin, D.date);
		cout << "Enter tage business\n";
		getline(cin, D.tage);
		delo.push_back(D);

	}

	void Save() override
	{
		ofstream outfile("TestDelo.txt");
		for (int i = 0; i < delo.size(); i++)
		{
			outfile << delo[i].name << "\n";
			outfile << delo[i].date << "\n";
			outfile << delo[i].tage << "\n\n";
		}
		outfile.close();
	}

	void Read() override
	{
		string s;
		ifstream outfile("TestDelo.txt");
		if (outfile.is_open())
		{
			int i = 0;
			while (!outfile.eof())
			{
				getline(outfile, s);

				cout << s << "\n";

			}
		}
		outfile.close();
		cout << "\n";
	}

	void SearchName() override
	{
		string a;
		cout << "Enter search name:\n";
		getline(cin, a);
		bool b = false;
		for (int i = 0; i < delo.size(); i++)
		{

			if (!delo[i].name.find(a))
			{
				cout << i + 1 << "\t" << delo[i].name << "\n";
				b = true;
			}
		}
		if (b == false)
		{
			cout << "Ne nashlos'\n";
		}
	}

	void SearchDate() override
	{
		string a;
		cout << "Enter search date:\n";
		getline(cin, a);
		bool b = false;
		for (int i = 0; i < delo.size(); i++)
		{

			if (!delo[i].date.find(a))
			{
				cout << i + 1 << "\t" << delo[i].date << "\n";
				b = true;
			}
		}
		if (b == false)
		{
			cout << "Ne nashlos'\n";
		}
	}

	void SearchTage() override
	{
		string a;
		cout << "Enter search tage:\n";
		getline(cin, a);
		bool b = false;
		for (int i = 0; i < delo.size(); i++)
		{

			if (!delo[i].tage.find(a))
			{
				cout << i + 1 << "\t" << delo[i].tage << "\n";
				b = true;
			}
		}
		if (b == false)
		{
			cout << "Ne nashlos'\n";
		}
	}

};

class DeloAbs
{
public:
	virtual CreateDe* createDATA() = 0;
};

class DeloFactory : public DeloAbs
{
public:
	CreateDe* createDATA()
	{
		return new CreateDe;
	}
};

class Create
{
public:
	vector<CreateDe*> d;

	~Create()
	{
		for (int i = 0; i < d.size(); i++) delete d[i];

	}

	void Enter()
	{
		for (int i = 0; i < d.size(); i++)  d[i]->Enter();
	}

	void info()
	{
		for (int i = 0; i < d.size(); i++)  d[i]->Print();
		cout << "\n";
	}

	void Sav()
	{
		for (int i = 0; i < d.size(); i++)  d[i]->Save();
	}

	void Reader()
	{
		for (int i = 0; i < d.size(); i++)  d[i]->Read();
	}

	void SearcherName()
	{
		for (int i = 0; i < d.size(); i++)  d[i]->SearchName();
	}

	void SearcherDate()
	{
		for (int i = 0; i < d.size(); i++)  d[i]->SearchDate();
	}

	void SearcherTage()
	{
		for (int i = 0; i < d.size(); i++)  d[i]->SearchTage();
	}

};

class NewData
{
public:
	Create* createDelo(DeloFactory& factory)
	{
		Create* c = new Create;
		c->d.push_back(factory.createDATA());
		return c;
	}
};

int main()
{
	NewData NewD;
	DeloFactory DELO_Factory;

	Create* DELO = NewD.createDelo(DELO_Factory);

	char vvod;
	do
	{
		system("cls");
		cout << "1 - CreateDelo\n";
		cout << "2 - SearchName\n";
		cout << "3 - SearchDate\n";
		cout << "4 - SearchTage\n";
		cout << "5 - info\n";
		cout << "6 - SaveToFile\n";
		cout << "7 - ReadFile\n";
		cout << "Exit - Esc\n";
		vvod = _getch();
		switch (vvod)
		{
		case'1':
		{
			re1:DELO->Enter();
			char vvod;
			do
			{
				system("cls");
				cout << "1 - Add delo\n";
				cout << "2 - Exit\n";
				vvod = _getch();
				switch (vvod)
				{
				case'1':
				{
					goto re1;
				}
				case'2':
				{
					vvod = 27;
				}
				}
			} while (vvod != 27);
			system("pause");
			break;
		}
		case'2':
		{
			DELO->SearcherName();
			system("pause");
			break;
		}
		case'3':
		{
			DELO->SearcherDate();
			system("pause");
			break;
		}
		case'4':
		{
			DELO->SearcherTage();
			system("pause");
			break;
		}
		case'5':
		{
			DELO->info();
			system("pause");
			break;
		}
		case'6':
		{
			DELO->Sav();
			system("pause");
			break;
		}
		case'7':
		{
			DELO->Reader();
			system("pause");
			break;
		}
		}
	} while (vvod != 27);

}