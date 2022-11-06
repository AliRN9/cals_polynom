

#include <iostream>
#include <vector>
#include "parser.h"
#include "poly.h"

using namespace std;

int main() {
    pair<vector<string>, vector<vector<double>>> parsed;
    parsed = input_parsing();

    Poly result;
    result=calculate(parsed.first, parsed.second);
    cout<< parsed.first[0]<<endl;
    cout<<result;

}
