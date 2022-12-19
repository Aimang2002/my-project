#include"ExpandSupply_Role.h"

ExpandSupply::ExpandSupply()
{
	this->mdb = Database::instance();
	this->m_random_number = 0;
	this->m_minSupply_number = 0;
	this->m_maxSupply_number = 0;
	this->dataPrestrain();
	this->presentSupply_role();
}

void ExpandSupply::dataPrestrain()
{
	this->KJ_ID = { LIMITSGRADE_ID,SPGRADE_ID,AGRADE_ID,SPGRADE_ID,AGRADE_ID,EVOLVEMATERIAL_ID,EXPERIENCEMATERIAL_ID,GOLDMATERIAL_ID };
	this->KJ_chance.push_back(make_pair(EXPANDSUPPLY_LIMITSGRADE_PROBABILITY_BEGIN, EXPANDSUPPLY_LIMITSGRADE_PROBABILITY_END));
	this->KJ_chance.push_back(make_pair(EXPANDSUPPLY_SPGRADE_PROBABILITY_BEGIN, EXPANDSUPPLY_SPGRADE_PROBABILITY_END));
	this->KJ_chance.push_back(make_pair(EXPANDSUPPLY_AGRADE_PROBABILITY_BEGIN, EXPANDSUPPLY_AGRADE_PROBABILITY_END));
	this->KJ_chance.push_back(make_pair(EXPANDSUPPLY_SPGRADE_FRAGMENT_PROBABILITY_BEGIN, EXPANDSUPPLY_SPGRADE_FRAGMENT_PROBABILITY_END));
	this->KJ_chance.push_back(make_pair(EXPANDSUPPLY_AGRADE_FRAGMENT_PROBABILITY_BEGIN, EXPANDSUPPLY_AGRADE_FRAGMENT_PROBABILITY_END));
	this->KJ_chance.push_back(make_pair(EXPANDSUPPLY_EVOLVEMATERIAL_PROBABILITY_BEGIN, EXPANDSUPPLY_EVOLVEMATERIAL_PROBABILITY_END));
	this->KJ_chance.push_back(make_pair(EXPANDSUPPLY_EXPERIENCEMATERIAL_PROBABILITY_BEGIN, EXPANDSUPPLY_EXPERIENCEMATERIAL_PROBABILITY_END));
	this->KJ_chance.push_back(make_pair(EXPANDSUPPLY_GOLDMATERIAL_PROBABILITY_BEGIN, EXPANDSUPPLY_GOLDMATERIAL_PROBABILITY_END));
}

void ExpandSupply::makerRandomNumber()
{
	this->m_random_number = (double)(rand() % 10000 + 1) / 100;
}

void ExpandSupply::presentSupply_role()
{
	//����UP��ɫ
	int random_index = rand() % this->mdb->read_limitSGrade_data.size() + LIMITSGRADE_ID + 1;  //�����ѡ
	this->SRole.first = random_index;
	this->SRole.second = this->mdb->read_limitSGrade_data[random_index];

	// ����SP��ɫ
	cout << this->mdb->read_SPGrade_data.size() << endl;
	random_index = rand() % this->mdb->read_SPGrade_data.size() + (SPGRADE_ID + 1);
	this->ARoleGroup.push_back(make_pair(random_index, this->mdb->read_SPGrade_data[random_index]));

	//����A��ɫ
	for (int i = 0; i < 3; i++)
	{
		random_index = rand() % this->mdb->read_AGrade_data.size() + (AGRADE_ID + 1);
		this->ARoleGroup.push_back(make_pair(random_index, this->mdb->read_AGrade_data[random_index]));
	}
}


int ExpandSupply::keynumberJudeg()
{
	for (int i = 0; i < this->KJ_ID.size(); i++)
	{
		if (this->m_random_number >= KJ_chance[i].first && this->m_random_number <= KJ_chance[i].second)
		{
			return KJ_ID[i];
		}
	}
	return COMMON_ERROR;
}

