#include <iostream>
#include<vector>
#include <string>
#include <algorithm>
#include <fstream>
using namespace std;

class Fabric
{
public:
	virtual void rimsOnWheels() = 0;
	virtual void Queue() = 0;
	virtual void Save() = 0;
	virtual void Read() = 0;
	virtual void Search() = 0;
	virtual void Print() = 0;
	virtual void Enter() = 0;

};



class BMW : public Fabric
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
		rimsOnWheels();
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
	void rimsOnWheels() override
	{
		cout << "Enter name business\n";
		getline(cin,D.name);
		cout << "Enter date business\n";
		getline(cin, D.date);
		cout << "Enter tage business\n";
		getline(cin, D.tage);
		delo.push_back(D);
		
	}
	void Queue() override
	{
		/*for (int i = 0; i < delo.size(); i++)
		{*/
			sort(delo[0].date.begin(), delo[delo.size()+1].date.end());

		/*}*/
		
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

				cout << s<<"\n";
				
			}
		}
		outfile.close();
		cout << "\n";
	}
	
	void Search() override
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

};


class Auto
{
public:
	virtual BMW* createBMW() = 0;
	
};


class AutoFactory : public Auto
{
public:
	BMW* createBMW()
	{
		return new BMW;
	}

};

class Create
{
public:
	vector<BMW*> BMW;
	
	~Create()
	{
		for (int i = 0; i < BMW.size(); i++) delete BMW[i];

	}
	void Enter()
	{
		for (int i = 0; i < BMW.size(); i++)  BMW[i]->Enter();
	}
	void info()
	{
		for (int i = 0; i < BMW.size(); i++)  BMW[i]->Print();
		cout << "\n";
		
	}

	void Sav()
	{
		for (int i = 0; i < BMW.size(); i++)  BMW[i]->Save();
	}
	void Reader()
	{
		for (int i = 0; i < BMW.size(); i++)  BMW[i]->Read();
	}

	void Searcher()
	{
		for (int i = 0; i < BMW.size(); i++)  BMW[i]->Search();
	}

};

class NewAuto
{
public:
	Create* createAuto(AutoFactory& factory)
	{
		Create* c = new Create;
		c->BMW.push_back(factory.createBMW());
		return c;
	}

};

int main()
{
	NewAuto NewAuto2;
	AutoFactory BMW_factory;

	Create* BMW = NewAuto2.createAuto(BMW_factory);
	
	BMW->Enter();
	/*NewAuto2.createAuto(BMW_factory);*/
	BMW->info();
	BMW->Enter();
	BMW->info();
	BMW->Enter();
	BMW->info();
	
	BMW->Sav();
	BMW->Reader();
	BMW->Searcher();

	
}