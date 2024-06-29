#include "String.h"

///---------------------------------------------------------------///

//#define CONSTRUCTORS_CHECK
//#define OPERATOR_PLUS_CHECK
//#define OPERATOR_MOVE_ASSIGNMENT
#define CALLING_CONSTRUCTORS

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
	String str1;			//Default constructor
	str1.print();
	cout << delimiter << endl;

	String str2(8);			//Single-argument constructor
	str2.print();
	cout << delimiter << endl;

	String str3 = "Hello";
	str3 = str3;
	str3.print();
	cout << delimiter << endl;

	String str4 = "World";
	str4.print();
	cout << delimiter << endl;

	cout << str3 << endl;
	cout << str4 << endl;
	cout << delimiter << endl;

	String str5;
	str5 = str3 + str4;
	str5.print();
	cout << str5 << endl;
#endif 

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";

	cout << delimiter << endl;
	String str3 = str1 + str2;
	cout << str3 << endl;
	cout << delimiter << endl;
	
	cout << str1 << endl;
	cout << str2 << endl;
	cout << delimiter << endl;
	
#endif // OPERATOR_PLUS_CHECK
	
#ifdef OPERATOR_MOVE_ASSIGNMENT
	String str1 = "Hello";
	String str2 = "World";

	cout << str1 << endl;
	cout << str2 << endl;

	String str3;
	cout << delimiter << endl;
	str3 = str1 + str2; //MoveAssignment
	cout << delimiter << endl;
	cout << str3 << endl;
#endif // OPERATOR_MOVE_ASSIGNMENT

#ifdef CALLING_CONSTRUCTORS
	String str1;	 //Default constructor
	str1.print();

	//String str2 = 8; //Single-Argument construcor 'int', explicit вызвать невозможно
	String str2(8); //explicit constructor можно вызвать только так
	str2.print();

	String str3 = "Hello"; //Single-Argument constructor 'char'
	str3.print();

	//String str4();			//Здесь НЕ вызывается никакой конструкто, и не создается объект,
							//здесь оъявляется функция str4(), которая не принимает никаких параметров
							//и возвращается значение типа "String"
							//т.е., таким образом DefaultConstructor вызвать невозможно.
	//str4.print();
	//Если нужно вызвать DefaultConstructor, это делается следующим образом:
	//String str6 = str3;		//CopyConstructor
	//String str6(str3);		//CopyConstructor
	String str5{};				//Явный вызов конструтора по умолчанию
	str5.print();
	String str6{ str3 };		//CopyConstructor
	str6.print();
	String str7 = str5 + str6;
	str7.print();
	//Следовательно, абсолютно любой конструктор можно вызвать при помощи () или {}
#endif // CALLING_CONSTRUCTORS

}