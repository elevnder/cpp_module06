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


/*Constructeurs*/
ScalarConverter::ScalarConverter(){
    
}
ScalarConverter::ScalarConverter( ScalarConverter&){
    
}
/*Destructeurs*/
ScalarConverter::~ScalarConverter(){
    
}

double stod(std::string &str)
{
    double value;
    std::stringstream ss(str);
    ss >> value;
    return (value);
}

bool isPseudoLiteral(const std::string &str){
    std::string pseudoLiteralsTab[6] = {"-inff", "+inff", "nanf", "-inf", "+inf", "nan"};

    for(int i = 0; i < 6; i++){
        if(pseudoLiteralsTab[i].compare(str))
            return true;
    }
    return false;
}

void printChar(double value){
    if (value < CHAR_MIN || value > CHAR_MAX)
        std::cout << "char: impossible" << std::endl;
    else {
        char c = static_cast<char>(value);
        if (isprint(c))
            std::cout << BOLDBLUE << "char: '" << c << "'" << DEFAULTCOL << std::endl;
        else
            std::cout << BOLDBLUE << "char: Non displayable" << DEFAULTCOL << std::endl;
    }
}


void printInt(double value) {
    if (value < INT_MIN || value > INT_MAX)
        std::cout << BOLDGREEN << "int: impossible" << DEFAULTCOL << std::endl;
    else
        std::cout << BOLDGREEN << "int: " << static_cast<int>(value) << DEFAULTCOL << std::endl;
}

void printFloat(double value) {
    float f = static_cast<float>(value); // on caste ici
    if (f == static_cast<int>(f))
        std::cout << std::fixed << std::setprecision(1);
    else
        std::cout << std::fixed << std::setprecision(6);
    std::cout << BOLDYELLOW << "float: " << f << "f" << std::endl;
}

void printDouble(double value) {
    if (value == static_cast<int>(value))
        std::cout << BOLDPEACH << std::fixed << DEFAULTCOL << std::setprecision(1);
    else
        std::cout << std::fixed << std::setprecision(6);
    std::cout << BOLDPEACH << "double: " << value << DEFAULTCOL << std::endl;
}
/*A REPRENDREEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE*/
void printPseudoLiteral(std::string &str) {
    if (str == "nan" || str == "nanf") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: nanf" << std::endl;
        std::cout << "double: nan" << std::endl;
    }
    else if (str == "+inf" || str == "+inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: +inff" << std::endl;
        std::cout << "double: +inf" << std::endl;
    }
    else if (str == "-inf" || str == "-inff") {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: -inff" << std::endl;
        std::cout << "double: -inf" << std::endl;
    }
}

bool checkInput(std::string string){
    if(string.empty())
        return false;
    if(isPseudoLiteral(string))
        printPseudoLiteral(string);
    if(string.length() == 1)
        return true;
    return true;
}

void printInput(std::string string){
    double value = stod(string);
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);


}

void    ScalarConverter::convert(std::string string)
{
    if(checkInput(string))
        printInput(string);
    else
        std::cout << BOLDRED << "Invalid input" << DEFAULTCOL << std::endl;   
}



/*Surcharge opérateur*/
// ScalarConverter& operator=(const ScalarConverter&);
