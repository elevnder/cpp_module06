/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: earnera <earnera@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 10:20:13 by earnera           #+#    #+#             */
/*   Updated: 2025/09/10 14:54:57 by earnera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/Serializer.hpp"

/********************************************CONSTRUCTEURS********************************************************** */

Serializer::Serializer() {
    std::cout << BOLD << GREEN << "Serializer constructor called ! :3" << std::endl;
}
Serializer::Serializer(const Serializer &machinou) {
    std::cout << BOLD << GREEN << "Serializer copy constructor called ! :3" << std::endl;
    *this = machinou;
}
Serializer::~Serializer() {
    std::cout << BOLD << RED << "Serializer destructor called ! o/" << std::endl;
}

Serializer &Serializer::operator=(const Serializer &machinou) {
    std::cout << BOLD << GREEN << "Serializer assignation operator called ! :3" << std::endl;
    if(this == &machinou)
        return(*this);
    return(*this);
}

/********************************************METHODES********************************************************** */

uintptr_t Serializer::serialize(Data* ptr){
    uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
    return (raw);
    // prend un pointeur et le convertir en entier non signé (unsigned integer)
}

Data *Serializer::deserialize(uintptr_t raw){
    Data * ptr = reinterpret_cast<Data *>(raw);
    return (ptr);
// prend un parametre entier non signé et le convertit en pointeur sur data 
}
