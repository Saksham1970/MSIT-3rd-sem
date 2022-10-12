#include <iostream> // Header files

class String
{
    // The class for user made Character String

private:
    char *_value;
    int _length = 0;

    // Constructor with direct value and length
    String(char *value, int length)
    {
        this->_value = value;
        this->_length = length;
    }

public:
    // Constructor
    String(const char *value)
    {
        while (value[this->_length] != '\0')
            this->_length++;

        this->_value = new char[this->_length + 1];
        for (int i = 0; i <= this->_length; i++)
        {
            this->_value[i] = value[i];
        }
    }

    // Default Constructor
    String()
    {
        this->_length = 0;
        char *value = new char[1];
        value[0] = '\0';
        this->_value = value;
    }

    // + Operator overloading for Concatenation
    String operator+(const String &other)
    {
        int new_len = this->_length + other._length;
        char *value = new char[new_len + 1];
        for (int i = 0; i < this->_length; i++)
        {
            value[i] = this->_value[i];
        }
        for (int i = 0; i <= other._length; i++)
        {
            value[this->_length + i] = other._value[i];
        }
        return String(value, new_len);
    }

    // = Operator overloading for copying
    void operator=(const String &other)
    {
        this->_length = other._length;
        char *value = new char[this->_length + 1];
        for (int i = 0; i <= this->_length; i++)
        {
            value[i] = other._value[i];
        }
        free(this->_value);
        this->_value = value;
    }

    // <= Operator overloading for comparison
    bool operator<=(const String &other)
    {
        for (int i = 0; i <= this->_length; i++)
        {
            if (this->_value[i] != other._value[i])
            {
                if (this->_value[i] < other._value[i])
                    return true;
                else
                    return false;
            }
        }
        return true;
    }

    // returning the length of the string
    int length()
    {
        return _length;
    }

    // converting the string to upper case
    void toUpper()
    {
        for (int i = 0; i < this->_length; i++)
        {
            this->_value[i] = toupper(this->_value[i]);
        }
    }

    // Converting the string to lower case
    void toLower()
    {
        for (int i = 0; i < this->_length; i++)
        {
            this->_value[i] = tolower(this->_value[i]);
        }
    }

    // ostream operator overloading for printing
    friend std::ostream &operator<<(std::ostream &output, const String &string)
    {
        output << string._value;
        return output;
    }
};

// Driver code
int main()
{

    String s1("Saksham");
    String s2("Gupta");

    // Using of concatenation and copy
    String s3 = s1 + s2;

    // Using of copy
    String s4;
    s4 = s1;

    std::cout << "String 1 = " << s1 << ", String 2 = " << s2 << std::endl;
    std::cout << "Concatenation of String 1 and 2 (String 3) = " << s3 << std::endl;
    std::cout << "Copy of String 1 (String 4) = " << s4 << std::endl;
    std::cout << "Comparison (String 1 <= String 3) = " << (s1 <= s3) << std::endl; // less than
    std::cout << "Comparison (String 1 <= String 2) = " << (s1 <= s2) << std::endl; // greater than
    std::cout << "Comparison (String 1 <= String 1) = " << (s1 <= s1) << std::endl; // equal
    std::cout << "Length of String 1 = " << s1.length() << std::endl;
    s1.toLower();
    std::cout << "String 1 toLower() = " << s1 << std::endl;
    s1.toUpper();
    std::cout << "String 1 toUpper() = " << s1 << std::endl;
    std::cout << "Copy didn't change (String 4) = " << s4 << std::endl;

    return 0;
}
