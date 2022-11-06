//
// Created by ArtMed on 03.11.2022.
//

#include <iostream>
#include <regex>
#include "poly.h"
#include <string>
#include "parser.h"

using namespace std;

vector<string> parse_operations(string line) {
    vector<string> operations;

    istringstream iss(line);
//    std::map <std::string, int> mapping;

    string operation;
    while (getline(iss, operation, ' ')) {
        if (operation == "+" || operation == "-" || operation == "*"
            || operation == "int" || operation == "der"){
            operations.push_back(operation);
        }
        else{
            if (operation != "") {
                cerr << "unknown operation";
                exit(-1);
            }
        }

    }
    return operations;
}




pair<vector<string>, vector<vector<double>>> input_parsing() {

    vector<vector<double>> polys_vec;
    vector<string> operations;
    vector<double> coefs;
    regex regular("(\\[[-?[:digit:]+ ]*\\])");
    cmatch result;
    int pos;
    string line;
    cout << "Please enter your expression:" << endl;
    getline(cin, line);

    while (regex_search(line.c_str(), result, regular)) {
        coefs.clear();
        coefs=str_to_poly(result[0]);
//        Poly poly(result[0]);
        pos = line.find(result[0]);
        line.erase(pos, result[0].length());
        polys_vec.push_back(coefs);
    }
    operations = parse_operations(line);

    if (polys_vec.size() == 0){
        cerr<<"no polys entered";
        exit(0);
    }
    if (operations.size() == 0){
        cerr<<"no signs entered";
        exit(0);
    }
    pair<vector<string>, vector<vector<double>>> res;
    res.first = operations;
    res.second = polys_vec;
    return res;
}

Poly calculate(vector<string> signs, vector<vector<double>> polys_coefs_vec) {

    Poly result(polys_coefs_vec[0]);
    for (int i = 0; i < signs.size(); ++i) {

        if (signs[i]=="+") {
            Poly operand(polys_coefs_vec[i+1]);
            result = result + operand;
        }
        else if (signs[i]=="-") {
            Poly operand(polys_coefs_vec[i+1]);
            result = result - operand;
        }
        else if (signs[i]=="*") {
            Poly operand(polys_coefs_vec[i+1]);
            result = result * operand;
        }
        else if (signs[i]=="int") {
            result = result.integral();
        }
        else if (signs[i]=="der") {
            result = result.der();
        }
    }
    return result;
}


vector<double> str_to_poly(string coefs){
    vector<double> coef_vec;
    while(coefs[0] == '[' || coefs[0] == ' ')
        coefs.erase(0, 1);

    while(coefs[coefs.size() - 1] == ']' || coefs[coefs.size() - 1] == ' ')
        coefs.erase(coefs.size() - 1, 1);


    int pos = 0;
    while ((pos = coefs.find(" ")) != std::string::npos) {
        coef_vec.push_back(stod(coefs.substr(0, pos)));
        coefs.erase(0, pos + 1);
    }
    coef_vec.push_back(stod(coefs));
    return coef_vec;
}