//
// Created by ssi on 28.04.15.
//

#include "Request.h"
#include <string.h>
#include "../fsmjson/renderexception.h"
#include "../json.h"

namespace vkmes
{
	Request::Request(const char *_clientId, const char *_secretKey, const char *_code)
	{
		if (_secretKey && _code && _clientId)
		{
			secretKey = new char[strlen(_secretKey)];
			strcpy(secretKey, _secretKey);
			code = new char[strlen(_code)];
			strcpy(code, _code);
			clientId = new char[strlen(_clientId)];
			strcpy(clientId, _clientId);
		}
		else
		{
			LOG_TRACE("Secret Key or Code or ClientId is NULL")
		}
	}

	Request::Request(const char *_clientId, const char *_secretKey, const char *_code, const char *_token) : Request(_clientId, _secretKey, _code)
	{
		if (_token)
		{
			token = new char[strlen(_token)];
			stpcpy(token, _token);
		}
		else
		{
			LOG_TRACE("Token is NULL")
		}
	}

	Request::~Request()
	{
		if (clientId)
			delete[] clientId;
		if (secretKey)
			delete[] secretKey;
		if (code)
			delete[] code;
		if (token)
			delete[] token;
	}

	char *Request::getToken() const
	{
		CURL *curl;
		CURLcode result;
		curl = curl_easy_init();
		char errorBuffer[CURL_ERROR_SIZE];
		std::string buffer;

		if (curl)
		{
			char *url = new char[strlen("https://oauth.vk.com/access_token/")];
			strcpy(url, "https://oauth.vk.com/access_token/");
			url = addGetParam(url, "client_id", clientId);
			url = addGetParam(url, "secret_key", secretKey);
			url = addGetParam(url, "code", code);
			url = addGetParam(url, "redirect_uri", "http://api.vk.com/blank.html");
//			std::cout << url << std::endl;
			curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
			curl_easy_setopt(curl, CURLOPT_URL, url);
			curl_easy_setopt(curl, CURLOPT_HEADER, 0);
			curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeResp);
			curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
			result = curl_easy_perform(curl);
			if (result == CURLE_OK)
			{
				std::cout << buffer << "\n";
				Json json(buffer);
				std::string tokenString = json.getValueByKey("token");
				if(tokenString != "")
				{
					char *tokenCharptr = new char[tokenString.length() + 1];
					strcpy(tokenCharptr, tokenString.c_str());
					curl_easy_cleanup(curl);
					delete[] url;
					return tokenCharptr;
				}
			}
			else
			{
				std::cout << "Ошибка! " << errorBuffer << std::endl;
				delete[] url;
			}
		}
		curl_easy_cleanup(curl);
		return nullptr;
	}

	char *Request::addGetParam(char *link, const char *pKey, const char *val) const
	{
		char *keyValString = new char[strlen(pKey) + 1 + strlen(val)];
		strcpy(keyValString, pKey);
		strcat(keyValString, "=");
		strcat(keyValString, val);
		size_t l = strlen(link) + 2 + strlen(keyValString);
		char *temp = new char[l];
		strcpy(temp, link);
		if (strchr(link, '?'))
		{
			strcat(temp, "&");
		}
		else
		{
			strcat(temp, "?");
		}
		strcat(temp, keyValString);
		delete[] keyValString;
		delete[] link;
		link = new char[l];
		strcpy(link, temp);
		delete[] temp;
		return link;
	}

	int Request::writeResp(char *data, size_t size, size_t nmemb, std::string *buffer)
	{
		//переменная - результат, по умолчанию нулевая
		int result = 0;
		//проверяем буфер
		if (buffer != NULL)
		{
			//добавляем к буферу строки из data, в количестве nmemb
			buffer->append(data, size * nmemb);
			//вычисляем объем принятых данных
			result = size * nmemb;
		}
		//вовзращаем результат
		return result;
	}

	bool Request::auth() const
	{
		getToken();
		return false;
	}
}
