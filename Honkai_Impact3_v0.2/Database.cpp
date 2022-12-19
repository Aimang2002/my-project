#include "Database.h"

Database* Database::m_instance = nullptr;

Database::Database()
{
	this->all_read_record_data[0] = &this->read_HomeSupplyRecord_data;
	this->all_read_record_data[1] = &this->read_ExpandSupplyRecord_data;

	this->recordData_path[0] = HOMESUPPLYRECORDPATH;
	this->recordData_path[1] = EXPANDSUPPLYRECORDPATH;

	this->code.push_back(HOMESUPPLY_CODE);
	this->code.push_back(EXPANDSUPPLY_CODE);

	this->readFile();
}

Database* Database::instance()
{
	if (m_instance == nullptr)m_instance = new Database();
	return m_instance;
}

void Database::readFile()
{
	cout << "���ڳ�ʼ��......" << endl;
	// Ԥ����
	string filePath[] = { SGRADEPATH,AGRADEPATH,BGRADEPATH,FOURWEAPONPATH,FOURSTIGMATAPATH,THREEWEAPONPATH,
	THREESTIGMATAPATH,EVOLVEMATERIALPATH,EXPERIENCEMATERIALPATH,GOLDMATERIALPATH,LIMITSGRADEPAHT,LIMITFIVEWEAPONPAHT,LIMITSPGRADEPAHT};

	map<int, string>* vessel[13];
	vessel[0] = &this->read_SGrade_data;
	vessel[1] = &this->read_AGrade_data;
	vessel[2] = &this->read_BGrade_data;
	vessel[3] = &this->read_fourWeapon_data;
	vessel[4] = &this->read_fourStigmata_data;
	vessel[5] = &this->read_threeWeapon_data;
	vessel[6] = &this->read_threeStigmata_data;
	vessel[7] = &this->read_evolveMaterial_data;
	vessel[8] = &this->read_experienceMaterial_data;
	vessel[9] = &this->read_goldMaterial_data;
	vessel[10] = &this->read_limitSGrade_data;
	vessel[11] = &this->read_limitFiveWeapon_data;
	vessel[12] = &this->read_SPGrade_data;

	// ��ȡ  
	ifstream ifs;
	for (int i = 0; i < (sizeof(filePath) / sizeof(filePath[0])); i++)
	{
		ifs.open(filePath[i], ios::in);
		if (!ifs.is_open())
		{
			string str = __LINE__ + "��myDatabase.cpp\tfile open error";
			// Log::write(str);
			exit(FILEPATH_OPEN_ERROR);
		}

		// ��ȡ�ļ�
		pair<int, string>p;
		while (ifs >> p.first >> p.second)
		{
			// ��������
			vessel[i]->insert(p);
		}	
		ifs.close();
	}
	


	// ��ȡ��ȡ������Ϣ
	for (int i = 0; i < (sizeof(this->recordData_path) / sizeof(this->recordData_path[0])); i++)
	{
		ifs.open(this->recordData_path[i], ios::in);
		if (!ifs.is_open())
		{
			string str = __LINE__ + "��myDatabase.cpp\tfile open error";
			// Log::write(str);
			exit(FILEPATH_OPEN_ERROR);
		}

		pair<int, string>p;
		while (ifs >> p.first >> p.second)
		{
			this->all_read_record_data[i]->push_back(p);
		}
		ifs.close();
	}
	

	// ��ȡ����ʥ��
	ifs.open(LIMITFIVESTIGMATAPAHT, ios::in);
	if (!ifs.is_open())
	{
		string str = __LINE__ + "��myDatabase.cpp\tfile open error";
		// Log::write(str);
		exit(FILEPATH_OPEN_ERROR);
	}

	vector<string>stigmataName(3); //ʥ������
	int stigmataID = 0; // ʥ��ID
	while (ifs >> stigmataID >> stigmataName[0] >> stigmataName[1] >> stigmataName[2])
	{
		this->read_limitFiveStigmata_data.insert(make_pair(stigmataID,stigmataName));
	}
	ifs.close();

	cout << "��ʼ����ɣ�\n��ʾ��Ϣ�������..." << endl;
	Sleep(1500);
	system("cls");
}

void Database::writeFile(const string path)
{
	if (this->tempDateSave.size() < 1)exit(VESSEL_EMPTY);
	// ���ļ�
	ofstream ofs(path, ios::out|ios::app);
	// �ж��ļ��Ƿ�򿪳ɹ�
	if (!ofs.is_open())
	{
		string str = __LINE__ + "��myDatabase.cpp\tfile open error";
		// Log::write(str);
		exit(FILEPATH_OPEN_ERROR);
	}

	for (auto it = this->tempDateSave.begin();it!=this->tempDateSave.end();it++)
	{
		ofs << it->first << "\t" << it->second << endl; 
	}

	ofs.close();
}

void Database::syncData(const int supply_code,const int target)
{
	pair<int, string>p;
	bool flag = true;
	if (target == 1 || target == 10)
	{
		for (int i = 0; i < (sizeof(this->code) / sizeof(this->code[0])) && flag; i++)
		{
			if (supply_code == this->code[i])
			{
				flag = !flag;
				if (this->tempDateSave.size() != target)exit(PARAMETER_ERROR);
				for (int j = 0; j < target; j++)
				{
					p = this->tempDateSave[j];
 					this->all_read_record_data[i]->push_back(p);
				}

			}
		}
	}
	else exit(PARAMETER_ERROR);
}

void Database::testFunction()
{
	// �޶�S��ɫ
	cout << "�޶�S��ɫ" << endl;
	for (auto it = this->read_limitSGrade_data.begin(); it != this->read_limitSGrade_data.end(); it++)
	{
		cout << it->first << "\t" << it->second << endl;
	}

	// ��������
	cout << "-----------" << endl;
	cout << "��������" << endl;
	for (auto it = this->read_limitFiveWeapon_data.begin(); it != this->read_limitFiveWeapon_data.end(); it++)
	{
		cout << it->first << "\t" << it->second << endl;
	}

	// ����ʥ��
	cout << "-----------" << endl;
	cout << "����ʥ��" << endl;
	for (auto it = this->read_limitFiveStigmata_data.begin(); it != this->read_limitFiveStigmata_data.end(); it++)
	{
		cout << it->first << "\t" << it->second[0]<<"\t"<<it->second[1]<<"\t"<<it->second[2] << endl;
	}
}

Database::~Database()
{
	if (m_instance != nullptr)
	{
		cout << "��ʾ������Database�ͷ�" << endl;
		//delete m_instance;
		// m_instance = nullptr;
	}
}
