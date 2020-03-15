#pragma once
#include <iostream>
#include "CHAR.h"
class STRING
{
private:
	CHAR* content;
	int length;
public:
	STRING();
	//STRING(const char&);
	STRING(const STRING&);
	STRING(const char*);
	STRING(const CHAR&);
	STRING & Expand(const STRING&);
	STRING & Expand(const CHAR&);
	
	~STRING();
};

