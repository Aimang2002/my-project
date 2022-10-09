#include<iostream>
#include "TrueRandom.h"
#include "DataSave.h"
#include"Arms.h"
#include<Windows.h>
using namespace std;

void test01()
{
	TrueRandom *TR = new TrueRandom;
	for (int i = 0; i < 18; i++)
	{
		TR->tenContinu();
	}
}

void test02()
{
	DataSave *ds = new DataSave;
	ds->printRecord();
	ds->destroyRecord();
}

int main() {
	srand((unsigned int)time(NULL));
	test01();
	

	/*真随机数 十连模块 已完成*/
	/*真随机数 单次模块 已完成*/
	/*将数据保存到另外一个容器中，记录四星和五星，以及他们出现的位置，最后将数据存放到硬盘  已完成*/
	/*显示具体三星、四星、五星物品  已完成 */
	/*实现回档功能  已完成*/
	/*真UP和非UP  已完成*/

	system("pause");
	return 0;
}