#include "poly.h"



Poly Poly::operator + (const Poly& p)
{
	//std::vector<double>newpoly(std::max(coef.size(), p.coef.size()));
	std::vector<double> new_coef(std::max(coef.size(), p.coef.size()));
	Poly res(new_coef);
	for (int i = 0; i < (std::max(coef.size(), p.coef.size())); ++i)
	{
		double p1 = coef.size() > i ? coef[i] : 0;
		double p2 = p.coef.size() > i ? p.coef[i] : 0;
		new_coef[i] = p1 + p2;
		res.coef.push_back(new_coef[i]);
	}
	return res;
}
Poly Poly::operator - (const Poly& p)
{
	std::vector<double>new_coef(std::max(coef.size(), p.coef.size()));
	Poly res(new_coef);
	for (int i = 0; i < (std::max(coef.size(), p.coef.size())); ++i)
	{
		double p1 = coef.size() > i ? coef[i] : 0;
		double p2 = p.coef.size() > i ? p.coef[i] : 0;
		new_coef[i] = p1 - p2;
		res.coef.push_back(new_coef[i]);
	}
	return res;
}


Poly Poly::operator * (const Poly& p)
{

	std::vector<double>new_coef(coef.size() + p.coef.size() - 1);
	Poly res(new_coef);
	for (int i = 0; i < (coef.size() + p.coef.size() - 1); ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			new_coef[i + j] += coef[i] * p.coef[j];
			res.coef.push_back(new_coef[i + j]);
		}

	}
	return res;
}

Poly Poly::der()
{
	std::vector<double>new_coef(coef.size() - 1);
	Poly res(new_coef);
	for (int i = 0; i < (coef.size() - 1); ++i)
	{
		new_coef[i] += coef[i + 1] * i;
		res.coef.push_back(new_coef[i]);
	}
	return res;
}

Poly Poly::integral()
{
	std::vector<double>new_coef(coef.size() + 1);
	Poly res(new_coef);
	for (int i = 0; i < (coef.size() + 1); ++i)
	{
		new_coef[i] += coef[i] / i;
		res.coef.push_back(new_coef[i]);
	}
	return res;
}
