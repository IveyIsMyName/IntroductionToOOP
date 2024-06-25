#include<iostream>
using namespace std;
#define delimiter "\n--------------------------------------------------------------------\n"

class String
{
	int size;
	char* str;
public:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	char* get_str()
	{
		return str;
	}

	//				Constructors:
	String(const char* str)
	{
		this->size = strlen(str) + 1;
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)
		{
			this->str[i] = str[i];
		}
		cout << "Constructor:\t\t" << this << endl;
	}
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "1ArgConstructor:\t" << this << endl;
	}
	String(const String& other)
	{
		//Deep Copy (Побитовое копирование)
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
		{
			this->str[i] = other.str[i];
		}
		cout << "CopyConstructor:\t\t" << this << endl;
	}
	~String()
	{
		delete[] str;
		cout << "Destructor:\t\t" << this << endl;
	}

	//				 Operators:
	String& operator=(const String& other)
	{
		if (this == &other) return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	char operator[](int i)const
	{
		return this->str[i];
	}
	char& operator[](int i)
	{
		return this->str[i];
	}

	//				  Methods:
	void print()const
	{
		cout << "Obj:\t\t\t" << this << endl;
		cout << "String:\t\t\t" << str << endl;
		cout << "Addr\t\t\t" << &str << endl;
		cout << "Size:\t\t\t" << size << endl;
	}
};
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

void main()
{
	setlocale(LC_ALL, "");

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
}