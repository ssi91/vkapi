#include "json.h"
#include "fsmjson/renderexception.h"

Json::Json(std::string const &_json)
{
	fsmJson = new FSMJson("{\"@:#\"}[],.\"\"");
	if (fsmJson->isValidJson(_json.c_str()))
		jsonString = _json;
	else
	{
		throw LOG_TRACE("Json-string invalid")
	}
}

std::string Json::getJsonString() const
{
	return jsonString;
}

void Json::setJsonString(const std::string &_json)
{
	if (fsmJson->isValidJson(_json.c_str()))
		jsonString = _json;
	else
	{
		throw LOG_TRACE("Json-string invalid")
	}
}

std::list<boost::any> Json::jsonToMap(const std::string &js) const
{
	std::list<boost::any> li;
	return li;
}

std::string Json::getValueByKey(const std::string &key)
{
	void *qq;
	if (qq = fsmJson->setInMap(jsonString, key.c_str()))
	{
		std::string val;
		std::string *ee = static_cast<std::string *>(qq);
		val = ee[0];
		delete ee;
		return val;
	}
	return "";
}