#ifndef QUOTE_H
#define QUOTE_H
#include <iostream>
#include <string>
class Quote {
public:
	Quote() = default;
	Quote(const std::string &book, double sales_price) :
		bookNo(book), price(sales_price) {}
	std::string isbn() const { return bookNo; }

	//返回给定数量的书籍的销售总额
	//派生类负责改写并使用不同的折扣计算算法
	virtual double net_price(std::size_t n) const
	{
		return n*price;
	}
	virtual ~Quote() = default;		//对析构函数进行动态绑定
private:
	std::string bookNo;
protected:
	double price = 0;		//代表普通状态下不打折的价格
};

class bulk_quote : public Quote {
public:
	bulk_quote() = default;
	bulk_quote(const std::string &book, double p, std::size_t qty, double disc):
		Quote(book,p),min_qty(qty),discount(disc){}
	//覆盖基类的函数版本以实现基于大量购买的折扣政策
	double net_price(std::size_t)const override;
private:
	std::size_t min_qty = 0;
	double discount = 0.0;
};

double bulk_quote::net_price(std::size_t cnt) const
{
	if (cnt >= min_qty)
		return cnt * (1 - discount) * price;
	else
		return cnt * price;
}

double print_total(std::ostream &os,
	const Quote &item, size_t n)
{
	//根据传入item形参的对象类型调用Quote::net_price
	//或者Bulk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()		//调用Quote::isbn
		<< " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}
#endif // !QUOTE_H