#pragma once
#include "dm.h"

struct SObjId
{
	unsigned long long id1;
	unsigned long long id2;
};

struct SPoint
{
	float x;
	float y;
	float z;
};

struct SChaoXiang
{
	float x;
	float y;
};

class gameObject
{

public:
	dm::Dmsoft* m_dm = 0;
	unsigned long long m_nodeObj;
	unsigned long long m_obj = 0;
	SObjId m_id;
	SObjId m_suoShuId;
	unsigned char m_type = 0;
	gameObject() {};
	gameObject(dm::Dmsoft* pdm , unsigned long long node);

	void printGameObj();

        std::wstring getName();
        SPoint getPoint();

};

