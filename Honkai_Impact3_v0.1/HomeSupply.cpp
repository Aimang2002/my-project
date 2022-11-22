#include "HomeSupply.h"


HomeSupply::HomeSupply()
{
	this->mdb = new HomeSupplyDatabase; // ��Ҫ�ֶ��ͷ�
	this->m_random_number = 0.0;
	this->m_minSupply_number = 0;
	this->m_maxSupply_number = 0;
	this->HomeSupply_readSupplyData();
	this->dataPrestrain();
}

void HomeSupply::dataPrestrain()
{
	this->retID = { SGRADE_ID ,SGRADE_FRAGMENT_ID,AGRADE_ID ,AGRADE_FRAGMENT_ID,BGRADE_ID,FURSTRARWEAPON_ID ,FOURSTRARSTIGMATA_ID,
		THREESTRARWEAPON_ID,THREESTRARSTIGMATA_ID, EVOLVEMATERIAL_ID ,EXPERIENCEMATERIAL_ID ,GOLDMATERIAL_ID };

	chance.push_back(make_pair(HOMESUPPLY_SGRADE_PROBABILITY_BEGIN, HOMESUPPLY_SGRADE_PROBABILITY_END));
	chance.push_back(make_pair(HOMESUPPLY_SGRADE_FRAGMENT_PROBABILITY_BEGIN, HOMESUPPLY_SGRADE_FRAGMENT_PROBABILITY_END));
	chance.push_back(make_pair(HOMESUPPLY_AGRADE_PROBABILITY_BEGIN, HOMESUPPLY_AGRADE_PROBABILITY_END));
	chance.push_back(make_pair(HOMESUPPLY_AGRADE_FRAGMENT_PROBABILITY_BEGIN, HOMESUPPLY_AGRADE_FRAGMENT_PROBABILITY_END));
	chance.push_back(make_pair(HOMESUPPLY_BGRADE_PROBABILITY_BEGIN, HOMESUPPLY_BGRADE_PROBABILITY_END));
	chance.push_back(make_pair(HOMESUPPLY_FOURSTRARWEAPON_PROBABILITY_BEGIN, HOMESUPPLY_FOURSTRARWEAPON_PROBABILITY_END));
	chance.push_back(make_pair(HOMESUPPLY_FOURSTRARSTIGMATA_PROBABILITY_BEGIN, HOMESUPPLY_FOURSTRARSTIGMATA_PROBABILITY_END));
	chance.push_back(make_pair(HOMESUPPLY_THREESTRARWEAPON_PROBABILITY_BEGIN, HOMESUPPLY_THREESTRARWEAPON_PROBABILITY_END));
	chance.push_back(make_pair(HOMESUPPLY_THREESTRARSTIGMATA_PROBABILITY_BEGIN, HOMESUPPLY_THREESTRARSTIGMATA_PROBABILITY_END));
	chance.push_back(make_pair(HOMESUPPLY_EVOLVEMATERIAL_PROBABILITY_BEGIN, HOMESUPPLY_EVOLVEMATERIAL_PROBABILITY_END));
	chance.push_back(make_pair(HOMESUPPLY_EXPERIENCEMATERIAL_PROBABILITY_BEGIN, HOMESUPPLY_EXPERIENCEMATERIAL_PROBABILITY_END));
	chance.push_back(make_pair(HOMESUPPLY_GOLDMATERIAL_PROBABILITY_BEGIN, HOMESUPPLY_GOLDMATERIAL_PROBABILITY_END));
}

void HomeSupply::makerRandomNumber()
{
	this->m_random_number = (double)(rand() % 10000 + 1) / 100;
}

void HomeSupply::singleSupply()
{
	//ǿ�Ʋ���
	if (this->m_maxSupply_number > 99 || this->m_minSupply_number > 9) this->mandatoryGain();
	else
	{
		this->m_minSupply_number++;								// ���׼�¼����
		this->m_maxSupply_number++;

		this->makerRandomNumber();								// ���������
		int keyID = this->keynumberJudeg();						// �ؼ����ж�

		if (keyID == SGRADE_ID || keyID == SGRADE_FRAGMENT_ID || keyID == AGRADE_ID || keyID == AGRADE_FRAGMENT_ID)
		{
			// ����ƫ��
			if ((rand() % 10) != (rand() % 10)) keyID = EVOLVEMATERIAL_ID;
		}
		supplyAdjustment(keyID);							// ��������ֱֵ�ӷ���mdb->tempDataSave��
	}
	this->mdb->writeFile();									// ������д���ļ���
	this->mdb->syncData();									// ͬ������
	this->showSupplyresult();								// ������
	this->mdb->tempDateSave.clear();						// �����ʱ����

	this->HomeSupply_saveSupplyData();						// ���汣����ֵ
	
}

void HomeSupply::tenSupply()
{
	int number = 10;
	while(number--)this->singleSupply();
}

int HomeSupply::keynumberJudeg()
{
	for (int i = 0; i < retID.size(); i++)
	{
		if (this->m_random_number >= chance[i].first && this->m_random_number <= chance[i].second)
		{
			return retID[i];
		}
	}
	return COMMON_ERROR;
}

