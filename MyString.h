//
// Created by kondr on 10.10.2020.
//

#include <memory.h>
#include <initializer_list>
#include <string>
#include <iostream>

#ifndef MYSTRING_MYSTRING_H
#define MYSTRING_MYSTRING_H

typedef unsigned int t_dword;
static const t_dword DEFAULT_BLOCK = 100; //size of memory block that dynamically allocated for a string
class MyString
{
public:
    //Constructors
    MyString();
    MyString(const  MyString &base_string_object);
    MyString(const char* base_string);
    MyString(std::initializer_list<char> list);
    MyString(std::string string);
    MyString(const char* base_string, t_dword count);
    MyString(t_dword count, char symbol);
    //Destructor
    ~MyString();

    void Insert(t_dword index, const char * string);
    void Insert(t_dword index, t_dword count, char symbol);
    void Insert(t_dword index, const char * string, t_dword count);
    void Insert(t_dword index, std::string string);
    void Insert(t_dword index, std::string string, t_dword count);

    void Erase(t_dword index, t_dword count);

    void Append(const char * string);
    void Append(t_dword count, char symbol);
    void Append(const char * string, t_dword index, t_dword count);
    void Append(std::string string);
    void Append(std::string string, t_dword index, t_dword count);

    void Replace(t_dword index, t_dword count, const char * string);
    void Replace(t_dword index, t_dword count, std::string string);

    const char * SubStr(t_dword index) const;
    const char * SubStr(t_dword index, t_dword count);

    t_dword Find(const char * substring, t_dword index) const;
    t_dword Find(const char * substring) const;
    t_dword Find(std::string substring, t_dword index) const;
    t_dword Find(std::string substring) const;

    MyString &operator +(const MyString &string_object) const;
    MyString &operator +(const char * string) const;
    MyString &operator +(const std::string string) const;

    MyString &operator =(const char * string);
    MyString &operator =(std::string string);
    MyString &operator =(char symbol);

    void operator +=(const char * string);
    void operator +=(std::string string);

    char operator [](t_dword index) const;

    bool operator <(MyString &string_object) const;
    bool operator >(MyString &string_object) const;
    bool operator ==(MyString &string_object) const;
    bool operator !=(MyString &string_object) const;
    bool operator <=(MyString &string_object) const;
    bool operator >=(MyString &string_object) const;

    const char * c_str() const;
    const void * data() const;
    t_dword size() const;
    t_dword length() const;
    bool empty() const;
    t_dword capacity() const;
    void shrink_to_fit();
    void clear();

    friend std::ostream& operator<<(std::ostream&, MyString&);
    friend std::istream& operator>>(std::istream&, MyString&);

private:
    //Filling area of memory started from pointer with count of symbols
    void StrFill(char *pointer, t_dword count, char symbol);
    //Return length of the null-terminated string
    t_dword StrLen(const char *str) const;
    char * a_data_; //Pointer to the string data
    char * a_trash_; //Pointer to the additional array
    t_dword a_allocated_memory; //Current amount of allocated memory in bytes
    t_dword a_length; //Current length of the string
};

#endif //MYSTRING_MYSTRING_H

