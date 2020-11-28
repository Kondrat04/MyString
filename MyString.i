%module mystring

%{
#include <initializer_list>
#include "MyString.h"
%}

%include "MyString.h"

%extend MyString{
    const char& __getitem__(unsigned int i) {
        return (*self)[i];
    }
}