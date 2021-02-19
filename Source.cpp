#include <stdio.h>
#include <stdlib.h>
#include <cmath>
#include <iostream>
using namespace std;

class Fraction 
{
	friend istream& operator>>(istream& in, Fraction& Fr)
	{
		return in >> Fr.numerator >> Fr.denominator;
	}
	friend ostream& operator<<(ostream& out, const Fraction& Fr)
	{
		return out << Fr.numerator << "/" << Fr.denominator << endl;
	}

private:
	int numerator;
	int	denominator;

public:
	Fraction() {}
	Fraction(int a, int b) { numerator = a; denominator = b; }
	~Fraction() {}

	int Get_Num() { return numerator; }

	int Get_Den() { return denominator; }



	void Set_Num(int a) { numerator = a; }

	void Set_Den(int b) { denominator = b; }


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
	Fraction First; // ddsl lhj,sd
	cout << "First:\n";
	cin >> First;
	First.Simpl();
	cout << "First " << First;

	Fraction Second;
	cout << "Second:\n";
	cin >> Second;
	Second.Simpl();
	cout << "Second " << Second;

	// First(15,2); - ввід для конструкова

	Fraction Result;

	Result.Add(First, Second);
	Result.Simpl();
	cout << "Addition " << Result;

	Result.Sub(First, Second);
	Result.Simpl();
	cout << "Subtraction " << Result;

	Result.Multi(First, Second);
	Result.Simpl();
	cout << "Multiplication " << Result;

	Result.Div(First, Second);
	Result.Simpl();
	cout << "Division " << Result;
}
