#include<iostream>
using namespace std;
using std::cin;
using std::cout;
#define delimiter "\n--------------------------------------------------------------------\n"

/// Объявление класса (Class declaration)

class String
{
	int size;
	char* str;
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//				Constructors:
	explicit String(int size = 80);
	String(const char* str);
	String(const String& other);
	String(String&& other)noexcept;
	~String();

	//				 Operators:
	String& operator=(const String& other);
	String& operator=(String&& other)noexcept;
	char operator[](int i)const;
	char& operator[](int i);

	//				  Methods:
	void print()const;
};

/// Конец объявления класса (Class declaration end)

///---------------------------------------------------------------///

/// Определение класса (Class definition)

int String::get_size()const
{
	return size;
}
const char* String::get_str()const
{
	return str;
}
char* String::get_str()
{
	return str;
}

//				Constructors:
String::String(int size) :size(size), str(new char[size] {})
{
	//this->size = size;
	//this->str = new char[size] {};
	cout << "1ArgConstructor:\t" << this << endl;
}
String::String(const char* str) :String(strlen(str) + 1)
{
	//this->size = strlen(str) + 1;
	//this->str = new char[size] {};
	for (int i = 0; str[i]; i++)
	{
		this->str[i] = str[i];
	}
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	//Deep Copy (Побитовое копирование)
	//this->size = other.size;
	//this->str = new char[size] {};
	/*for (int i = 0; i < size; i++)
	{
		this->str[i] = other.str[i];
	}*/
	cout << "CopyConstructor:\t" << this << endl;
}
String::String(String&& other)noexcept :size(other.size), str(other.str) //r-value reference
{
	//Shallow copy:
	//this->size = other.size;
	//this->str = other.str;

	//Reset other:
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}
String::~String()
{
	delete[] str;
	cout << "Destructor:\t\t" << this << endl;
}

//				 Operators:
String& String::operator=(const String& other)
{
	//Deep copy
	if (this == &other) return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}
String& String::operator=(String&& other)noexcept
{
	if (this == &other) return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t\t" << this << endl;
	return *this;
}
char String::operator[](int i)const
{
	return this->str[i];
}
char& String::operator[](int i)
{
	return this->str[i];
}

//				  Methods:
void String::print()const
{
	cout << "Obj:\t\t\t" << this << endl;
	cout << "String:\t\t\t" << str << endl;
	cout << "Addr\t\t\t" << &str << endl;
	cout << "Size:\t\t\t" << size << endl;
	cout << delimiter << endl;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	cout << "Operator + " << endl;
	String buffer(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		buffer[i] = left[i];
		//buffer.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		buffer[i + left.get_size() - 1] = right[i];
		//buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return buffer;
}
/// Конец определения класса (Class definiton end)

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