#pragma once
#include<iostream>
using namespace std;
#include<fstream>
#include<vector>
#include"config.h"
#include"Arms.h"


class DataSave
{
public:
	//���캯��
	DataSave();

	//��������
	void saveTenData(const vector<int>&v);

	//���浥������
	void saveSingleDate(const vector<int>& v);

	//�������
	void printRecord();

	//��ȡ���һ�����ǳ��ֵ�λ��
	int getLastFiveStarsPosition();

	//��ȡ���һ�����ǳ��ֵ�λ��
	int getLastFourStarsPosition();

	//���ټ�¼
	void destroyRecord();

private:
	int fourStarsSum; //��������
	int fiveStarsSum; //��������
	int fiveStarsLastPosition; //�������һ�γ��ֵ�λ��
	int fourStarsLasePosition; //�������һ�γ��ֵ�λ��
	vector<int>save_V;
	Arms AM;
};