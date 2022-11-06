#include "poly.h"




Poly::Poly(std::string params) {
    while(params[0] == '[' || params[0] == ' ')
        params.erase(0, 1);

    while(params[params.size() - 1] == ']' || params[params.size() - 1] == ' ')
        params.erase(params.size() - 1, 1);


    int pos = 0;
    while ((pos = params.find(" ")) != std::string::npos) {
        coef.push_back(stod(params.substr(0, pos)));
        params.erase(0, pos + 1);
    }
    coef.push_back(stod(params));
}

Poly Poly::operator + (const Poly& p)
{
	//std::vector<double>newpoly(std::max(coef.size(), p.coef.size()));
	std::vector<double> new_coef(std::max(coef.size(), p.coef.size()));
	Poly res(new_coef);
	for (int i = 0; i < (std::max(coef.size(), p.coef.size())); ++i)
	{
       // std::cout<<i<<std::endl;
		double p1 = coef.size() > i ? coef[i] : 0;
		double p2 = p.coef.size() > i ? p.coef[i] : 0;
		new_coef[i] = p1 + p2;
		res.coef[i]=new_coef[i];
	}
   // std::cout<<res.coef.size()<<std::endl;
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
        res.coef[i]=new_coef[i];
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
			res.coef[i]=new_coef[i + j];
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
		new_coef[i] = coef[i + 1] * (i+1);
		res.coef[i]=new_coef[i];
	}
	return res;
}

Poly Poly::integral()
{
	std::vector<double>new_coef(coef.size() + 1);
	Poly res(new_coef);
	for (int i = 1; i < (coef.size() + 1); ++i)
	{
		new_coef[i] = coef[i-1] / i;
		res.coef[i]=new_coef[i];
	}
	return res;
}
std::ostream &operator<<(std::ostream &os, Poly p) 
{
    for (int i = 0; i < p.coef.size(); ++i) 
	{
        os << p.coef[i] << " ";
    }
    os << std::endl;
}

