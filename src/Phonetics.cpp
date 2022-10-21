#define KLING_PHONETICS_DEFINE_IPA

#include <Kling/Phonetics/Phone.hpp>
#include <Kling/Phonetics/IPA.hpp>

#include <string>
#include <sstream>
#include <iostream>

std::ostream& operator<<(std::ostream& os, const Kling::Phone& phone){
    os << phone.ToString();
    return os;
}