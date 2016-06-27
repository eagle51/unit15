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

	//���ظ����������鼮�������ܶ�
	//�����ฺ���д��ʹ�ò�ͬ���ۿۼ����㷨
	virtual double net_price(std::size_t n) const
	{
		return n*price;
	}
	virtual ~Quote() = default;		//�������������ж�̬��
private:
	std::string bookNo;
protected:
	double price = 0;		//������ͨ״̬�²����۵ļ۸�
};

class bulk_quote : public Quote {
public:
	bulk_quote() = default;
	bulk_quote(const std::string &book, double p, std::size_t qty, double disc):
		Quote(book,p),min_qty(qty),discount(disc){}
	//���ǻ���ĺ����汾��ʵ�ֻ��ڴ���������ۿ�����
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
	//���ݴ���item�βεĶ������͵���Quote::net_price
	//����Bulk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn()		//����Quote::isbn
		<< " # sold: " << n << " total due: " << ret << std::endl;
	return ret;
}
#endif // !QUOTE_H