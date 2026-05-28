#include "Array.hpp"
#include<iostream>

int main()
{

    /*int * a = new int();
    std::cout << *a << std::endl;
    delete a;*/

    //------------Construction with no parameter: Creates an empty array-------------------
    Array<int> num1;
    std::cout << "Construction with no parameter: num1.size(): " << num1.size() << std::endl; //should be 0
    std::cout << "num1[0]: ";
    try
    {
        std::cout << num1[0] << std::endl;
    }
    catch (const std::exception&)
    {
        std::cout << "Invalid index!" << std::endl;
    }
    std::cout << std::endl;


    //------------Construction with an unsigned int n as a parameter-------------------
    Array<int> num2(3);    
    //Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default.
    std::cout << "Construction with parameter: Array<int> num2(3): num2.size(): " << num2.size() << std::endl; // should be 3
    std::cout << std::endl;


    //----------Construction by copy -------------------
    Array<int> num3(num2);
    std::cout << "Construction by copy. After Array<int> num3(num2) -> num3[2]: " << num3[2] << std::endl; // should be 0, meaning num3 is no longer empty

    num2[0] = 10;
    num2[1] = 20;
    num2[2] = 30;

    num3[0] = 66;
    num3[1] = 77;
    num3[2] = 88;

    //Check if modifying either the original array or its copy after copying musn’t affect the other array
    std::cout << "After modifing both num2 and num3: num2[0]]: " << num2[0] << std::endl; // should be 10
    std::cout << "After modifing both num2 and num3: num3[0]]: " << num3[0] << std::endl; // should be 66
    std::cout << std::endl;


    //----------Assignement Operator-------------------
    num1 = num2;
    std::cout << "Construction by Assignement. After num1 = num2 -> num1[0]: " << num1[0] << std::endl; // should be 10, meaning num1 is no longer empty
    std::cout << "Construction by Assignement. After num1 = num2 -> num1.size(): " << num1.size() << std::endl;  //should be 3
    num2[0] = 100;
    num2[1] = 200;
    num2[2] = 300;

    num1[0] = 1;
    num1[1] = 2;
    num1[2] = 3;

    //Check if modifying either the original array or its copy after copying musn’t affect the other array
    std::cout << "After modifing both num1 and num2: num1[0]]: " << num1[0] << std::endl; // should be 1
    std::cout << "After modifing both num1 and num2: num2[0]]: " << num2[0] << std::endl; // should be 100
    std::cout << std::endl;


    //Test if its index is out of bounds, an std::exception is thrown
    try
    {
        std::cout << num2[999] << std::endl;
    }
    catch (const std::exception&)
    {
        std::cout << "Invalid index!" << std::endl;
    }
    std::cout << std::endl;


    //Test self assignment
    num2 = num2;
    std::cout << "After self assignment num2 = num2 -> num2[0]: " << num2[0] << std::endl;
    std::cout << std::endl;


    /*--------------test with strings------------*/

    //------------Construction with no parameter-------------------
    std::cout << std::endl;
    Array<std::string> words1;
    std::cout << "Construction with no parameter: words1.size(): " << words1.size() << std::endl; //should be 0
     std::cout << std::endl;

    //------------Construction with an unsigned int n as a parameter-------------------
    Array<std::string> words2(3);    
    //Construction with an unsigned int n as a parameter: Creates an array of n elements initialized by default.
    std::cout << "Construction with parameter: Array<std::string> words2(3): words2.size(): " << words2.size() << std::endl; // should be 3
    std::cout << std::endl;


    //----------Construction by copy -------------------
    Array<std::string> words3(words2);
    std::string ret =words3[2].empty() ? "empty" : "has value";
    std::cout << "Construction by copy. After Array<std::string>words3(words2) -> words3[2]: " << ret << std::endl; // should be empty, as was words2[2] the default value
    std::cout << std::endl;

    //----------Assignement Operator-------------------
    words2[0] = "hello";
    words2[1] = "wonderful";
    words2[2] = "world";

    words1 = words2;
    std::cout << "Construction by Assignement. After words1 = num2 -> words1[0]: " << words1[0] << std::endl; // should be hello, meaning words1 is no longer empty
    std::cout << "Construction by Assignement. After words1 = num2 -> words1.size(): " << words1.size() << std::endl;  //should be 3


    return 0;
}