#include <iostream>
#include <cstring>
#include <cstdlib>

#define MAX_NAME_LENGTH 100

using namespace std;

struct Person {
    size_t pesel_number;
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    unsigned int age;
    unsigned int books_count;
};

const char* first_names[] = {
    "Marcin",
    "Marek",
    "Tomasz",
    "Krystian",
    "Waldek",
    "Roman",
    "Piotrek",
    "Tadeusz",
    "Nikodem",
    "Karol"
};

const char* last_names[] = {
    "Kowalski",
    "Duda",
    "Pirek",
    "Wrona",
    "Walski",
    "Trodejski",
    "Listek",
    "Koconowski",
    "Janicki",
    "Kreda"
};

Person* create_person() {
    Person* person = new Person{};

    person->pesel_number = (rand() % 10) + (rand() % 100) + (rand() % 1000) + 10000;
    
    strcpy_s(person->first_name, MAX_NAME_LENGTH, first_names[rand() % 10]);
    strcpy_s(person->last_name, MAX_NAME_LENGTH, last_names[rand() % 10]);

    person->age = (rand() % 50) + 20;
    person->books_count = 1;

    return person;
}

Person** create_people(size_t size) {
    Person** people = new Person * [size] {};

    for (int i = 0; i < size; i++) {
        people[i] = create_person();
    }

    return people;
}

Person*** create_book_people(size_t book_size, size_t people_size) {
    Person*** book_people = new Person * *[book_size] {};
    
    for (int i = 0; i < book_size; i++) {
        book_people[i] = create_people(people_size);
    }

    return book_people;
}

void print_person(Person* person) {
    cout << "===== Person details =====" << endl;
    cout << "PESEL number: " << person->pesel_number << endl;
    cout << "First name: " << person->first_name << endl;
    cout << "Last name: " << person->last_name << endl;
    cout << "Person age: " << person->age << endl;
    cout << "Person books count: " << person->books_count;
}

void print_people(Person**& people, size_t size) {
    cout << "=========== Book of people " << size << " ===========" << endl << endl;

    for (int i = 0; i < size; i++) {
        print_person(people[i]);
        cout << endl << endl;
    }
}

void print_book_people(Person***& book_people, size_t book_size, size_t people_size) {
    cout << "=============== Books of people " << book_size << " ===============" << endl << endl;

    for (int i = 0; i < book_size; i++) {
        print_people(book_people[i], people_size);
    }
}

void delete_person(Person*& person) {
    delete person;
    person = nullptr;
}

void delete_people(Person**& people, size_t size) {
    for (int i = 0; i < size; i++) {
        delete_person(people[i]);
    }

    delete[] people;
    people = nullptr;
}

void delete_book_people(Person***& book_people, size_t book_size, size_t people_size) {
    for (int i = 0; i < book_size; i++) {
        delete_people(book_people[i], people_size);
    }

    delete[] book_people;
    book_people = nullptr;
}

int main()
{
    //Person* person = create_person();
    //print_person(person);
    //delete_person(person);

    const unsigned int PEOPLE_SIZE = 3;

    //Person** people = create_people(PEOPLE_SIZE);
    //print_people(people, PEOPLE_SIZE);
    //delete_people(people, PEOPLE_SIZE);

    const unsigned int SIZE_BOOK_PEOPLE = 5;

    Person*** book_people = create_book_people(SIZE_BOOK_PEOPLE, PEOPLE_SIZE);
    print_book_people(book_people, SIZE_BOOK_PEOPLE, PEOPLE_SIZE);
    delete_book_people(book_people, SIZE_BOOK_PEOPLE, PEOPLE_SIZE);
}
