#include "stdafx.h"
#include "MapList.h"


CMapList::CMapList()
{
}


CMapList::~CMapList()
{
	//销毁列表中所有指针指向的对象
	for (int i = 0; i < GetSize(); i++) {
		delete GetAt(i);
	}
}
