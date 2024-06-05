#include<iostream>
using namespace std;

//#define STRUCT_POINT

class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}
	Point(double x, double y)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor: \t\t" << this << endl;
	}

	//				Methods:
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
	double Distance(const Point& other)const
	{
		double dx = this->x - other.x;
		double dy = this->y - other.y;
		double distance = sqrt(dx * dx + dy * dy);

		return distance;
	}
};
double Distance(const Point& A, const Point& B)
{
	double dx = B.get_x() - A.get_x();
	double dy = B.get_y() - A.get_y();

	return sqrt(dx * dx + dy * dy);
}

void main()
{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	Point A;		//Создание объекта 'A' типа 'Point'
					//Создание экземпляра 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT

	Point A;
	A.set_x(2);
	A.set_y(3);
	A.print();
	Point B (6, 8);	
	B.print();

	//cout <<"A: " << A.get_x() << "\t" << A.get_y() << endl;
	//cout <<"B: " << B.get_x() << "\t" << B.get_y() << endl;
	
	cout << "Расстояние от точки A до точки B:\t " << A.Distance(B) << endl;
	cout << "Расстояние от точки B до точки A:\t " << Distance(B,A) << endl;
}
