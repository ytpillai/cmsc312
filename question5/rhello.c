/*
 * This is sample code generated by rpcgen.
 * These are only templates and you can use them
 * as a guideline for developing your own functions.
 */

#include "hello.h"
#include <string.h>

void
helloprog_1(char *host, int argc, char *argv[])
{
	CLIENT *clnt;
	char  *args_1 = malloc(sizeof(char) * 255);
	char **result_1;
	
	
	strncpy(args_1, argv[3], 20);
#ifndef	DEBUG
	clnt = clnt_create (host, HELLOPROG, HELLOVERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */
	result_1 = hello_1(&args_1, clnt);
	if (result_1 == (char **) NULL) {
		clnt_perror (clnt, "call failed");
	}
	free(args_1);
	printf("%s\n", *result_1);
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	helloprog_1 (host, argc, argv);
exit (0);
}
