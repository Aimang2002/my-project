#include "HomeSupply.h"

HomeSupply::HomeSupply()
{
	this->mdb = Database::instance();
	this->m_random_number = 0.0F;
	this->m_minSupply_number = 0;
	this->m_maxSupply_number = 0;
	this->HomeSupply_readSupplyData();
	this->dataPrestrain();
}

void HomeSupply::dataPrestrain()
{
	this->retID = { HOMESUUPLY_SGRADE_ID ,SGRADE_FRAGMENT_ID,AGRADE_ID ,AGRADE_FRAGMENT_ID,BGRADE_ID,FURSTRARWEAPON_ID ,FOURSTRARSTIGMATA_ID,
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
	this->m_minSupply_number++;								// 保底记录递增
	this->m_maxSupply_number++;

	if (this->m_maxSupply_number > 99 || this->m_minSupply_number > 9)this->mandatoryGain(); //强制补给
	else
	{
		this->makerRandomNumber();								// 生成随机数
		int keyID = this->keynumberJudeg();						// 关键字判断

		if (keyID == HOMESUUPLY_SGRADE_ID || keyID == SGRADE_FRAGMENT_ID || keyID == AGRADE_ID || keyID == AGRADE_FRAGMENT_ID)
		{
			// 概率偏移
			if (keyID == HOMESUUPLY_SGRADE_ID || keyID == SGRADE_FRAGMENT_ID)
			{
				if ((rand()% 2) != rand() % 2)keyID = EVOLVEMATERIAL_ID;
			}
			else
			{
				if ((rand() % 7 != rand() % 7)) keyID = GOLDMATERIAL_ID;
			}
		}
		supplyAdjustment(keyID);							// 最后调整的值直接放入mdb->tempDataSave中
	}
	this->mdb->writeFile(HOMESUPPLYRECORDPATH);				// 将数据写入文件中
	this->mdb->syncData(HOMESUPPLY_CODE,1);					// 数据同步
	this->showSupplyresult();								// 输出结果
	this->mdb->tempDateSave.clear();						// 清空临时记录

	this->HomeSupply_saveSupplyData();						// 保存保底数值
}

void HomeSupply::tenSupply()
{
	int keyID = 0;
	for (int i = 0; i < 10; i++)
	{
		this->m_minSupply_number++;
		this->m_maxSupply_number++;

		if (this->m_maxSupply_number > 99 || this->m_minSupply_number > 9)this->mandatoryGain();
		else
		{
			this->makerRandomNumber();								// 生成随机数
			keyID = this->keynumberJudeg();							// 关键字判断

			if (keyID == HOMESUUPLY_SGRADE_ID || keyID == SGRADE_FRAGMENT_ID || keyID == AGRADE_ID || keyID == AGRADE_FRAGMENT_ID)
			{
				// 概率偏移
				if (keyID == HOMESUUPLY_SGRADE_ID || keyID == SGRADE_FRAGMENT_ID)
				{
					if ((rand() % 2) != rand() % 2)keyID = EVOLVEMATERIAL_ID;
				}
				else
				{
					if ((rand() % 7 != rand() % 7)) keyID = GOLDMATERIAL_ID;
				}
			}
			supplyAdjustment(keyID);
		}
	}
	this->mdb->writeFile(HOMESUPPLYRECORDPATH);
	this->mdb->syncData(HOMESUPPLY_CODE,10);
	this->showSupplyresult();
	this->mdb->tempDateSave.clear();

	this->HomeSupply_saveSupplyData();

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

void HomeSupply::supplyAdjustment(const int keyID)
{
	switch (keyID)
	{
	case HOMESUUPLY_SGRADE_ID: // S角色
	{
		int random_index = rand() % this->mdb->read_SGrade_data.size() + HOMESUUPLY_SGRADE_ID + 1;
		this->mdb->tempDateSave.push_back(make_pair(random_index, (this->mdb->read_SGrade_data.find(random_index)->second)));
		this->m_maxSupply_number = 0;
	}
	break;
	case SGRADE_FRAGMENT_ID: // S角色碎片
	{
		int random_index = rand() % this->mdb->read_SGrade_data.size() + HOMESUUPLY_SGRADE_ID + 1;
		this->mdb->tempDateSave.push_back(make_pair(random_index, (this->mdb->read_SGrade_data.find(random_index)->second + "碎片×30块")));
		this->m_maxSupply_number = 0;
	}
	break;
	case AGRADE_ID: // A角色
	{
		int random_index = rand() % this->mdb->read_AGrade_data.size() + AGRADE_ID + 1;
		this->mdb->tempDateSave.push_back(make_pair(random_index, (this->mdb->read_AGrade_data.find(random_index)->second)));
		this->m_minSupply_number = 0;
	}
	break;
	case AGRADE_FRAGMENT_ID: // A角色碎片
	{
		int random_index = rand() % this->mdb->read_SGrade_data.size() + AGRADE_ID + 1;
		this->mdb->tempDateSave.push_back(make_pair(random_index, (this->mdb->read_AGrade_data.find(random_index)->second + "碎片×30块")));
		this->m_minSupply_number = 0;
	}
	break;
	case BGRADE_ID: // B角色
	{
		int random_index = rand() % this->mdb->read_BGrade_data.size() + BGRADE_ID + 1;
		this->mdb->tempDateSave.push_back(make_pair(random_index, (this->mdb->read_BGrade_data.find(random_index)->second)));
	}
	break;
	case FURSTRARWEAPON_ID:  // 四星武器
	{
		int random_index = rand() % this->mdb->read_fourWeapon_data.size() + FURSTRARWEAPON_ID + 1;
		this->mdb->tempDateSave.push_back(make_pair(random_index, this->mdb->read_fourWeapon_data.find(random_index)->second));
	}
	break;
	case FOURSTRARSTIGMATA_ID: // 四星圣痕
	{
		int random_index = rand() % this->mdb->read_fourStigmata_data.size() + FOURSTRARSTIGMATA_ID + 1;
		this->mdb->tempDateSave.push_back(make_pair(random_index, this->mdb->read_fourStigmata_data.find(random_index)->second));
	}
	break;
	case THREESTRARWEAPON_ID: // 三星武器
	{
		int random_index = rand() % this->mdb->read_threeWeapon_data.size() + THREESTRARWEAPON_ID + 1;
		this->mdb->tempDateSave.push_back(make_pair(random_index, this->mdb->read_threeWeapon_data.find(random_index)->second));
	}
	break;
	case THREESTRARSTIGMATA_ID: // 三星圣痕
	{
		int random_index = rand() % this->mdb->read_threeStigmata_data.size() + THREESTRARSTIGMATA_ID + 1;
		this->mdb->tempDateSave.push_back(make_pair(random_index, this->mdb->read_threeStigmata_data.find(random_index)->second));
	}
	break;
	case EVOLVEMATERIAL_ID: // 进化材料
	{
		int random_index = rand() % this->mdb->read_evolveMaterial_data.size() + EVOLVEMATERIAL_ID + 1;
		this->mdb->tempDateSave.push_back(make_pair(random_index, this->mdb->read_evolveMaterial_data.find(random_index)->second));
	}
	break;
	case EXPERIENCEMATERIAL_ID: //升级材料
	{
		int random_index = rand() % this->mdb->read_experienceMaterial_data.size() + EXPERIENCEMATERIAL_ID + 1;
		this->mdb->tempDateSave.push_back(make_pair(random_index, this->mdb->read_experienceMaterial_data.find(random_index)->second));
	}
	break;
	case GOLDMATERIAL_ID: //金币材料
	{
		int random_index = rand() % this->mdb->read_goldMaterial_data.size() + GOLDMATERIAL_ID + 1;
		this->mdb->tempDateSave.push_back(make_pair(random_index, this->mdb->read_goldMaterial_data.find(random_index)->second));
	}
	break;
	default:
	{	// 异常行号+异常文件+异常情况+异常信息
		string str = __LINE__ + "：HomeSupply.cpp\tkeyID = " + keyID;
		str += "\tkeyID exception,Please check!";
		// Log::write(str);
	}
	exit(-1);
	break;
	}
}

void HomeSupply::mandatoryGain()
{
	// 生成随机数，实现UP和非UP
	int r = rand() % 2;

	if (this->m_maxSupply_number > 99)
	{
		if (r)
		{
			int random_index = rand() % this->mdb->read_SGrade_data.size() + HOMESUUPLY_SGRADE_ID + 1;
			this->mdb->tempDateSave.push_back(make_pair(random_index, this->mdb->read_SGrade_data.find(random_index)->second));
			this->m_maxSupply_number %= 10;
		}
		else
		{
			int random_index = rand() % this->mdb->read_SGrade_data.size() + HOMESUUPLY_SGRADE_ID + 1;
			this->mdb->tempDateSave.push_back(make_pair(random_index, (this->mdb->read_SGrade_data.find(random_index)->second + "锟斤拷片锟斤拷30锟斤拷")));
			this->m_maxSupply_number %= 10;
		}

	}
	else if (this->m_minSupply_number > 9)
	{
		if (r)
		{
			// A角色
			int random_index = rand() % this->mdb->read_AGrade_data.size() + AGRADE_ID + 1;
			this->mdb->tempDateSave.push_back(make_pair(random_index, this->mdb->read_AGrade_data.find(random_index)->second));
			this->m_minSupply_number %= 10;
		}
		else
		{
			// A角色碎片
			int random_index = rand() % this->mdb->read_AGrade_data.size() + AGRADE_ID + 1;
			this->mdb->tempDateSave.push_back(make_pair(random_index, (this->mdb->read_AGrade_data.find(random_index)->second + "碎片×30块")));
			this->m_minSupply_number %= 10;
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
		FontColor::modifyColor(p);
		cout << endl;
	}
	system("pause");
	system("cls");
}


void HomeSupply::showRecordData()
{
	if (this->mdb->read_HomeSupplyRecord_data.size() < 1)
	{
		cout << "暂无数据......" << endl;
		system("pause");
		system("cls");
		return;
	}

	cout << "\t\t\t\t--------------家园补给--------------\n" << endl;

	// 坐标控制
	_COORD coord;
	coord.X = 55;
	coord.Y = 3;
	short count = 0;

	pair<int, string>p;

	for (auto it = this->mdb->read_HomeSupplyRecord_data.begin(); it != this->mdb->read_HomeSupplyRecord_data.end(); it++, count++)
	{
		if (count == 2 || count == 0)
		{
			count = 0;
			cout << "\n\t";
		}
		else
		{
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); // 终端坐标控制
			coord.Y++;
		}

		p.first = it->first;
		p.second = it->second;
		FontColor::modifyColor(p);
	}
	this->showanalyseRecordData();
}

void HomeSupply::showanalyseRecordData()
{
	int SGrade_Sum = 0;  // 获取S级角色数量
	for (const auto& i : this->mdb->read_HomeSupplyRecord_data)
	{
		if (i.first > HOMESUUPLY_SGRADE_ID && i.first < (HOMESUUPLY_SGRADE_ID + 99))SGrade_Sum++;
	}

	cout << "\n\n\n" << endl;
	cout << "总共补给次数：\t" << this->mdb->read_HomeSupplyRecord_data.size() << "次" << endl;
	cout << "抽取花费：\t" << this->mdb->read_HomeSupplyRecord_data.size() * HOMESUPPLY_PRICE << "水晶" << endl;
	cout << "S级角色获数：\t" << SGrade_Sum << "个" << endl;
	cout << "平均获取S级角色：" << (SGrade_Sum ? this->mdb->read_HomeSupplyRecord_data.size() / SGrade_Sum : this->mdb->read_HomeSupplyRecord_data.size()) << "次补给" << endl;
	system("pause");
	system("cls");
}

void HomeSupply::HomeSupply_saveSupplyData()
{
	ofstream ofs(HOMESUPPLY_MINIMUM_RECORD, ios::out || ios::ate);
	if (!ofs.is_open())
	{
		string str = __LINE__ + "：HomeSupply.cpp\tfile open error";
		// Log::write(str);
		exit(FILEPATH_OPEN_ERROR);
	}

	ofs << this->m_minSupply_number << "\t" << this->m_maxSupply_number << endl;

	ofs.close();
}

void HomeSupply::HomeSupply_readSupplyData()
{
	ifstream ifs(HOMESUPPLY_MINIMUM_RECORD, ios::in);
	if (!ifs.is_open())
	{
		string str = __LINE__ + "：HomeSupply.cpp\tfile open error";
		// Log::write(str);
		exit(FILEPATH_OPEN_ERROR);
	}
	// 小补给									大补给
	ifs >> this->m_minSupply_number >> this->m_maxSupply_number;
	ifs.close();
}


HomeSupply::~HomeSupply()
{
	/*
	if (!this->mdb)
	{
		delete this->mdb;
		this->mdb = nullptr;
	}
	*/
}
