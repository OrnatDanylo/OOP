#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
using namespace std;

class Fraction
{
	friend istream& operator>>(istream& in, Fraction& Fr)
	{
		return in >> *Fr.numerator >> *Fr.denominator;
	}
	friend ostream& operator<<(ostream& out, const Fraction& Fr)
	{
		return out << *Fr.numerator << "/" << *Fr.denominator << endl;
	}

private:
	int *numerator = new int;
	int	*denominator = new int;

public:
	Fraction() { *numerator = 0; *denominator = 10; cout << "Constructor complete \n"; }

	Fraction(const Fraction &CopyFromME) 
	{
		this->numerator = CopyFromME.numerator;
		this->denominator = CopyFromME.denominator;
		cout << "Constructor complete \n";
	}
	Fraction(int a, int b) { *numerator = a; *denominator = b; cout << "Constructor complete \n";}

	~Fraction() { delete numerator; delete denominator; cout << "DeConstructor complete \n";}


	int Get_Num() { return *this->numerator; }

	int Get_Den() { return *this->denominator; }


	void Set_Num(int a) { *this->numerator = a; }

	void Set_Den(int b) { *this->denominator = b; }


	void Add(Fraction&, Fraction&); // Додавання

	void Sub(Fraction&, Fraction&);// Віднімання

	void Multi(Fraction&, Fraction&);//Множення

	void Div(Fraction&, Fraction&);// Ділення

	void Simpl(void); // спрощення
};



void Fraction::Add(Fraction& First, Fraction& Second)// Додавання
{
	this->Set_Num(First.Get_Num() * Second.Get_Den() + Second.Get_Num() * First.Get_Den());
	this->Set_Den(First.Get_Den() * Second.Get_Den());
}

void Fraction::Sub(Fraction& First, Fraction& Second)//Віднімання
{
	this->Set_Num(First.Get_Num() * Second.Get_Den() - Second.Get_Num() * First.Get_Den());
	this->Set_Den(First.Get_Den() * Second.Get_Den());
}

void Fraction::Multi(Fraction& First, Fraction& Second)//Множення
{
	this->Set_Num(First.Get_Num() * Second.Get_Num());
	this->Set_Den(First.Get_Den() * Second.Get_Den());
}

void Fraction::Div(Fraction& First, Fraction& Second)// Ділення
{
	this->Set_Num(First.Get_Num() * Second.Get_Den());
	this->Set_Den(First.Get_Den() * Second.Get_Num());
}

void Fraction::Simpl(void)
{
	int nod = 1;
	for (int i = this->Get_Num(); i > 0; i--) {
		if (this->Get_Num() % i == 0 && this->Get_Den() % i == 0) {
			nod = i;
			break;
		}
	}
	int a = this->Get_Num();
	this->Set_Num(a /= nod);

	a = this->Get_Den();
	this->Set_Den(a /= nod);
}

void main(void)
{
	Fraction *First = new Fraction; // ddsl lhj,sd
	cout << "First:\n";
	cin >> *First;
	First->Simpl();
	cout << "First:" << *First;

	Fraction *Second =new Fraction;
	cout << "Second:\n";
	cin >> *Second;
	Second->Simpl();
	cout << "Second:" << *Second;

	Fraction SecondCopy(*Second);

	// First(15,2); - ввід для конструктора

	Fraction *Result = new Fraction;

	Result->Add(*First, SecondCopy);
	Result->Simpl();
	cout << "Addition " << *Result;

	Result->Sub(*First, SecondCopy);
	Result->Simpl();
	cout << "Subtraction " << *Result;

	Result->Multi(*First, SecondCopy);
	Result->Simpl();
	cout << "Multiplication " << *Result;

	Result->Div(*First, SecondCopy);
	Result->Simpl();
	cout << "Division " << *Result;

	delete(Result);
	delete(First);
	delete(Second);

	getchar();
	getchar();
}
