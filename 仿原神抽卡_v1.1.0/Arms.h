#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include<map>
#include<vector>
#include<string>
#include"config.h"

class Arms
{
public:
	// ���캯��
	Arms();

	// ��ȡ����
	map<int, string>::iterator getArms(const int key);

	// ��ȡ��������  ��0��ʼ
	int getThreeStarsNumber();

	// ��ȡ��������  ��0��ʼ
	int getFourStarsNumber();

	// ��ȡ��������  ��0��ʼ
	int getFiveStarsNumber();

private:
	
	map<int, string>weapon; // �������������
	vector<string>filePath; // �����ļ�·��

	int threeStars_number;	// ������������
	int fourStars_number;	// ������������
	int fiveStars_number;	// ������������

	// ��ȡӲ���ļ�
	void read_HD_File();
};
