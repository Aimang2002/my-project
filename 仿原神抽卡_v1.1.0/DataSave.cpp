#include "DataSave.h"
#include <iomanip>

DataSave::DataSave()
{
	this->fiveStarsLastPosition = 0;
	this->fourStarsLasePosition = 0;
	this->fiveStarsSum = 0;
	this->fourStarsSum = 0;

	ifstream ifs(RETURNFILE_DATACARD_PATH, ios::in);
	if (!ifs.is_open())
	{
		throw exception();
	}

	int number;
	int count = 0;
	while (ifs >> number)
	{
		if (number >= FIVESTARS_KEY_BEGIN)
		{
			this->fiveStarsLastPosition = count;
			this->fiveStarsSum++;
		}
		else if (number >= FOURSTARS_KEY_BEGIN)
		{
			this->fourStarsLasePosition = count;
			this->fourStarsSum++;
		}
		this->save_V.push_back(number);
		count++;
	}
	ifs.close();
}


void DataSave::saveTenData(const vector<int>&v)
{
	ofstream ofs(RETURNFILE_DATACARD_PATH, ios::out | ios::app);
	if (!ofs.is_open())
	{
		throw exception();
	}

	for (vector<int>::const_iterator it = (v.begin() + (v.size() - 10)); it != v.end(); it++) // ��������ʮ������д���ļ���
	{
		ofs << *it<< ' ';
	}
	ofs.close();
}

void DataSave::saveSingleDate(const vector<int>& v)
{
	ofstream ofs(RETURNFILE_DATACARD_PATH, ios::out | ios::app);
	if (!ofs.is_open())
	{
		throw exception();
	}
	ofs << v.back() << ' ';
	ofs.close();
}

int DataSave::getLastFiveStarsPosition()
{
	return this->fiveStarsLastPosition;
}

int DataSave::getLastFourStarsPosition()
{
	return this->fourStarsLasePosition;
}


void DataSave::printRecord()
{
	if (this->save_V.size() < 1)
	{
		cout << "�������ݣ�" << endl;
		return;
	}

	int index = 1;
	for (vector<int>::iterator it = this->save_V.begin(); it != this->save_V.end(); it++,index++)
	{
		map<int, string>::iterator ret = this->AM.getArms(*it);
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

		if (index % 6 == 0) 
		{
			cout << "\n------------------------------------------------------------------------------" << endl;
			index = 0;
		}
	}
	cout << "\n\n\n��ȡ����Ϊ��" << this->save_V.size() << endl;
	cout<< "�����ܻ�ȡΪ��" << this->fourStarsSum << "\t�����ܻ�ȡΪ��" << this->fiveStarsSum << endl;

	double fourStarsAverage = 0.00;
	double fiveStarsAverage = 0.00;
	if (fourStarsSum != 0)fourStarsAverage = (double)this->save_V.size() / this->fourStarsSum;
	if (fiveStarsSum != 0)fiveStarsAverage = (double)this->save_V.size() / this->fiveStarsSum;

	cout << fixed << setprecision(2) << "ƽ�������ǣ�" << fourStarsAverage << "��" << endl;
	cout << fixed << setprecision(2) << "ƽ�������ǣ�" << fiveStarsAverage << "��" << endl;
}

void DataSave::destroyRecord()
{
	char select = 'n';
	cout << "����ȷ���Ƿ�ɾ��(y/n)��";
	cin >> select;
	if (select == 'y')
	{
		ofstream ofs(RETURNFILE_DATACARD_PATH, ios::ate);
		ofs.close();
		cout << "ɾ���ɹ���" << endl;
	}
	else
	{
		cout<<"ȡ��ɾ��" << endl;
	}
}