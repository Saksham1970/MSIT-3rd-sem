#include <iostream>
#include <fstream>

class Student
{
private:
    char name[40];
    int age;
    float height;
    float weight;
    char sex;

public:
    void putdata();
    void getdata();
};

// Defining the function putdata() to enter the values of data members of an object.
void Student ::putdata()
{
    std::cout << "Enter the name : ";
    std::cin.getline(this->name, 40);
    std::cout << "Enter the age : ";
    std::cin >> this->age;
    std::cout << "Enter the height : ";
    std::cin >> this->height;
    std::cout << "Enter the weight : ";
    std::cin >> this->weight;
    std::cout << "Enter the sex : ";
    std::cin >> this->sex;
}

// Defining the function getdata() to read the values of data members of an object.
void Student ::getdata()
{
    std::cout << "The name is : " << this->name << "\n";
    std::cout << "The age is : " << this->age << "\n";
    std::cout << "The height is : " << this->height << "\n";
    std::cout << "The weight is : " << this->weight << "\n";
    std::cout << "The sex is : " << this->sex << "\n";
}

int main()
{
    // Creating an output stream
    std::ofstream OutputFile;

    // Calling the open function to write an object to a file
    OutputFile.open("9_object.txt");

    // Creating an object of A class
    Student student;

    // Calling the putdata() function
    student.putdata();

    // Calling the write() function to write an object to a file.
    OutputFile.write((char *)&student, sizeof(student));

    std::cout << "\nYour object is successfully stored in the file. \n";

    // Closing the output stream
    OutputFile.close();

    // Creating an input stream
    std::ifstream InputFile;

    // Calling the open function to read an object from a file
    InputFile.open("9_object.txt");

    // Creating an empty object of A class
    Student empty_student;

    std::cout << "\nReading the object from a file : \n";

    // Calling the read() function to read an object from a file and transfer its content to an empty object
    InputFile.read((char *)&empty_student, sizeof(empty_student));

    // Calling the getdata() function
    empty_student.getdata();

    // Closing the input stream
    InputFile.close();

    return 0;
}
