#include<iostream>
using namespace std;
using std::cout;
using std::cin;

#define delimiter cout << "\n----------------------------------------------\n"; 
//#define STRUCT_POINT
//#define CONSTRUCTORS_CHECK
//#define DISTANCE_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS_CHECK

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

	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0) // Универсальный конструктор
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Point()
	{
		cout << "Destructor: \t\t" << this << endl;
	}

	//				Operators:
	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;

		return *this;
	}
	Point& operator++()  //Prefix increment
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
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
	
#ifdef CONSTRUCTORS_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	A.print();
	delimiter;

	Point B = 5;
	B.print();
	delimiter;
	
	Point C(2, 3);
	C.print();
	delimiter;

	Point D = C;		//Copy constructor
	D.print();
	delimiter;

	Point E;
	E = D;				//Copy assignment
	E.print();
	delimiter;
	
	cout << "A: " << A.get_x() << "\t" << A.get_y() << endl;
	cout << "B: " << B.get_x() << "\t" << B.get_y() << endl;
	cout << "C: " << C.get_x() << "\t" << C.get_y() << endl;
	cout << "D: " << D.get_x() << "\t" << D.get_y() << endl;
	cout << "E: " << E.get_x() << "\t" << E.get_y() << endl;
	delimiter;

#endif // CONSTRUCTORS_CHECK

#ifdef DISTANCE_CHECK
	Point A;
	A.set_x(2);
	A.set_y(3);
	Point B(7, 8);
	A.print();
	B.print();
	delimiter;

	cout << "Расстояние от точки A до точки B:\t " << A.Distance(B) << endl;
	delimiter;
	cout << "Расстояние от точки B до точки A:\t " << Distance(B, A) << endl;
	delimiter;
#endif // DISTANCE_CHECK

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	
	a = b = c = 0;
	delimiter;
	cout << a << "\t" << b << "\t" << c << endl;
	delimiter;

	Point A, B, C;
	delimiter;

	A = B = C = Point(2, 3);	//Point(2,3) - явно вызываем конструктор
	delimiter;					//и создаем временный безымянный объект
								//этот объект и передается как параметр
								//в первый CopyAssignment.
	A.print();
	B.print();
	C.print();
	delimiter;
#endif // ASSIGNMENT_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	Point A(2, 3);
	A.print();

	Point B(7, 8);
	B.print();

	Point C = A + B;
	C.print();

	Point D = C++;
	C.print();
	D.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef COMPARISON_OPERATORS_CHECK
	//cout << (2 == 3) << endl;
	Point A(2, 3);
	Point B(2, 3);
	//cout << (A == B) << endl;
	cout << (Point(2, 3) == Point(7, 8)) << endl;
#endif // COMPARISON_OPERATORS_CHECK

	Point A(2, 3);
	
	cout << A << endl;
}
