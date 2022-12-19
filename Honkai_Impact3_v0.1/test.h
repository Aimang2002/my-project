#pragma once
#include<iostream>
#include "Database.h"

class Prestrain
{
public:
	Prestrain()
	{
		this->DB = new Database();
	}

	Database* DB;
};

static Prestrain* PT = new Prestrain();
