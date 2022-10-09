#include "TrueRandom.h"


TrueRandom::TrueRandom()
{
	this->record_fiveStars_position = -1;
	this->fourguaranteed = this->DS.getLastFourStarsPosition();
	this->recoveryData();
}

void TrueRandom::recoveryData()
{
	ifstream ifs(RETURNFILE_DATACARD_PATH, ios::in);
	if (!ifs.is_open())throw exception();
	int count = 0;
	int data_value = 0;
	//������������
	while (ifs >> data_value)
	{
		count++;
		if (count > this->DS.getLastFiveStarsPosition())break;
	}
	//��ʽ�ָ�
	while (ifs >> data_value)
	{
		this->v.push_back(data_value);
	}
}

double TrueRandom::setRandom()
{
	return (double)(rand() % 1001) / 10; //0~100
}


void TrueRandom::tenContinu()
{
	this->data.clear();
	for (int i = 0; i < 10; i++)
	{
		double num = this->setRandom();
		fourguaranteed++;

		if ((this->v.size() + this->data.size()) > 77 && record_fiveStars_position == -1)//���Ǳ���
		{
			this->fiveStars_compensation(num);
		}
		else if (fourguaranteed >= 9)//���Ǳ���
		{
			this->fourStars_compensation(num);
		}
		else
		{
			this->Rarity(num);
		}

		if (this->record_fiveStars_position != -1)
		{
			this->clearVector();
			this->record_fiveStars_position = -1;
		}
	}
	for (vector<int>::iterator it = data.begin(); it != data.end(); it++)
	{
		this->v.push_back(*it);
	}
	this->DS.saveTenData(this->v); //ͬ�����ļ�
	this->printTenVector();
	cout << endl;
}

void TrueRandom::onceExtract()
{
	double num = this->setRandom();
	this->data.clear();
	fourguaranteed++;

	if (v.size() > 77 && record_fiveStars_position == -1)//���Ǳ���
	{
		this->fiveStars_compensation(num);
	}
	else if (fourguaranteed >= 9)//���Ǳ���
	{
		this->fourStars_compensation(num);
	}
	else
	{
		this->Rarity(num);
	}

	if (this->record_fiveStars_position != -1)
	{
		this->clearVector();
		this->record_fiveStars_position = -1;
	}

	//��������
	this->v.push_back(this->data.back());
	this->DS.saveSingleDate(v);
	//�����ǰ��ȡ״̬
	this->printSingleData();
}

// ���ǲ���
void TrueRandom::fourStars_compensation(const double num)
{
	if (num < FOURSTART_GOODS_BEGIN && num <= (56.1 + FOURSTART_GOODS_END) && fourguaranteed == 9 || fourguaranteed >= 10) //��������&&���Ա���
	{
		this->data.push_back(rand()%this->AM.getFourStarsNumber() + FOURSTARS_KEY_BEGIN);
		if (fourguaranteed >= 10) { this->fourguaranteed %=10; }
		else this->fourguaranteed = 0;
	}
	else
	{
		this->data.push_back(rand() % this->AM.getThreeStarsNumber() + THREESTARS_KEY_BEGIN);
	}
}

//���ǲ���
void TrueRandom::fiveStars_compensation(const double num)
{
	if ((this->v.size() + this->data.size()) > 77 && v.size() < 90) // ���ʲ���
	{
		double temp = FIVESTART_GOODS_END + ((v.size() - 77+this->data.size()) * 6.0);
		if (num >= FIVESTART_GOODS_BEGIN && num <= FIVESTART_GOODS_END || num > FOURSTART_GOODS_END && num <= temp) //0~0.6 || 5.9~temp
		{
			this->data.push_back(rand()%this->AM.getFiveStarsNumber() + FIVESTARS_KEY_BEGIN);
			this->record_fiveStars_position = v.size();
		}
		else
		{
			this->data.push_back(rand() % this->AM.getThreeStarsNumber() + THREESTARS_KEY_BEGIN);
		}
	}
	else if (v.size() >= 90) // ���Բ���
	{
		this->data.push_back(rand() % this->AM.getFiveStarsNumber() + FIVESTARS_KEY_BEGIN);
		this->record_fiveStars_position = v.size();
	}
}


void TrueRandom::Rarity(const double num)
{
	if (num >= FIVESTART_GOODS_BEGIN && num <= FIVESTART_GOODS_END) // ����
	{
		this->data.push_back(rand() % this->AM.getFiveStarsNumber() + FIVESTARS_KEY_BEGIN);
		this->record_fiveStars_position = v.size();
	}
	else if (num >= FOURSTART_GOODS_BEGIN && num <= FOURSTART_GOODS_END) // ����
	{
		this->data.push_back(rand() % this->AM.getFourStarsNumber() + FOURSTARS_KEY_BEGIN);
		this->fourguaranteed = 0;
	}
	else
	{
		this->data.push_back(rand() % this->AM.getThreeStarsNumber() + THREESTARS_KEY_BEGIN);
	}
}


void TrueRandom::printTenVector()
{
	for (int i = this->v.size() - 10; i < this->v.size(); i++)
	{
		map<int, string>::iterator ret = this->AM.getArms(this->v[i]);
		if (ret->first >= FIVESTARS_KEY_BEGIN)
		{
			cout << "\033[33m" << ret->second << "\033[0m" << " "; //��ɫ
		}
		else if (ret->first >= FOURSTARS_KEY_BEGIN)
		{
			cout << "\033[35m" << ret->second << "\033[0m" << " "; //��ɫ
		}
		else
		{
			cout << ret->second << " ";
		}
	}
	cout << "\n-----------------------------------------------------------------------------------------" << endl;
}

void TrueRandom::printSingleData()
{
	map<int,string>::iterator ret = this->AM.getArms(this->v.back());
	if (ret->first >= FIVESTARS_KEY_BEGIN)
	{
		cout << "\033[33m" << ret->second << "\033[0m" << " "; //��ɫ
	}
	else if (ret->first >= FOURSTARS_KEY_BEGIN)
	{
		cout << "\033[35m" << ret->second << "\033[0m" << " "; //��ɫ
	}
	else
	{
		cout << ret->second << " ";
	}
}

void TrueRandom::clearVector()
{
	
	vector<int>tempV;
	int index = 0;
	for (auto it = v.begin() + this->record_fiveStars_position; it != v.end(); it++, index++)
	{
		tempV.push_back(*it);
	}
	this->v.clear();
	this->v = tempV;
}


