/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:48:09 by earnera           #+#    #+#             */
/*   Updated: 2025/09/10 14:59:46 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Serializer.hpp"

int main(){
    Data data = {"Chouchouw", 42, NULL};

    std::cout << std::endl << "★----------------------☆ TEST ☆--------------------------★" << std::endl << std::endl;
    std::cout << BOLD << BLUE << "Adresse originale : " << &data << DEFCOL << std::endl;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << INDIGO << "Adresse après conversion en entier : " << raw << DEFCOL << std::endl;
    
    Data* ptr = Serializer::deserialize (raw);
    std::cout << PURPLE << "Adresse après désérialisation : " << ptr << DEFCOL << std::endl;
    std::cout << PINK << "Valeurs : " << ptr->str << ", " << ptr->num << DEFCOL << std::endl;
    std::cout << std::endl;
}