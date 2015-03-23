#include <map>
#include <string>

class Json
{
private:
	std::string jsonString;
public:
	Json(const std::string &_json = "");
	std::string getJsonString() const;
	void setJsonString(const std::string &_json);
	std::map<std::string, std::string> jsonToMap(const std::string &js) const;
};