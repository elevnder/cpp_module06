/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterer.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:42:36 by earnera           #+#    #+#             */
/*   Updated: 2025/08/28 17:45:26 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/ScalarConverter.hpp"

/********************************************CONSTRUCTEURS********************************************************** */

ScalarConverter::ScalarConverter() {

}
ScalarConverter::ScalarConverter(ScalarConverter&) {

}
ScalarConverter::~ScalarConverter() {}

/********************************************DETECTION*DE*TYPE********************************************************** */

bool isPseudoLiteral(const std::string &str) {
    static const std::string pseudoLiterals[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

    for (int i = 0; i < 6; i++)
        if (pseudoLiterals[i] == str) return true;
    return false;
}

bool isInt(const std::string &str) {
    if (str.empty()) return false;
    for (size_t i = 0; i < str.size(); i++) {
        if (i == 0 && (str[i] == '+' || str[i] == '-')) continue;
        if (!isdigit(str[i])) 
            return false;
    }
    return true;
}

bool isFloat(const std::string &str) {
    if (str.size() < 2 || str.back() != 'f') return false;
    bool hasDot = false;
    for (size_t i = 0; i < str.size() - 1; i++) {
        if (i == 0 && (str[i] == '+' || str[i] == '-')) 
            continue;
        if (str[i] == '.') 
            hasDot = true;
        else if (!isdigit(str[i])) 
            return false;
    }
    return hasDot;
}

bool isDouble(const std::string &str) {
    if (str.empty()) 
        return false;
    bool hasDot = false;
    for (size_t i = 0; i < str.size(); i++) {
        if (i == 0 && (str[i] == '+' || str[i] == '-')) 
            continue;
        if (str[i] == '.') 
            hasDot = true;
        else if (!isdigit(str[i])) 
            return false;
    }
    return hasDot;
}

int getType(const std::string &str) {
    if (str.size() == 1 && !isdigit(str[0])) 
        return 1;   /*char*/
    else if (isInt(str)) 
        return 2;                       /*int*/
    else if (isFloat(str)) 
        return 3;                     /*float*/
    else if (isDouble(str)) 
        return 4;                    /*double*/
    else if (isPseudoLiteral(str)) 
        return 5;            /*pseudoliteral*/
    return 0;                                            /*autre y a un pbbbbb*/
}

/********************************************PRINTS********************************************************** */


// void printChar(double value){
//     if (value < CHAR_MIN || value > CHAR_MAX)
//         std::cout << "char: impossible" << std::endl;
//     else {
//         char c = static_cast<char>(value);
//         if (isprint(c))
//             std::cout << BOLDBLUE << "char: '" << c << "'" << DEFAULTCOL << std::endl;
//         else
//             std::cout << BOLDBLUE << "char: Non displayable" << DEFAULTCOL << std::endl;
//     }
// }


// void printInt(double value) {
//     if (value < INT_MIN || value > INT_MAX)
//         std::cout << BOLDGREEN << "int: impossible" << DEFAULTCOL << std::endl;
//     else
//         std::cout << BOLDGREEN << "int: " << static_cast<int>(value) << DEFAULTCOL << std::endl;
// }

// void printFloat(double value) {
//     float f = static_cast<float>(value); // on caste ici
//     if (f == static_cast<int>(f))
//         std::cout << std::fixed << std::setprecision(1);
//     else
//         std::cout << std::fixed << std::setprecision(6);
//     std::cout << BOLDYELLOW << "float: " << f << "f" << std::endl;
// }

// void printDouble(double value) {
//     if (value == static_cast<int>(value))
//         std::cout << BOLDPEACH << std::fixed << DEFAULTCOL << std::setprecision(1);
//     else
//         std::cout << std::fixed << std::setprecision(6);
//     std::cout << BOLDPEACH << "double: " << value << DEFAULTCOL << std::endl;
// }

void printChar(double value) {
    if (value < CHAR_MIN || value > CHAR_MAX)
        std::cout << "char: impossible\n";
    else {
        char c = static_cast<char>(value);
        std::cout << "char: " << (isprint(c) ? std::string("'") + c + "'" : "Non displayable") << std::endl;
    }
}

void printInt(double value) {
    if (value < INT_MIN || value > INT_MAX) std::cout << "int: impossible\n";
    else std::cout << "int: " << static_cast<int>(value) << std::endl;
}

void printFloat(double value) {
    float f = static_cast<float>(value);
    std::cout << "float: " << std::fixed << std::setprecision((f == static_cast<int>(f)) ? 1 : 6) << f << "f" << std::endl;
}

void printDouble(double value) {
    std::cout << "double: " << std::fixed << std::setprecision((value == static_cast<int>(value)) ? 1 : 6) << value << std::endl;
}


void printPseudoLiteral(const std::string &str) {
    if (str == "nan" || str == "nanf") {
        std::cout << BOLDBLUE << "char: impossible" << std::endl;
        std::cout << BOLDGREEN << "int: impossible" << std::endl;
        std::cout << BOLDYELLOW << "float: nanf" << std::endl;
        std::cout << BOLDPEACH << "double: nan" << std::endl;
    }
    else if (str == "+inf" || str == "+inff") {
        std::cout << BOLDBLUE << "char: impossible" << std::endl;
        std::cout << BOLDGREEN << "int: impossible" << std::endl;
        std::cout << BOLDYELLOW << "float: +inff" << std::endl;
        std::cout << BOLDPEACH << "double: +inf" << std::endl;
    }
    else if (str == "-inf" || str == "-inff") {
        std::cout << BOLDBLUE << "char: impossible" << std::endl;
        std::cout << BOLDGREEN << "int: impossible" << std::endl;
        std::cout << BOLDYELLOW <<"float: -inff" << std::endl;
        std::cout << BOLDPEACH <<"double: -inf" << std::endl;
    }
}

/********************************************CONVERSION********************************************************** */

void ScalarConverter::convert(const std::string &str) {
    int type = getType(str);

    switch (type) {
        case 1: { // char
            char c = str[0];
            double value = static_cast<double>(c);
            printChar(value);
            printInt(value);
            printFloat(value);
            printDouble(value);
            break;
        }
        case 2: { // int
            int i = std::stoi(str);
            double value = static_cast<double>(i);
            printChar(value);
            printInt(value);
            printFloat(value);
            printDouble(value);
            break;
        }
        case 3: { // float
            float f = std::stof(str);
            double value = static_cast<double>(f);
            printChar(value);
            printInt(value);
            printFloat(value);
            printDouble(value);
            break;
        }
        case 4: { // double
            double d = std::stod(str);
            printChar(d);
            printInt(d);
            printFloat(d);
            printDouble(d);
            break;
        }
        case 5: { // pseudo-literal
            printPseudoLiteral(str);
            break;
        }
        default:
            std::cout << "Invalid input\n";
            break;
    }
}


// /*Constructeurs*/
// ScalarConverter::ScalarConverter(){
    
// }
// ScalarConverter::ScalarConverter( ScalarConverter&){
    
// }
// /*Destructeurs*/
// ScalarConverter::~ScalarConverter(){
    
// }

// /********************************************CONVERSIONS********************************************************** */

//  double stod(std::string &str)
// {
//     double value;
//     std::stringstream ss(str);
//     ss >> value;
//     return (value);
// }

// /*************************************************IS*TYPE******************************************************* */


// bool isPseudoLiteral(const std::string &str){
//     std::string pseudoLiteralsTab[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

//     for(int i = 0; i < 6; i++){
//         if(pseudoLiteralsTab[i] == str)
//             return true;
//     }
//     return false;
// }

// bool isInt(const std::string &str){
//     bool isInt = true;
//     for(int i = 0; i < str.size(); i++)
//     {
//         if(i == 0 && str[i] == '+' || str[i] == '-')
//             continue;
//         if(!isdigit(str[i])){
//             isInt = false;
//             break;
//         }
//     }
//     return(isInt);

// }

// bool isFloat(const std::string &str){
//     if(str.back() == 'f'){
//         bool hasDot = false;
//         for(int i = 0; i < str.size() - 1; i++){
//             if(i == 0 && str[i] == '+' || str[i] == '-')
//                 continue;
//             if(str[i] == '.')
//                 hasDot = true;
//             else if (!isdigit(str[i]))
//                 return false;
//         }
//         if(hasDot)
//             return true;
//     }
//     return false ;
// }

// bool isDouble(const std::string &str){
    
//     bool hasDot = false;
//     for(int i = 0; i < str.size() - 1; i++){
//         if(i == 0 && str[i] == '+' || str[i] == '-')
//             continue;
//         if(str[i] == '.')
//             hasDot = true;
//         else if (!isdigit(str[i]))
//             return false;
//     }
//     if(hasDot)
//         return true;
// }

//  /**********************************************CHECK***************************************************** */


// bool checkInput(std::string string){
//     if(string.empty())
//         return false;
//     if(isPseudoLiteral(string))
//     {
//         printPseudoLiteral(string);
//         return false;
//     }
//     if(string.length() == 1)
//         return true;
//     return true;
// }
// int getType(const std::string &str){
//     if(str.size() == 1 && !isdigit(str[0]))
//         return 1; /*char*/
//     else if(isInt(str))
//         return 2; /*int*/
//     else if(isFloat(str))
//         return 3;
//     else if(isDouble(str))
//         return 4;
//     return(0);
// }

// /*****************************************PRINT****************************************************** */


// void printChar(double value){
//     if (value < CHAR_MIN || value > CHAR_MAX)
//         std::cout << "char: impossible" << std::endl;
//     else {
//         char c = static_cast<char>(value);
//         if (isprint(c))
//             std::cout << BOLDBLUE << "char: '" << c << "'" << DEFAULTCOL << std::endl;
//         else
//             std::cout << BOLDBLUE << "char: Non displayable" << DEFAULTCOL << std::endl;
//     }
// }


// void printInt(double value) {
//     if (value < INT_MIN || value > INT_MAX)
//         std::cout << BOLDGREEN << "int: impossible" << DEFAULTCOL << std::endl;
//     else
//         std::cout << BOLDGREEN << "int: " << static_cast<int>(value) << DEFAULTCOL << std::endl;
// }

// void printFloat(double value) {
//     float f = static_cast<float>(value); // on caste ici
//     if (f == static_cast<int>(f))
//         std::cout << std::fixed << std::setprecision(1);
//     else
//         std::cout << std::fixed << std::setprecision(6);
//     std::cout << BOLDYELLOW << "float: " << f << "f" << std::endl;
// }

// void printDouble(double value) {
//     if (value == static_cast<int>(value))
//         std::cout << BOLDPEACH << std::fixed << DEFAULTCOL << std::setprecision(1);
//     else
//         std::cout << std::fixed << std::setprecision(6);
//     std::cout << BOLDPEACH << "double: " << value << DEFAULTCOL << std::endl;
// }
// void printPseudoLiteral(std::string &str) {
//     if (str == "nan" || str == "nanf") {
//         std::cout << BOLDBLUE << "char: impossible" << std::endl;
//         std::cout << BOLDGREEN << "int: impossible" << std::endl;
//         std::cout << BOLDYELLOW << "float: nanf" << std::endl;
//         std::cout << BOLDPEACH << "double: nan" << std::endl;
//     }
//     else if (str == "+inf" || str == "+inff") {
//         std::cout << BOLDBLUE << "char: impossible" << std::endl;
//         std::cout << BOLDGREEN << "int: impossible" << std::endl;
//         std::cout << BOLDYELLOW << "float: +inff" << std::endl;
//         std::cout << BOLDPEACH << "double: +inf" << std::endl;
//     }
//     else if (str == "-inf" || str == "-inff") {
//         std::cout << BOLDBLUE << "char: impossible" << std::endl;
//         std::cout << BOLDGREEN << "int: impossible" << std::endl;
//         std::cout << BOLDYELLOW <<"float: -inff" << std::endl;
//         std::cout << BOLDPEACH <<"double: -inf" << std::endl;
//     }
// }





// void printInput(std::string string){
//     /*try/catch*/
//     double value = stod(string);
//     printChar(value);
//     printInt(value);
//     printFloat(value);
//     printDouble(value);


// }

// void    ScalarConverter::convert(std::string string)
// {
//     int type = getType(string);
//     bool isValid = true;

//     switch(type)
//     {
//         case 1 :{ /*char*/
//             checkChar ();
//             break;
//         }
//         case 2 :{ /*int*/
//             checkInt();
//             int i = std::stoi(string);
//             double value = static_cast<double>(i);
//             printChar(value);
//             printInt(value);
//             printFloat(value);
//             printDouble(value);
//             break;
//         }
//         case 3 :{ /*float*/
//             checkFloat();
//             break;
//         }
//         case 4 :{ /*double*/
//             checkDouble();
//             break;
//         }
//         case 0 :
//         {
//             isValid = false;
//             break;
//         }
//         break;
//     }
//     else
//         std::cout << BOLDRED << "Invalid input" << DEFAULTCOL << std::endl;   
// }

// /*Surcharge opérateur*/
// // ScalarConverter& operator=(const ScalarConverter&);
