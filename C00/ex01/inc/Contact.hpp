/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cde-la-r <code@cesardelarosa.xyz>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 11:42:03 by cde-la-r          #+#    #+#             */
/*   Updated: 2025/04/20 11:45:30 by cesi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>

class   Contact
{
    public:
        typedef struct s_field {
            const char* prompt;
            std::string Contact::* member;
        } t_field;

        Contact();
        ~Contact();

        void    fillFromPrompt();
        void    printRow(int index) const;
        void    printCard() const;

    private:
        static const t_field    _fields[];

        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret;
};