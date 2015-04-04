#include "config.h"

Config* Config::_conf = nullptr;

Config* Config::getConfig() {
	if (_conf == NULL) {			
		_conf = new	Config();
	}
	return _conf;
}

void Config::setConfig(Config* conf) {
	if (conf == NULL) {
		// user try to set null config =)
	}
	// TODO: do copy of conf
	_conf = conf;
}

Config::Config() {
	test = "foo";
}