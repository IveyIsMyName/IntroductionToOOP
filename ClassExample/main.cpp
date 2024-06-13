#include <iostream>
#include <string>

class Person {
private:
    std::string name;
    int age;

public:
    // Конструктор по умолчанию
    Person() : name("Unknown"), age(0) {
        std::cout << "Default constructor called" << std::endl;
    }

    // Параметризованный конструктор
    Person(const std::string& name, int age) : name(name), age(age) {
        std::cout << "Parameterized constructor called" << std::endl;
    }

    // Конструктор копирования
    Person(const Person& other) : name(other.name), age(other.age) {
        std::cout << "Copy constructor called" << std::endl;
    }

    // Перемещающий конструктор (если требуется поддержка семантики перемещения)
    Person(Person&& other) noexcept : name(std::move(other.name)), age(other.age) {
        std::cout << "Move constructor called" << std::endl;
    }

    // Деструктор
    ~Person() {
        std::cout << "Destructor called for " << name << std::endl;
    }

    // Метод для получения имени
    std::string getName() const {
        return name;
    }

    // Метод для задания имени
    void setName(const std::string& name) {
        this->name = name;
    }

    // Метод для получения возраста
    int getAge() const {
        return age;
    }

    // Метод для задания возраста
    void setAge(int age) {
        this->age = age;
    }

    // Перегрузка оператора присваивания
    Person& operator=(const Person& other) {
        if (this == &other)
            return *this; // Самоприсваивание, ничего не делаем

        name = other.name;
        age = other.age;
        std::cout << "Assignment operator called" << std::endl;
        return *this;
    }

    // Перемещающий оператор присваивания (если требуется поддержка семантики перемещения)
    Person& operator=(Person&& other) noexcept {
        if (this == &other)
            return *this; // Самоприсваивание, ничего не делаем

        name = std::move(other.name);
        age = other.age;
        std::cout << "Move assignment operator called" << std::endl;
        return *this;
    }

    // Метод, выводящий информацию о человеке
    void display() const {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Создание объектов разными способами
    Person person1; // Конструктор по умолчанию
    Person person2("Alice", 30); // Параметризованный конструктор
    Person person3(person2); // Конструктор копирования
    Person person4(std::move(person2)); // Перемещающий конструктор

    person1.display();
    person3.display();
    person4.display();

    // Использование методов класса
    person1.setName("Bob");
    person1.setAge(25);
    person1.display();

    // Перегрузка оператора присваивания
    person3 = person1;
    person3.display();

    return 0;
}
