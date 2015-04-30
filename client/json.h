#include <map>
#include <string>
#include "fsmjson/fsmjson.h"
#include <boost/any.hpp>
#include <list>

class Json
{
private:
	std::string jsonString;
	FSMJson *fsmJson;
public:
	Json(const std::string &_json = "");
	std::string getJsonString() const;
	void setJsonString(const std::string &_json);
	std::string getValueByKey(const std::string &key);
	std::list<boost::any> jsonToMap(const std::string &js) const;
};