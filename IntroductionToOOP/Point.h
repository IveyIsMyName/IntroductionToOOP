#pragma once
#include<iostream>
using namespace std;
using std::cout;
using std::cin;

#define delimiter cout << "\n----------------------------------------------\n"; 

class Point;
double Distance(const Point& A, const Point& B);
Point operator+(const Point& left, const Point& right);
bool operator==(const Point& left, const Point& right);
std::ostream& operator<<(std::ostream& os, const Point& obj);

class Point
{
	double x;
	double y;
public:
	double get_x()const;
	double get_y()const;
	void set_x(double x);
	void set_y(double y);
	Point(double x = 0, double y = 0);
	Point(const Point& other);
	~Point();

	//				Operators:
	Point& operator=(const Point& other);
	Point& operator++();
	Point operator++(int);
	//				Methods:
	void print()const;
	double Distance(const Point& other)const;
};