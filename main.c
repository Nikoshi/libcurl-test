#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curl/curl.h>

int
main(int argc, char **argv)
{
	int port1delay = 10000;
	int port2delay = 12000;
	int port3delay = 14000;
	int port4delay = 16000;

    int opt;
	while ((opt = getopt(argc, argv, "1:2:3:4:g:")) != -1) {
        switch (opt) {
        case '1': sscanf("%d", optarg, &port1delay); break;
        case '2': sscanf("%d", optarg, &port2delay); break;
        case '3': sscanf("%d", optarg, &port3delay); break;
		case '4': sscanf("%d", optarg, &port4delay); break;
		case 'g': sscanf("%d", optarg, &port1delay); port2delay = port3delay = port4delay = port1delay; break;
        default:
            fprintf(stderr, "Usage: %s ([-1] <delay> [-2] <delay> [-3] <delay> [-4] <delay>) | [-g] <delay>\n", argv[0]);
            exit(EXIT_FAILURE);
        }
    }

	CURL *curl;
	CURLcode res;
	curl = curl_easy_init();

	if(curl) {
		curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "POST");
		curl_easy_setopt(curl, CURLOPT_URL, "http://netio-4c.netio-products.com:8080/netio.json");
		curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

		struct curl_slist *headers = NULL;
		headers = curl_slist_append(headers, "Content-Type: application/json");
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		
		char data[1024];
		sprintf(data, "{\"Outputs\": [{\"ID\": 1,\"Action\": 2,\"Delay\": %d},{\"ID\": 2,\"Action\": 2,\"Delay\": %d},{\"ID\": 3,\"Action\": 2,\"Delay\": %d},{\"ID\": 4,\"Action\": 2,\"Delay\": %d}]}", port1delay, port2delay, port3delay, port4delay);
		curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data);

		res = curl_easy_perform(curl);
		curl_easy_cleanup(curl);
	}
}
