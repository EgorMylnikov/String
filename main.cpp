#define _ CRT_SECURE_NO_WARNINGS
#include<iostream>
using  std:: cin;
using  std::cout;
using  std::endl;

class String
{
	size_t size;//размер строки в байтах (size_t unsignet int)
	char* str;//адрес строки в динамической памяти 
public:
	size_t get_size()const
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
	//Constractors:
	explicit String(size_t cize = 80) 
	{
		this->size = cize;
		this->str = new char[size] {};
		cout << "DefaultConstructor: \t" << this << endl;
	}
	String(const char* str)
	{
		this->size = strlen(str)+1; 
		this ->str = new char[size] {};
		strcpy(this->str, str);
		cout << "Constructor:" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		strcpy(this->str, other.str);
		cout << "CopyConsrtuctor" << this << endl;
	}
	String(String&& other)
	{
		
		this-> size = other.size;
		this->str = other.str;
		other.str = nullptr;
		other.size = 0;
		cout << "MoveConstractor" << this << endl;

	}

	~String()
	{
		delete[] str;
		cout << "Destructor: \t" << this << endl;
	}

	//  Operators:
	String& operator =(const String& other)
	{
		//0) Проверяем не являчется ли принятый объект нашим объектом
		if (this == &other)return *this;
		//1)Удаляем старое значение объекта
		delete[] this->str;
		//2) Deep copy
		this->size = other.size;
		this->str = new char [size] {};
		strcpy(this->str, other.str);
		cout << "CopyAssignment" << this << endl;
		return *this;
	}
	String& operator =(String&& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		//Shallow copy:
		this->size = other.size;
		this->str = other.str;
		other.size = 0;
		other.str = nullptr;
		cout << "MoveAssignmtnt:" << this << endl;

	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	char& operator[](int i)
	{
		return str[i];
	}
	// Methods:
	void print()const
	{
		cout << "size:\t" << size << endl;
		cout << "Str:\t" << str << endl;
	}
	
};

String operator+(const String& left, const String& right)
{
	String cat(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
	{
		cat[i] = left[i];
	}
	for (int i = 0; i < right.get_size(); i++)
	{
		cat[i + left.get_size() - 1] = right[i];

	}
	return cat;
}

std::ostream& operator<<(std::ostream& os, const String& obj)
	{
		return os << obj.get_str();
	}
void main()
{
	setlocale(LC_ALL, "Rus");
	String str1(10);  //DefaultConstractor
	str1.print();

	String str2 = "Hello";
	str2 = str2;
	str2.print();

	String str3 = str2;//Copy constructor
	str3.print();

	String str4;
	str4 = str3; //CopyAssignment
	str4.print();

	String str1 = "Hello";
	cout << str1 << endl;
	String str2 = "World";
	cout << str2 << endl;


	String str3 = str1 + str2;
	cout << str3 << endl;

	String str3;
	str3 = str1 + str2;
	cout << str3 << endl;









}