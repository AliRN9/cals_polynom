#pragma once
#include<iostream>
#include <utility>
#include <vector>

class Poly
{
public:
	std::vector<double> coef = {};
	Poly() = default;
	explicit Poly(std::vector<double> coef1) : coef(std::move(coef1)) {};
	Poly operator + (const Poly& p);
	Poly operator - (const Poly& p);
	Poly operator * (const Poly& p);
	Poly der();
	Poly integral();

};
