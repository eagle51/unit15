#ifndef BASKET_H
#define BASKET_H
#include <memory>
#include "quote.h"
#include <set>
class Basket {
public:
	//Basket使用合成的默认构造函数和拷贝控制成员
	void add_item(const std::shared_ptr<Quote> &sale)
	{
		items.insert(sale);
	}

	void add_item(const Quote &sale)		//拷贝给定的对象
	{
		items.insert(shared_ptr<Quote>(sale.clone()));
	}
	void add_item(Quote &&sale)			//移动给定的的对象
	{
		items.insert(shared_ptr<Quote>(std::move(sale).clone()));
	}

	//打印每本书的总价和购物篮中所有书的总价
	double total_receipt(std::ostream &) const;
private:
	//该函数用于比较shared_ptr，multiset成员会用到它
	static bool compare(const std::shared_ptr<Quote> &lhs,
		const std::shared_ptr<Quote> &rhs)
	{
		return lhs->isbn() < rhs->isbn();
	}

	//multiset保存多个报价,按照compare成员排序
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{ compare };
};

double Basket::total_receipt(std::ostream &os) const
{
	double sum = 0.0;			//保存实时计算出的总价格
	//iter指向ISBN相同的一批元素中的第一个
	//upper_bound返回一个迭代器，该迭代器指向这批元素的尾后位置
	for (auto iter = items.cbegin();iter != items.cend();iter = items.upper_bound(*iter)) {
		//我们知道在当前的Basket中至少有一个该关键字的元素
		//打印该书籍对应的项目
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << std::endl;
	return sum;
}
#endif // !BASKET_H