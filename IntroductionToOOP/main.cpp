#include "Point.h"

//#define STRUCT_POINT
//#define CONSTRUCTORS_CHECK
#define DISTANCE_CHECK
//#define ASSIGNMENT_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define COMPARISON_OPERATORS_CHECK

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


}
