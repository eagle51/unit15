#include <iostream>
#include <vector>
#include <memory>
#include "quote.h"
#include "basket.h"
using namespace std;
int main()
{
	Basket basket;
	for (unsigned int i = 0;i != 10;++i)
		basket.add_item(bulk_quote("Bible", 20.6,20, 0.3));
	for (unsigned int i = 0;i != 10;++i)
		basket.add_item(bulk_quote("C++Primer", 30.9, 5, 0.4));

	for (unsigned i = 0; i != 10; ++i)
		basket.add_item(Quote("CLRS", 40.1));

	basket.total_receipt(cout);
	system("pause");
	return 0;
}
//2016年6月29日17:36:10
//实验室