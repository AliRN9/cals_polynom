#include <iostream>
#include <vector>
#include <regex>
//#include <wsman.h>
#include "poly.h"


std::vector<std::string> parse_operations(std::string line);

std::pair<std::vector<std::string>, std::vector<std::vector<double>>> input_parsing();

std::vector<double> str_to_poly(std::string coefs);

Poly calculate(std::vector<std::string> signs, std::vector<std::vector<double>> polys_coefs_vec);


