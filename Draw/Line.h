#pragma once
#include "MapElement.h"
class CLine :
	public CMapElement
{
public:
	CLine();
	~CLine();
	void draw(CDC *pDC);
	int GetType();
};

