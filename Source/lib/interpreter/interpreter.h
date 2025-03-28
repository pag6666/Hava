#pragma once
#include "../fun/ex_fun.h"
#include "../memory_stack/GC/Gc.h"
#include "../object/ex_object.h"
#include "fun_generic_type.h"
#include <locale>
#include <codecvt>
#include <fstream>
#include <algorithm>
#include <Windows.h>

namespace System {
    namespace Interpreter {
        class Interpreter {
            private:
            int LEFT = 0;
            int RIGHT = 1;
            std::vector<std::string> split(const std::string& text, const std::string& dec) {
                std::vector<std::string> result;
                if (dec.empty()) {
                    return result;
                }
                size_t start = 0;
                size_t end = text.find(dec);
                while (end != std::string::npos) {
                    result.push_back(text.substr(start, end - start));
                    start = end + dec.length();
                    end = text.find(dec, start);
                }
                result.push_back(text.substr(start));
                if (result.size() == 1 && result[0] == text) {
                    return {}; 
                }
                return result;
            }
            void print_vector(std::vector<std::string> vec) {
                std::string res = "{ ";
                for(std::string val : vec) {
                    res += val + ", ";
                }
                res += " }";
                std::cout << res << std ::endl;
            }
            std::vector<std::string> list_line_code;
            void MessageError(std::string message) {
                MessageBoxA(nullptr, message.c_str(), "Error", MB_ICONERROR);
            }
            std::string RemoveSpaces(const std::string& str) {
                std::string result;
                std::remove_copy(str.begin(), str.end(), std::back_inserter(result), ' ');
                return result;
            }
             
            std::vector<std::string> readLinesFromFile(std::wstring filename) {
                std::vector<std::string> lines;
                std::wifstream wif(filename.c_str());
                    wif.imbue(std::locale(wif.getloc(), new std::codecvt_utf8<wchar_t>));

                    if (!wif.is_open()) {
                        std::wcerr << L"Не удалось открыть файл: " << filename << std::endl;
                        return lines;
                    }

                    std::wstring line;
                    while (std::getline(wif, line)) {
                        std::string str(line.begin(), line.end());
                        lines.push_back(str);
                    }

                    return lines;
                }
            bool StringProcessing(std::string code) {
                print_vector(split(code, "="));
                if(std::vector<std::string> p_line = split(code, "="); p_line.size() > 0) {
                    std::string text = p_line[RIGHT];
                    text = text.substr(0, text.length() - 1);
                    System::Generic::g_type type = System::Generic::determineType(text);
                    std::cout << "n:= " << text << ", type:= " << type << std::endl;
                    if(type == System::Generic::g_type::BOOL) {
                        
                    }
                    else if(type == System::Generic::g_type::CHAR) {

                    }
                    else if(type == System::Generic::g_type::DOUBLE) {

                    }
                    else if(type == System::Generic::g_type::FLOAT) {

                    }
                    else if(type == System::Generic::g_type::INT) {
                        
                    }
                    else if(type == System::Generic::g_type::OBJECT) {

                    }
                    else if(type == System::Generic::g_type::STRING) {

                    }
                    //return true;
                }
                return false;
            }
            void EntryMain() {

            }

            public:
            Interpreter() {
                this->list_line_code = std::vector<std::string>();
            }
            void OpenFile(std::wstring path) {
                list_line_code.clear();
                this->list_line_code = readLinesFromFile(path);
                for(std::string line: list_line_code) {
                    if(StringProcessing(line)) {
                        MessageError(line);
                        break;
                    }
                }
            }
            void PrintScripts() {
                for(size_t i = 0; i < list_line_code.size(); i++) {
                    std::cout << list_line_code[i] << std::endl; 
                }
                
                std::cout<<std::endl;
                std::cout << "____Trim___" << std::endl;
                std::cout<<std::endl;

                for(size_t i = 0; i < list_line_code.size(); i++) {
                    std::cout << RemoveSpaces(list_line_code[i]).c_str() << std::endl; 
                }
            }
        };
    }
} 
