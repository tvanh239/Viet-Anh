#include "STRING.h"
#include <iostream>
STRING::STRING()
{
	this->length = 0;
	this->content = new CHAR;
	this->content = NULL;
	
}
STRING::STRING(const STRING& new_string) {
	this->length = new_string.length;
	this->content = new CHAR[this->length];
	for (int i = 0; i < this->length; i++)
		this->content[i] = new_string.content[i];
}
STRING::STRING(const CHAR&temp)
{
	this->length = 1;
	this->content = new CHAR[this->length+1];
	this->content[0] = temp;
}
STRING::STRING(const char* temp)  {
	this->length = strlen(temp);
	this->content = new CHAR[this->length];
	for (int i = 0; i < this->length; i++)
		this->content[i] = CHAR(temp[i]);
}
STRING & STRING::Expand(const STRING& temp) {
	int new_length = this->length + temp.length;
	CHAR* new_string = new CHAR[new_length];
	if(this->content)
	   for (int i = 0; i < this->length; i++)
		   new_string[i] = CHAR(this->content[i]);
	for (int i = this->length; i < new_length; i++)
		new_string[i] = CHAR(temp.content[i-this->length]);
	this->length = new_length;
	delete[] this->content;
	this->content = new_string;
	return *this;
}
STRING & STRING::Expand(const CHAR &temp) {
	int new_length = this->length + 1;
	CHAR* new_string = new CHAR[new_length];
	for (int i = 0; i < this->length; i++)
		new_string[i] = this->content[i];
	new_string[new_length - 1] = CHAR(temp);
	this->length = new_length;
	delete[] this->content;
	this->content = new_string;
	return *this;
}

STRING::~STRING()
{
	delete this->content;
}
