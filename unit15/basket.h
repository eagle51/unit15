#ifndef BASKET_H
#define BASKET_H
#include <memory>
#include "quote.h"
#include <set>
class Basket {
public:
	//Basketʹ�úϳɵ�Ĭ�Ϲ��캯���Ϳ������Ƴ�Ա
	void add_item(const std::shared_ptr<Quote> &sale)
	{
		items.insert(sale);
	}

	void add_item(const Quote &sale)		//���������Ķ���
	{
		items.insert(shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote &&sale)			//�ƶ������ĵĶ���
	{
		items.insert(shared_ptr<Quote>(std::move(sale).clone()));
	}

	//��ӡÿ������ܼۺ͹���������������ܼ�
	double total_receipt(std::ostream &) const;
private:
	//�ú������ڱȽ�shared_ptr��multiset��Ա���õ���
	static bool compare(const std::shared_ptr<Quote> &lhs,
		const std::shared_ptr<Quote> &rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}

	//multiset����������,����compare��Ա����
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{ compare };
};

double Basket::total_receipt(std::ostream &os) const
{
	double sum = 0.0;			//����ʵʱ��������ܼ۸�
	//iterָ��ISBN��ͬ��һ��Ԫ���еĵ�һ��
	//upper_bound����һ�����������õ�����ָ������Ԫ�ص�β��λ��
	for (auto iter = items.cbegin();iter != items.cend();iter = items.upper_bound(*iter)) {
		//����֪���ڵ�ǰ��Basket��������һ���ùؼ��ֵ�Ԫ��
		//��ӡ���鼮��Ӧ����Ŀ
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << std::endl;
	return sum;
}
#endif // !BASKET_H