#include "stdafx.h"
#include "MapList.h"


CMapList::CMapList()
{
}


CMapList::~CMapList()
{
	//�����б�������ָ��ָ��Ķ���
	for (int i = 0; i < GetSize(); i++) {
		delete GetAt(i);
	}
}
