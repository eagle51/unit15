#include "quote.h"
using namespace std;
int main()
{
	Quote q1("xxxx", 5);
	bulk_quote q2("xxxxx", 5, 4, 0.5);
	print_total(cout, q1, 3);
	print_total(cout, q2, 4);
	system("pause");
	return 0;
}
//2016年6月27日16:10:08
//实验室