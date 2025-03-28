#pragma once
#include <iostream>
#include <string>
namespace System {
    namespace Generic {
        enum g_type {
            INT,
            FLOAT,
            DOUBLE,
            STRING,
            CHAR,
            BOOL,
            OBJECT,
            NPM
        };
        g_type determineType(std::string str) {
            if (str.empty()) {
                return g_type::NPM;
            }
            if (str == "true" || str == "false") {
                return g_type::BOOL;
            }
            bool isInteger = true;
            for (char c : str) {
                if (!std::isdigit(c) && c != '-' && c != '+') {
                    isInteger = false;
                    break;
                }
            }
            if (isInteger) {
                return g_type::INT;
            }
            bool isFloat = false;
            bool hasDecimalPoint = false;
            for (char c : str) {
                if (c == '.') {
                    if (hasDecimalPoint) {
                        isFloat = false;
                        break;
                    }
                    hasDecimalPoint = true;
                } else if (!std::isdigit(c) && c != '-' && c != '+') {
                    isFloat = false;
                    break;
                } else {
                    isFloat = true;
                }
            }
            if (isFloat) {
                return g_type::FLOAT;
            }
            return g_type::STRING;
        }
    }
}