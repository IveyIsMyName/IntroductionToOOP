#include "Point.h"

double Point::get_x()const
{
	return x;
}
double Point::get_y()const
{
	return y;
}
void Point::set_x(double x)
{
	this->x = x;
}
void Point::set_y(double y)
{
	this->y = y;
}

Point::Point(double x, double y) // ”ниверсальный конструктор
{
	this->x = x;
	this->y = y;
	cout << "Constructor:\t\t" << this << endl;
}
Point::Point(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "CopyConstructor:\t" << this << endl;
}
Point::~Point()
{
	cout << "Destructor: \t\t" << this << endl;
}

//				Operators:
Point& Point::operator=(const Point& other)
{
	this->x = other.x;
	this->y = other.y;
	cout << "CopyAssignment:\t\t" << this << endl;

	return *this;
}
Point& Point::operator++()  //Prefix increment
{
	x++;
	y++;
	return *this;
}
Point Point::operator++(int)
{
	Point old = *this;
	x++;
	y++;
	return old;
}
//				Methods:
void Point::print()const
{
	cout << "X = " << x << "\tY = " << y << endl;
}
double Point::Distance(const Point& other)const
{
	double dx = this->x - other.x;
	double dy = this->y - other.y;
	double distance = sqrt(dx * dx + dy * dy);

	return distance;
}
double Distance(const Point& A, const Point& B)
{
	double dx = B.get_x() - A.get_x();
	double dy = B.get_y() - A.get_y();

	return sqrt(dx * dx + dy * dy);
}
Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}
bool operator==(const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;*/
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}
std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	os << "X = " << obj.get_x() << "\tY = " << obj.get_y();
	return os;
}