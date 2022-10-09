#include "Arms.h"


Arms::Arms()
{
	this->filePath.push_back(RESOURCES_THREESTARS_PATH);
	this->filePath.push_back(RESOURCES_FOURSTARS_PATH);
	this->filePath.push_back(RESOURCES_FIVESTARS_PATH);

	//读取文件
	this->read_HD_File();
}

void ::Arms::read_HD_File()
{
	fstream fs;
	for (vector<string>::iterator it = this->filePath.begin(); it != this->filePath.end(); it++)
	{
		fs.open(*it, ios::in);
		if (!fs.is_open())
		{
			cout << "文件打开失败！" << endl;
			throw exception();
		}

		int key = 0;
		string value;
		while (fs >> key >> value)
		{
			//放入容器
			this->weapon.insert(make_pair(key, value));
			//统计物品数量
			if (key >= FIVESTARS_KEY_BEGIN)this->fiveStars_number++;
			else if (key >= FOURSTARS_KEY_BEGIN)this->fourStars_number++;
			else this->threeStars_number++;
		}
		fs.close();
	}
}

map<int, string>::iterator Arms::getArms(const int key)
{
	return this->weapon.find(key);
}


int Arms::getThreeStarsNumber()
{
	return this->threeStars_number - 1;
}

int Arms::getFourStarsNumber()
{
	return this->fourStars_number - 1;
}

int Arms::getFiveStarsNumber()
{
	return this->fiveStars_number - 1;
}