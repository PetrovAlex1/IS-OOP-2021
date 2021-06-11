#pragma once
#include <iostream>

template <typename T>
class PriceTag
{
private:
	T product;
	double price;
public:

	PriceTag(const T& product, const double& price)
	{
		this->product = product;
		this->price = price;
	}

	void setProduct(const& T product)
	{
		this->product = product;
	}

	T& getProduct() const
	{
		return this->product;
	}

	void setPrice(cosnt double& price)
	{
		this->price = price;
	}

	double& getPrice() const
	{
		return  this->price;
	}

	void discount(const double& percentage)
	{
		this->price -= (percentage / 100) * this->price;
	}

	friend std::ostream& operator<<(std::ostream& out, const PriceTag& obj)
	{
		out << "Product " << obj.getProduct() << " with price: " << obj.getPrice() << std::endl;

		return out;
	}


	friend std::istream& operator>>(std::istream& in, PriceTag& obj)
	{
		T product;
		in >> product;

		obj.setProduct(product);

		double price;
		in >> price;

		obj.setPrice(price);

		return in;
	}
};