void HomeSupply::supplyAdjustment(const int keyID) //�����Ż�
{
	switch (keyID)
	{
	case SGRADE_ID: // S��ɫ
		{
			int random_index = rand() % this->mdb->read_SGrade_data.size() + SGRADE_ID + 1; // ���廯  
			this->mdb->tempDateSave.insert(make_pair(random_index, (this->mdb->read_SGrade_data.find(random_index)->second + "��"))); // �����ݷ�����ʱ����
			this->m_maxSupply_number = 0;
		}
		break;
	case SGRADE_FRAGMENT_ID: // S��ɫ��Ƭ
		{
			int random_index = rand() % this->mdb->read_SGrade_data.size() + SGRADE_ID + 1;
			this->mdb->tempDateSave.insert(make_pair(random_index, (this->mdb->read_SGrade_data.find(random_index)->second + "��Ƭ��30��")));
			this->m_maxSupply_number = 0;
		}
		break;
	case AGRADE_ID: // A��ɫ
		{
			int random_index = rand() % this->mdb->read_AGrade_data.size() + AGRADE_ID + 1;
			this->mdb->tempDateSave.insert(make_pair(random_index, (this->mdb->read_AGrade_data.find(random_index)->second + "��")));
			this->m_minSupply_number = 0;
		}
		break;
	case AGRADE_FRAGMENT_ID: // A��ɫ��Ƭ
		{
			int random_index = rand() % this->mdb->read_SGrade_data.size() + AGRADE_ID + 1; 
			this->mdb->tempDateSave.insert(make_pair(random_index, (this->mdb->read_AGrade_data.find(random_index)->second + "��Ƭ��30��")));
			this->m_minSupply_number = 0;
		}
		break;
	case BGRADE_ID: // B��ɫ
		{
			int random_index = rand() % this->mdb->read_BGrade_data.size() + BGRADE_ID + 1; 
			this->mdb->tempDateSave.insert(make_pair(random_index, (this->mdb->read_BGrade_data.find(random_index)->second + "��")));
		}
		break;
	case FURSTRARWEAPON_ID:  // ��������
		{
			int random_index = rand() % this->mdb->read_fourWeapon_data.size() + FURSTRARWEAPON_ID + 1;
			this->mdb->tempDateSave.insert(make_pair(random_index, this->mdb->read_fourWeapon_data.find(random_index)->second));
		}
		break;
	case FOURSTRARSTIGMATA_ID: // ����ʥ��
		{
			int random_index = rand() % this->mdb->read_fourStigmata_data.size() + FOURSTRARSTIGMATA_ID + 1; 
			this->mdb->tempDateSave.insert(make_pair(random_index, this->mdb->read_fourStigmata_data.find(random_index)->second));
		}
		break;
	case THREESTRARWEAPON_ID: // ��������
		{
			int random_index = rand() % this->mdb->read_threeWeapon_data.size() + THREESTRARWEAPON_ID + 1; 
			this->mdb->tempDateSave.insert(make_pair(random_index, this->mdb->read_threeWeapon_data.find(random_index)->second));
		}
		break;
	case THREESTRARSTIGMATA_ID: // ����ʥ��
		{
			int random_index = rand() % this->mdb->read_threeStigmata_data.size() + THREESTRARSTIGMATA_ID + 1; 
			this->mdb->tempDateSave.insert(make_pair(random_index, this->mdb->read_threeStigmata_data.find(random_index)->second));
		}
		break; 
	case EVOLVEMATERIAL_ID: // ��������
		{
			int random_index = rand() % this->mdb->read_evolveMaterial_data.size() + EVOLVEMATERIAL_ID + 1; 
			this->mdb->tempDateSave.insert(make_pair(random_index, this->mdb->read_evolveMaterial_data.find(random_index)->second));
		}
		break;
	case EXPERIENCEMATERIAL_ID: //�������
		{
			int random_index = rand() % this->mdb->read_experienceMaterial_data.size() + EXPERIENCEMATERIAL_ID + 1; 
			this->mdb->tempDateSave.insert(make_pair(random_index, this->mdb->read_experienceMaterial_data.find(random_index)->second));
		}
		break;
	case GOLDMATERIAL_ID: //��Ҳ���
		{
			int random_index = rand() % this->mdb->read_goldMaterial_data.size() + GOLDMATERIAL_ID + 1; 
			this->mdb->tempDateSave.insert(make_pair(random_index, this->mdb->read_goldMaterial_data.find(random_index)->second));
		}
		break;
	default:
		{	// �쳣�к�+�쳣�ļ�+�쳣���+�쳣��Ϣ
			string str = __LINE__ + "��HomeSupply.cpp\tkeyID = " + keyID;
			str += "\tkeyID exception,Please check!";
			Log::write(str);
		}
		exit(-1);
		break;
	}
}

