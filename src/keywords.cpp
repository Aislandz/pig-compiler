#include "keywords.hpp"

#include <list>
#include <iostream>
#include <cstdlib>

Keyword find_keyword(std::string input) {
    if (input == "oink") {
        return moo;
    } else if (input == "oInk") {
        return mOo;
    } else if (input == "oiNk") {
        return moO;
    } else if (input == "oinK") {
        return mOO;
    } else if (input == "Oink") {
        return Moo;
    } else if (input == "OInk") {
        return MOo;
    } else if (input == "OiNk") {
        return MoO;
    } else if (input == "OINK") {
        return MOO;
    } else if (input == "IINK") {
        return OOO;
    } else if (input == "IINO") {
        return OOM;
    } else if (input == "IIOK") {
        return oom;
    } else if (input == "OOOI") {
        return MMM;
    } else {
        std::cout << "'" << input << "' is invalid Pig operator. Exiting..." << std::endl;
        std::exit(1);
    }
}

std::vector<Keyword> to_keywords(std::string input_str, char delim = ' ') {
    auto n { input_str.size() };
    std::vector<Keyword> program_vector;
    // split
    size_t pos {0};
    std::string token;

    while ((pos = input_str.find(delim)) != std::string::npos) {
        token = input_str.substr(0, pos);
        
        program_vector.push_back(find_keyword(token));

        input_str.erase(0, pos + 1);
    }
    program_vector.push_back(find_keyword(input_str));
    return program_vector;
}
