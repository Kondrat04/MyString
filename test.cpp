//
// Created by kondr on 01.11.2020.
//
#include <stdio.h>
#include "MyString.h"

int main()
{
    MyString *str_obj_1 = new MyString();
    MyString const str_obj_2("charString");
    MyString str_obj_3({'q', 'w', 'e', 'r', 't', 'y'});
    MyString str_obj_4(str_obj_2);
    MyString str_obj_5(std::string("stdstring"));
    MyString str_obj_6("justpartofthis", 8);
    MyString str_obj_7(3, 'a');

    str_obj_1->Insert(0, "newStr");
    str_obj_3.Insert(3, 4, 'a');
    str_obj_4.Insert(4, "thispart", 4);
    str_obj_5.Insert(1, std::string("aaaaaaaaa"));
    str_obj_6.Insert(8, std::string("ofus"), 4);
    str_obj_7.Erase(1, 2);

    printf("\'\'.Insert(0, \"newStr\") == %s\n", str_obj_1->c_str());
    printf("\'qwerty\'.Insert(3, 4, \'a\') == %s\n", str_obj_3.c_str());
    printf("\'charString\'.Insert(4, \"thispart\", 4) == %s\n", str_obj_4.c_str());
    printf("\'stdstring\'.Insert(1, std::string(\"aaaaaaaaa\")) == %s\n", str_obj_5.c_str());
    printf("\'justpart\'.Insert(8, std::string(\"ofus\"), 4) == %s\n", str_obj_6.c_str());
    printf("\'aaa\'.Erase(1, 2) == %s\n", str_obj_7.c_str());

    str_obj_7.Append("bcdefg");
    printf("\'a\'.Append(\"bcdefg\") == %s\n", str_obj_7.c_str());

    str_obj_7.Replace(3, 2, "HELLO");
    printf("\'abcdefg\'.Replace(3, 2, \"HELLO\") == %s\n", str_obj_7.c_str());

    printf("\'charString\'.SubStr(4) == %s\n", str_obj_2.SubStr(4));
    printf("\'abcHELLOfg\'.SubStr(3, 5) == %s\n", str_obj_7.SubStr(3, 5));

    printf("\'charString\'.Find(\"Str\", 3) == %d\n", str_obj_2.Find("Str", 3));

    printf("\'justpartofus\' + \'qweaaaarty\' == %s\n", (str_obj_6 + str_obj_3).c_str());

    str_obj_4 = "newStr";
    printf("Assignment test : %s\n", str_obj_4.c_str());
    str_obj_4 += "1111";
    printf("Assignment test : %s\n", str_obj_4.c_str());
    printf("Indexing test : %c\n", (str_obj_4)[3]);

    printf("Is newStr >= newStr1111? Answer : %d\n", *str_obj_1 >= str_obj_4);
    printf("Is newStr < newStr1111? Answer : %d\n", *str_obj_1 < str_obj_4);
    printf("Is newStr > abcHELLOfg? Answer : %d\n", *str_obj_1 > str_obj_7);
    *str_obj_1 += "1111";
    printf("Is newStr1111 == newStr1111? Answer : %d\n", *str_obj_1 == str_obj_4);

    printf("Size of %s is %d\n",str_obj_4.c_str(), str_obj_4.size());
    printf("Capacity of %s is %d\n",str_obj_4.c_str(), str_obj_4.capacity());
    str_obj_4.shrink_to_fit();
    printf("...Shrink to fit...\n");
    printf("Capacity of %s is %d\n",str_obj_4.c_str(), str_obj_4.capacity());
    printf("Is empty? Answer : %d\n", str_obj_4.empty());
    str_obj_4.clear();
    printf("...Clearing...\n");
    printf("Is empty? Answer : %d\n", str_obj_4.empty());
    std::cout << str_obj_3;
}
