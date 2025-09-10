/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:20:16 by earnera           #+#    #+#             */
/*   Updated: 2025/09/10 14:58:51 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <string>
#include <stdint.h>

#define GREEN "\e[0;38;5;156m"
#define PURPLE "\e[0;38;5;147m"
#define PINK "\e[0;38;5;219m"
#define BLUE "\e[0;38;5;159m"
#define BRIGHTPINK "\e[0;38;5;212m"
#define INDIGO "\e[0;38;5;111m"
#define YELLOW "\e[0;38;5;221m"
#define PEACH "\e[0;38;5;216m"
#define MUD "\e[0;38;5;106m"
#define RED "\e[0;38;5;210m"
#define CREAM "\e[0;38;5;230m"
#define BROWN "\e[0;38;5;137m"
#define SICKGREEN "\e[0;38;5;143m"
#define DEFCOL "\e[0m"
#define BOLD    "\e[1m"

struct Data {
    std::string str;
    int num;
    Data *next;
};

class Serializer
{
    public:

                /*Constructeurs*/
                    Serializer();
                    Serializer(const Serializer& other);

                /*Destructeurs*/
                    ~Serializer();

                /*Surcharge opérateur*/
                    Serializer& operator=(const Serializer& other);

                /*Getters*/
                    // /* type */ getSomething() const;

                /*Setters*/
                    // void setSomething(/* params */);

                /*Objets*/

                /*Méthodes*/
                    // void doSomething();
                    static uintptr_t serialize(Data* ptr);
                    static Data *deserialize(uintptr_t raw);
                // /*Exceptions*/
                //     class ExampleException : public std::exception
                //     {
                //         public:
                //             const char* what() const throw()
                //             {
                //                 return "Erreur : exemple.";
                //             }
                //     };


    private:
                /* Attributs */
                // /* type */ _attribute;
};



#endif