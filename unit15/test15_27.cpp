#include <iostream>
#include <string>
using namespace std;

class Quote {
public:
	//Quote() = default;
	Quote(const string &book = "", double sales_price = 0.0) :
		bookNo(book), price(sales_price)
	{
		cout << "Quote constructor is running" << endl;
	}

	string isbn() const
	{
		return bookNo;
	}
	//返回给定数量的书籍销售总额，派生类改写并使用不同的折扣计算方法
	virtual double net_price(size_t n) const
	{
		return n*price;
	}

	virtual void debug()
	{
		cout << "bookNo=" << bookNo << " price=" << price << endl;
	}
	virtual ~Quote()
	{
		cout << "Quote destructor is running" << endl;
	}
	//friend ostream &operator<<(ostream &, Quote&);
private:
	string bookNo;
protected:
	double price;
};

ostream &operator<<(ostream &os, Quote &q)
{
	os << "\tUsing operator<<(ostream &,Quote &);" << endl;
	return os;
}

class Disc_quote : public Quote {
	Disc_quote(const string &book = "", double sales_price = 0.0, size_t qty = 0, double disc = 0.0) :
		Quote(book, sales_price), quantity(qty), discount(disc) {}
	double net_price(size_t cnt) const = 0;
protected:
	size_t quantity;
	double discount;
};
class Bulk_quote : public Disc_quote {
public:
	using Disc_quote::Disc_quote;
	double net_price(size_t cnt) const
	{
		if (cnt > quantity)
			return cnt*(1 - discount)*price;
		else
			return cnt*price;
	}
};
//2016年6月29日15:01:07
//实验室
