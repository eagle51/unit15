#include <iostream>
#include <vector>
#include <memory>
#include "quote.h"
using namespace std;
int main()
{
	vector<Quote> vq;
	vq.push_back(Quote("0-201-82470-1", 50));
	vq.push_back(bulk_quote("1-201-54848-8", 50, 10, 0.25));
	cout << vq.front().net_price(15) + vq.back().net_price(15) << endl;
	vector<shared_ptr<Quote>> basket;
	basket.push_back(make_shared<Quote>("0-201-82470-1", 50));
	basket.push_back(make_shared<bulk_quote>("1-201-54848-8", 50, 10, 0.25));
	cout << basket.front()->net_price(15) + basket.back()->net_price(15) << endl;
	system("pause");
	return 0;
}
//2016年6月29日15:52:34
//实验室