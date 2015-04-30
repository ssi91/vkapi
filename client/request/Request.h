//
// Created by ssi on 28.04.15.
//

#ifndef CLIENT_REQUEST_H
#define CLIENT_REQUEST_H

#include <curl/curl.h>
#include <string>

namespace vkmes
{
	class Request
	{
	private:
		char *secretKey;
		char *token;
		char *code;
		char *clientId;

		char *addGetParam(char *link, const char *pKey, const char *val) const;
		char *getToken() const;

		static int writeResp(char *data, size_t size, size_t nmemb, std::string *buffer);
	public:
		Request(const char *_clientId, const char *_secretKey, const char *_code, const char *_token);
		Request(const char *_clientId, const char *_secretKey, const char *_code);
		~Request();
		bool auth() const;
	};

}
#endif //CLIENT_REQUEST_H
