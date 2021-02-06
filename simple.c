#include <stdio.h>
#include <unistd.h>
#include <curl/curl.h>

int
main(void)
{
	FILE *null_file = fopen("/dev/null", "w");
	CURL *curl;
	CURLcode res;
	curl = curl_easy_init();

	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
		curl_easy_setopt(curl, CURLOPT_URL, "http://netio-4c.netio-products.com:8080/netio.json");
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, null_file);

		struct curl_slist *headers = NULL;
		headers = curl_slist_append(headers, "Content-Type: application/json");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		
		const char *data = "{\"Outputs\": [{\"ID\": 1,\"Action\": 2,\"Delay\": 10000},{\"ID\": 2,\"Action\": 2,\"Delay\": 12000},{\"ID\": 3,\"Action\": 2,\"Delay\": 14000},{\"ID\": 4,\"Action\": 2,\"Delay\": 16000}]}";
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
	if (null_file)
		fclose(null_file);
}
