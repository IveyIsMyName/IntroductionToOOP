#pragma once
#include<iostream>
using namespace std;

class Fraction;
Fraction operator*(Fraction& left, Fraction& right);

class Fraction
{
	int integer;
	int numerator;
	int denominator;

public:
	int get_integer()const;
	int get_numerator()const;
	int get_denominator()const;
	void set_integer(int integer);
	void set_numerator(int numerator);
	void set_denominator(int denominator);
	Fraction();
	Fraction(int integer);
	Fraction(int numerator, int denominator);
	Fraction(int integer, int numerator, int denominator);
	Fraction(const Fraction& other);
	~Fraction();
	//Operators
	Fraction& operator=(const Fraction& other);
	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);

	//Methods
	Fraction& to_improper();
	Fraction& to_proper();
	void print()const;
};