void ExpandSupply::mandatoryGain()
{
	if (this->m_maxSupply_number > 99)
	{
		this->mdb->tempDateSave.push_back(this->SRole);
		this->m_maxSupply_number = 0;
	}
	else if (this->m_minSupply_number > 9)
	{
		int random_index = rand() % this->ARoleGroup.size();
		this->mdb->tempDateSave.push_back(this->ARoleGroup[random_index]);
		this->m_minSupply_number %= 10;
	}
}

void ExpandSupply::supplyAdjustment(const int keyID)
{
	switch (keyID)
	{
	case LIMITSGRADE_ID:
		this->mdb->tempDateSave.push_back(this->SRole);
		this->m_maxSupply_number = 0;
		break;
	case SPGRADE_ID:
	{
		if (rand() % 2) this->mdb->tempDateSave.push_back(this->ARoleGroup[0]);
		else
		{
			pair<int, string>p;
			p.first = this->ARoleGroup[0].first;
			p.second = this->ARoleGroup[0].second + "��Ƭ��30��";
			this->mdb->tempDateSave.push_back(p);
		}
		this->m_minSupply_number = 0;
	}
	break;
	case AGRADE_ID:
	{
		int random_index = rand() % (this->ARoleGroup.size() - 1) + 1;
		//��ɫ����Ƭ
		if (rand() % 2) this->mdb->tempDateSave.push_back(this->ARoleGroup[random_index]);
		else
		{
			pair<int, string>p;
			p.first = this->ARoleGroup[random_index].first;
			p.second = this->ARoleGroup[random_index].second + "��Ƭ��30��";
			this->mdb->tempDateSave.push_back(p);
		}
		this->m_minSupply_number = 0;
	}
	break;
	case EVOLVEMATERIAL_ID:
	{
		int random_index = rand() % this->mdb->read_evolveMaterial_data.size() + EVOLVEMATERIAL_ID + 1;
		this->mdb->tempDateSave.push_back(make_pair(random_index, this->mdb->read_evolveMaterial_data.find(random_index)->second));
	}
	break;
	case EXPERIENCEMATERIAL_ID:
	{
		int random_index = rand() % this->mdb->read_experienceMaterial_data.size() + EXPERIENCEMATERIAL_ID + 1;
		this->mdb->tempDateSave.push_back(make_pair(random_index, this->mdb->read_experienceMaterial_data.find(random_index)->second));
	}
	break;
	case GOLDMATERIAL_ID:
	{
		int random_index = rand() % this->mdb->read_goldMaterial_data.size() + GOLDMATERIAL_ID + 1;
		this->mdb->tempDateSave.push_back(make_pair(random_index, this->mdb->read_goldMaterial_data.find(random_index)->second));
	}
	break;
	default:
		cout << "����������" << __LINE__ << endl;
		cout << "keyID = " << keyID << endl;
		exit(-1);
		break;
	}
}

void ExpandSupply::singleSupply()
{
	this->m_maxSupply_number++;
	this->m_minSupply_number++;
	
	if (this->m_maxSupply_number > 99 || this->m_minSupply_number > 9)this->mandatoryGain(); // ǿ�Ʋ���
	else
	{
		this->makerRandomNumber();
		int keyID = this->keynumberJudeg();
		
		if (keyID == LIMITSGRADE_ID) // ����ƫ��  �������ʹ��߿��޸ģ�
		{ 
			if ((rand() % 2) != rand() % 2)keyID = EVOLVEMATERIAL_ID;
		}
		supplyAdjustment(keyID);
	}
		
	// ����ͬ��
	this->mdb->writeFile(EXPANDSUPPLYRECORDPATH);			// ������д���ļ���
	this->mdb->syncData(EXPANDSUPPLY_CODE,1);				// ����ͬ��
	this->ExpandSupply_saveSupplyData();					// ���汣����ֵ
	this->showSupplyresult();								// ������
	this->mdb->tempDateSave.clear();						// �����ʱ��¼
}

