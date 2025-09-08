/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverterer.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 17:42:39 by earnera           #+#    #+#             */
/*   Updated: 2025/08/28 18:11:26 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <limits>
#include <climits>
#include <iomanip>

#define BOLDGREEN "\e[1;38;5;156m"
#define BOLDPURPLE "\e[1;38;5;147m"
#define BOLDPINK "\e[1;38;5;219m"
#define BOLDBLUE "\e[1;38;5;159m"
#define BOLDBRIGHTPINK "\e[1;38;5;212m"
#define BOLDINDIGO "\e[1;38;5;111m"
#define BOLDYELLOW "\e[1;38;5;221m"
#define BOLDPEACH "\e[1;38;5;216m"
#define BOLDMUD "\e[1;38;5;106m"
#define BOLDRED "\e[1;38;5;210m"
#define BOLDCREAM "\e[1;38;5;230m"
#define BOLDBROWN "\e[1;38;5;137m"
#define SICKGREEN "\e[0;38;5;143m"
#define DEFAULTCOL "\e[0m"


class ScalarConverter
{
    public:

                
                /*Surcharge opérateur*/
                    // ScalarConverter& operator=(const ScalarConverter&);
                /*Getters*/
                /*Setters*/
                /*Méthodes*/
                static void    convert(std::string string);
                /*Exceptions*/
                

    private:
                /*Constructeurs*/
                    ScalarConverter();
                    ScalarConverter( ScalarConverter&);
                /*Destructeurs*/
                    ~ScalarConverter();

};


// std::ostream& operator<<(std::ostream& o, const ScalarConverter& b);


#endif