#include "Fraction.h"

//#define CONSTRUCTORS_CHECK
void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	Fraction A;			//Default constructor
	A.print();

	Fraction B = 6;		// 1 Arg constructor
	B.print();

	Fraction C(1, 16);	// 2 Arg constructor
	C.print();

	Fraction D(4, 6, 9);// 3 Arg constructor
	D.print();

	Fraction E = C;		//Copy constructor
	E.print();

	Fraction F;			// Copy assignment
	F = D;
	F.print();

#endif // CONSTRUCTORS_CHECK
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	A.to_improper().print();
	A.to_proper().print();

	Fraction C = A * B;
	C.print();
}