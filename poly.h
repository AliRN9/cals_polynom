#pragma once
#include<iostream>
#include <vector>

class Poly 
{
public:
	std::vector<double> coef = {};
	Poly() = default;
	Poly(std::vector<double> coef);
	Poly operator + (Poly p);
	Poly operator - (Poly p);
	Poly operator * (Poly p);
	Poly der();
	Poly integral();
	//void calculator();
	//void print_poly();

};
//std::ostream& operator<<(std::ostream& strm,Poly(res))
//{
//	strm << "Polynom\n";
//	for (int i = 0; i < p.coef.size(); i++) {
//
//		strm << "X ^ ";
//		strm << i;
//		strm << " = ";
//		strm << p.Coefficients[i];
//		strm << "\n";
//	}
//
//	return strm;
//}