void ExpandSupply::tenSupply()
{
	int keyID = 0;
	for (int i = 0; i < 10; i++)
	{
		this->m_maxSupply_number++;
		this->m_minSupply_number++;
		if (this->m_maxSupply_number > 99 || this->m_minSupply_number > 9)this->mandatoryGain(); // ǿ�Ʋ���
		else
		{
			this->makerRandomNumber();
			keyID = this->keynumberJudeg();

			if (keyID == LIMITSGRADE_ID) // S����ƫ��  �������ʹ��߿��޸ģ�
			{
				if ((rand() % 2) != rand() % 2)keyID = EVOLVEMATERIAL_ID;
			}
			else if (keyID == AGRADE_ID || keyID == AGRADE_FRAGMENT_ID || keyID == SPGRADE_ID) // A����ƫ��
			{
				if ((rand() % 2) != rand() % 2)keyID = EVOLVEMATERIAL_ID;
			}
			supplyAdjustment(keyID);
		}
	}
	this->mdb->writeFile(EXPANDSUPPLYRECORDPATH);			
	this->mdb->syncData(EXPANDSUPPLY_CODE, 10);		
	this->ExpandSupply_saveSupplyData();
	this->showSupplyresult();								
	this->mdb->tempDateSave.clear();										
}

void ExpandSupply::ExpandSupply_saveSupplyData()
{
	ofstream ofs(EXPANDSUPPLY_MINIMUM_RECORD, ios::out || ios::ate);
	if (!ofs.is_open())
	{
		string str = __LINE__ + "��HomeSupply.cpp\tfile open error";
		// Log::write(str);
		exit(FILEPATH_OPEN_ERROR);
	}

	ofs << this->m_minSupply_number << "\t" << this->m_maxSupply_number << endl;

	ofs.close();
}

void ExpandSupply::showSupplyresult()
{
	pair<int, string>p;
	for (auto it = this->mdb->tempDateSave.begin(); it != this->mdb->tempDateSave.end(); it++)
	{
		p.first = it->first;
		p.second = it->second;
		FontColor::modifyColor(p);
		cout << endl;
	}
	system("pause");
	system("cls"); 
}


void ExpandSupply::showRecordData()
{

	if (this->mdb->read_ExpandSupplyRecord_data.size() < 1)
	{
		cout << "��������......" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "\t\t\t\t--------------��ɫ���䲹��--------------\n" << endl;

	// �������
	_COORD coord;
	coord.X = 55;
	coord.Y = 3;
	short count = 0;

	pair<int, string>p;

	for (auto it = this->mdb->read_ExpandSupplyRecord_data.begin(); it != this->mdb->read_ExpandSupplyRecord_data.end(); it++, count++)
	{
		if (count == 2 || count == 0)
		{
			count = 0;
			cout << "\n\t";
		}
		else
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // �ն��������
			coord.Y++;
		}

		p.first = it->first;
		p.second = it->second;
		FontColor::modifyColor(p);
	}
	this->showanalyseRecordData();
}


void ExpandSupply::showanalyseRecordData()
{
	int SGrade_Sum = 0;  // ��ȡS����ɫ����
	for (const auto& i : this->mdb->read_ExpandSupplyRecord_data)
	{
		if (i.first > LIMITSGRADE_ID && i.first < (LIMITSGRADE_ID + 99))SGrade_Sum++;
	}

	cout << "\n\n\n" << endl;
	cout << "�ܹ�����������\t" << this->mdb->read_ExpandSupplyRecord_data.size() << "��" << endl;
	cout << "��ȡ���ѣ�\t" << this->mdb->read_ExpandSupplyRecord_data.size() * EXPANDSUPPLY_PRICE << "ˮ��" << endl;
	cout << "S����ɫ������\t" << SGrade_Sum << "��" << endl;
	cout << "ƽ����ȡS����ɫ��" << (SGrade_Sum ? this->mdb->read_ExpandSupplyRecord_data.size() / SGrade_Sum : this->mdb->read_ExpandSupplyRecord_data.size()) << "�β���" << endl;
	system("pause");
	system("cls");
}

ExpandSupply::~ExpandSupply()
{

}
