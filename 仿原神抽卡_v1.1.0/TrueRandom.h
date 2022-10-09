#pragma once
#include<iostream>
#include<vector>
#include "DataSave.h"
#include "config.h"
#include"Arms.h"

using namespace std;

class TrueRandom
{
public:
	//���캯��
	TrueRandom();

	//ʮ����
	void tenContinu();

	//����
	void onceExtract();

private:

	// ���ݻָ�
	void recoveryData();

	//�����
	double setRandom();

	// ���ǲ���
	void fourStars_compensation(const double num);

	// ���ǲ���
	void fiveStars_compensation(const double num);

	//�ж�ϡ�ж�
	void Rarity(const double num);

	//��ʾ������ʮ������
	void printTenVector();

	//��ʾ�������һ������
	void printSingleData();

	//�����������
	void clearVector();

	//����
	int fourguaranteed; //���Ǳ���
	int record_fiveStars_position; //��¼���ǳ��ֵ�λ��
	vector<int>v; //�����¼
	vector<int>data; //�洢��ǰʮ�����
	DataSave DS;
	Arms AM;
};