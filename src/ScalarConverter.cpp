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

double ScalarConverter::stod(std::string &str)
{
    double value;
    std::stringstream ss(str);
    ss << str;
    ss >> value;
    return (value);
}

void    ScalarConverter::convert(std::string string)
{
    double  value = ScalarConverter::stod(string);
    char    c = static_cast<char>(value);
    int     i = static_cast<int>(value);
    float   f = static_cast<float>(value);
    double  d = value;

    if(isprint(c) && !) /*ATTENTION !!!!!!!!!!!!!!!!!!!!!! PAS SUR QUE J'AI LE DROIT*/
        std::cout << BOLDBLUE << "char:" << c << DEFAULTCOL << std::endl;
    else
        std::cout << BOLDBLUE << "char: Non displayable" << DEFAULTCOL << std::endl;
    if((value < CHAR_MIN || value > CHAR_MAX) || (value < INT_MIN || value > INT_MAX)) 
        std::cout << BOLDGREEN << "int: Non displayable" << DEFAULTCOL << std::endl;
    else
        std::cout << BOLDGREEN << "int:" << i << DEFAULTCOL << std::endl;
    std::cout << BOLDYELLOW << "float:" << f << ".f" << DEFAULTCOL << std::endl;
    std::cout << BOLDPEACH << "double:" << d << DEFAULTCOL << std::endl;
}



/*Surcharge opérateur*/
// ScalarConverter& operator=(const ScalarConverter&);
