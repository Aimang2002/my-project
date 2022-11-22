#include "HomeSupplyDatabase.h"

HomeSupplyDatabase::HomeSupplyDatabase()
{
	this->readFile();
}

void HomeSupplyDatabase::readFile()
{
	cout << "正在初始化......" << endl;
	// 预处理
	string filePath[] = { SGRADEPATH,AGRADEPATH,BGRADEPATH,FOURWEAPONPATH,FOURSTIGMATAPATH,THREEWEAPONPATH,
	THREESTIGMATAPATH,EVOLVEMATERIALPATH,EXPERIENCEMATERIALPATH,GOLDMATERIALPATH};

	map<int, string>* vessel[11];
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
	

	// 读取  
	ifstream ifs;
	for (int i = 0; i < (sizeof(filePath)/sizeof(filePath[0])); i++)
	{
		ifs.open(filePath[i], ios::in);
		if (!ifs.is_open())
		{
			string str = __LINE__ + "：myDatabase.cpp\tfile open error";
			Log::write(str);
			exit(FILEPATH_OPEN_ERROR);
		}

		// 读取文件
		pair<int, string>p;
		while (ifs >> p.first >> p.second)
		{
			// 插入数据
			vessel[i]->insert(p);
		}
		ifs.close();
	}

	// 读取抽取过的信息
	ifs.open(SUUPLYRECORDPATH, ios::in);
	if (!ifs.is_open())
	{
		string str = __LINE__ + "：myDatabase.cpp\tfile open error";
		Log::write(str);
		exit(FILEPATH_OPEN_ERROR);
	}
	
	pair<int, string>p;
	while (ifs >> p.first>>p.second)
	{
		this->read_record_data.push_back(p);
	}
	ifs.close();

	cout << "初始化完成！\n提示信息即将清空..." << endl;
	Sleep(1500);
	system("cls");
}

void HomeSupplyDatabase::writeFile()
{
	// 打开文件
	ofstream ofs(SUUPLYRECORDPATH, ios::out|ios::app);
	// 判断文件是否打开成功
	if (!ofs.is_open())
	{
		string str = __LINE__ + "：myDatabase.cpp\tfile open error";
		Log::write(str);
		exit(FILEPATH_OPEN_ERROR);
	}

	for (auto it = this->tempDateSave.begin();it!=this->tempDateSave.end();it++)
	{
		ofs << it->first << "\t" << it->second << endl; 
	}

	ofs.close();
}

void HomeSupplyDatabase::syncData()
{
	pair<int, string>p;
	p.first = this->tempDateSave.begin()->first;
	p.second = this->tempDateSave.begin()->second;
	this->read_record_data.push_back(p);
}