void HomeSupply::mandatoryGain()
{
	// �����������ʵ��UP�ͷ�UP
	int r = rand() % 2 + 0;

	if (this->m_maxSupply_number > 99)
	{
		if (r)
		{
			int random_index = rand() % this->mdb->read_SGrade_data.size() + SGRADE_ID + 1;
			this->mdb->tempDateSave.insert(make_pair(random_index, this->mdb->read_SGrade_data.find(random_index)->second));
			this->m_maxSupply_number = 0;
		}
		else
		{
			int random_index = rand() % this->mdb->read_SGrade_data.size() + SGRADE_ID + 1;  
			this->mdb->tempDateSave.insert(make_pair(random_index, (this->mdb->read_SGrade_data.find(random_index)->second + "��Ƭ��30��")));
			this->m_maxSupply_number = 0;
		}
		
	}
	else if (this->m_minSupply_number > 9)
	{
		if (r)
		{
			// A��ɫ
			int random_index = rand() % this->mdb->read_AGrade_data.size() + AGRADE_ID + 1;
			this->mdb->tempDateSave.insert(make_pair(random_index, this->mdb->read_AGrade_data.find(random_index)->second));
			this->m_minSupply_number = 0;
		}
		else
		{
			// A��ɫ
			int random_index = rand() % this->mdb->read_AGrade_data.size() + AGRADE_ID + 1;
			this->mdb->tempDateSave.insert(make_pair(random_index, (this->mdb->read_AGrade_data.find(random_index)->second + "��Ƭ��30��")));
			this->m_minSupply_number = 0;
		}
		
	}
}

void HomeSupply::showSupplyresult()
{
	pair<int, string>p;
	for (auto it = this->mdb->tempDateSave.begin(); it != this->mdb->tempDateSave.end(); it++)
	{
		p.first = it->first;
		p.second = it->second;
		this->modifyColor(p);
		cout << endl;
	}
}


void HomeSupply::showRecordData() 
{
	if (this->mdb->read_record_data.size() < 1)
	{
		cout << "��������......" << endl;
		return;
	}


	cout << "\t\t--------------��԰��ȡ----------------------\n" << endl;

	// �������
	COORD coord;
	coord.X = 55;
	coord.Y = 3;
	short count= 0; 

	pair<int, string>p;

	for (auto it = this->mdb->read_record_data.begin(); it != this->mdb->read_record_data.end(); it++,count++)
	{
		if (count == 2||count==0)
		{
			count = 0;
			cout << "\n\t";
		}
		else
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // �ն����궨λ
			coord.Y++;
		}

		p.first = it->first;
		p.second = it->second;
		this->modifyColor(p);
	}
	this->showanalyseRecordData();
}

void HomeSupply::showanalyseRecordData()
{
	int SGrade_Sum = 0;  // ��ȡS����ɫ����
	for (const auto& i : this->mdb->read_record_data)
	{
		if (i.first > SGRADE_ID && i.first < AGRADE_ID)SGrade_Sum++;
	}

	cout << "\n\n\n" << endl;
	cout << "�ܹ�����������\t" << this->mdb->read_record_data.size() << "��" << endl;
	cout << "��ȡ���ѣ�\t" << this->mdb->read_record_data.size() * HOMESUPPLY_PRICE << "ˮ��" << endl;
	cout << "S����ɫ������\t" << SGrade_Sum << "��" << endl;
	cout << "ƽ����ȡS����ɫ��" << (SGrade_Sum? this->mdb->read_record_data.size() / SGrade_Sum : this->mdb->read_record_data.size()) << "�β���" << endl;
}


void HomeSupply::modifyColor(const pair<int, string>& p)
{
	if (p.first > BGRADE_ID)				// ����(���Ǽ�����)
	{
		cout << "\t\t" << p.second;
	}
	else if(p.first> AGRADE_ID)			// ����(����)
	{
		cout << "\t\t" << "\033[35m" << p.second << "\033[0m";
	}
	else if(p.first>SGRADE_ID)			// һ��(����)
	{
		cout << "\t\t" << "\033[33m" << p.second << "\033[0m";
	}
	else
	{
		string str = __LINE__ + "��HomeSupply.cpp\tp.first = " + p.first;
		str += "\tp.first exception,Please check!";
		Log::write(str);
		exit(COMMON_ERROR);
	}
}

void HomeSupply::HomeSupply_saveSupplyData()
{
	ofstream ofs(SUPPLY_MINIMUM_RECORD, ios::out || ios::ate);
	if (!ofs.is_open())
	{
		string str = __LINE__ + "��HomeSupply.cpp\tfile open error";
		Log::write(str);
		exit(FILEPATH_OPEN_ERROR);
	}

	ofs << this->m_minSupply_number << "\t" << this->m_maxSupply_number << endl;

	ofs.close();
}

void HomeSupply::HomeSupply_readSupplyData()
{
	ifstream ifs(SUPPLY_MINIMUM_RECORD, ios::in);
	if (!ifs.is_open())
	{
		string str = __LINE__ + "��HomeSupply.cpp\tfile open error";
		Log::write(str);
		exit(FILEPATH_OPEN_ERROR);
	}
	// С����       �󲹸�
	ifs >> this->m_minSupply_number>> this->m_maxSupply_number;
	ifs.close();
}


HomeSupply::~HomeSupply()
{
	if (!this->mdb)
	{
		delete this->mdb;
		this->mdb = nullptr;
	}
}
