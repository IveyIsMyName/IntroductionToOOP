#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // ����������� �� ���������
    Person() : name("Unknown"), age(0) {
        std::cout << "Default constructor called" << std::endl;
    }

    // ����������������� �����������
    Person(const std::string& name, int age) : name(name), age(age) {
        std::cout << "Parameterized constructor called" << std::endl;
    }

    // ����������� �����������
    Person(const Person& other) : name(other.name), age(other.age) {
        std::cout << "Copy constructor called" << std::endl;
    }

    // ������������ ����������� (���� ��������� ��������� ��������� �����������)
    Person(Person&& other) noexcept : name(std::move(other.name)), age(other.age) {
        std::cout << "Move constructor called" << std::endl;
    }

    // ����������
    ~Person() {
        std::cout << "Destructor called for " << name << std::endl;
    }

    // ����� ��� ��������� �����
    std::string getName() const {
        return name;
    }

    // ����� ��� ������� �����
    void setName(const std::string& name) {
        this->name = name;
    }

    // ����� ��� ��������� ��������
    int getAge() const {
        return age;
    }

    // ����� ��� ������� ��������
    void setAge(int age) {
        this->age = age;
    }

    // ���������� ��������� ������������
    Person& operator=(const Person& other) {
        if (this == &other)
            return *this; // ����������������, ������ �� ������

        name = other.name;
        age = other.age;
        std::cout << "Assignment operator called" << std::endl;
        return *this;
    }

    // ������������ �������� ������������ (���� ��������� ��������� ��������� �����������)
    Person& operator=(Person&& other) noexcept {
        if (this == &other)
            return *this; // ����������������, ������ �� ������

        name = std::move(other.name);
        age = other.age;
        std::cout << "Move assignment operator called" << std::endl;
        return *this;
    }

    // �����, ��������� ���������� � ��������
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // �������� �������� ������� ���������
    Person person1; // ����������� �� ���������
    Person person2("Alice", 30); // ����������������� �����������
    Person person3(person2); // ����������� �����������
    Person person4(std::move(person2)); // ������������ �����������

    person1.display();
    person3.display();
    person4.display();

    // ������������� ������� ������
    person1.setName("Bob");
    person1.setAge(25);
    person1.display();

    // ���������� ��������� ������������
    person3 = person1;
    person3.display();

    return 0;
}
