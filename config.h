#ifndef CONFIG_H
#define CONFIG_H

#include <QSize>
#include <QString>

class Config
{
public:
	static Config* getConfig();
	static void setConfig(Config* conf);

	QSize fieldSize;
	QString test;


private:
	Config();	

	static Config* _conf;
};

#endif