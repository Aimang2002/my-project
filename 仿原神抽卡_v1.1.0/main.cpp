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
	

	/*������� ʮ��ģ�� �����*/
	/*������� ����ģ�� �����*/
	/*�����ݱ��浽����һ�������У���¼���Ǻ����ǣ��Լ����ǳ��ֵ�λ�ã�������ݴ�ŵ�Ӳ��  �����*/
	/*��ʾ�������ǡ����ǡ�������Ʒ  ����� */
	/*ʵ�ֻص�����  �����*/
	/*��UP�ͷ�UP  �����*/

	system("pause");
	return 0;
}