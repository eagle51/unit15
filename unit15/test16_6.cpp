#include <iostream>
#include <string>

using namespace std;
template <typename T, size_t N>
void print(const T (&a)[N])
{
	for (auto iter = begin(a);iter != end(a);++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
}

int main()
{
	int a[6]{ 0,2,4,6,8 };
	string vs[3]{ "Hello","world","!" };
	print(a);
	print(vs);
	system("pause");
	return 0;
}
//2016年7月1日16:23:10
//实验室