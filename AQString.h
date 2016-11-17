#ifndef AQSTRING_H
#define AQSTRING_H
#include <qstring.h>

class AQString :public QString{
public:
	AQString(const std::string& str) :QString(str.c_str()){

	}
	AQString(const char* str) :QString(str){

	}
	AQString(const QString& str) :QString(str){

	}
public:
	AQString& operator+(const AQString& s){
		this->append(s);
		return *this;
	}
	AQString& operator+(const double value){
		this->append(QString::number(value));
		return *this;
	}
	AQString& operator+(const int value){
		this->append(QString::number(value));
		return *this;
	}
};

#endif