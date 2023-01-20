#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <assert.h>
#include <netdb.h> /* getprotobyname */
#include <netinet/in.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <unistd.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"
#define _XOPEN_SOURCE 700

int main(){

    int choiceInput;

    system("clear || cls");
    printf("\n         罪 深 い Kon'nichiwa\n" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "┌───────────────────────────────────┐" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "│            "ANSI_COLOR_RESET"PurpleVision"ANSI_COLOR_MAGENTA"           │" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "└───────────────────────────────────┘" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "┌───────────────────────────────────┐" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "│                                   │" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"1. OSINT"ANSI_COLOR_MAGENTA"                     │" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"2. DB DUMPER"ANSI_COLOR_MAGENTA"                 │    "ANSI_COLOR_RESET"v0.0.1\n");
    printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"3. Password Attack"ANSI_COLOR_MAGENTA"           │    "ANSI_COLOR_RESET"0x2CB#8856\n");
    printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"4. CreditCard Infos"ANSI_COLOR_MAGENTA"          │    "ANSI_COLOR_RESET"https://github.com/0x2CBB/PurpleVision.git\n");
    printf(ANSI_COLOR_MAGENTA "│                                   │" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "└───────────────────────────────────┘" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "┌───────────────────────────────────┐" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"e. Exit"ANSI_COLOR_MAGENTA"                      │" ANSI_COLOR_RESET "\n");
    printf(ANSI_COLOR_MAGENTA "└───────────────────────────────────┘" ANSI_COLOR_RESET "\n\n\t");
    printf("Option >>> ");
    scanf("%d", &choiceInput);

    if(choiceInput == 1){

        int choiceInputOsint;

        system("clear || cls");
        printf("\n             PurpleVision\n" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "┌───────────────────────────────────┐" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│            "ANSI_COLOR_RESET"   OSINT"ANSI_COLOR_MAGENTA"               │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "└───────────────────────────────────┘" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "┌───────────────────────────────────┐" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│                                   │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"1. IP LOCATE"ANSI_COLOR_MAGENTA"                 │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"2. SSID LOCATE  "ANSI_COLOR_MAGENTA"             │    "ANSI_COLOR_RESET"v0.0.1\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"3. LeakCheck          "ANSI_COLOR_MAGENTA"       │    "ANSI_COLOR_RESET"0x2CB#8856\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"4. Email Infos         "ANSI_COLOR_MAGENTA"      │    "ANSI_COLOR_RESET"https://github.com/0x2CBB/PurpleVision.git\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"5. PseudoSearch"ANSI_COLOR_MAGENTA"              │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│                                   │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "└───────────────────────────────────┘" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "┌───────────────────────────────────┐" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"e. Exit"ANSI_COLOR_MAGENTA"                      │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "└───────────────────────────────────┘" ANSI_COLOR_RESET "\n\n\t");
        printf("Option >>> ");
        scanf("%d", &choiceInputOsint);

        if(choiceInputOsint == 5){

            char username[30];

            printf("\tPseudo >>> ");
            scanf("%s", &username);

            char *argv = {""};
            char buffer[BUFSIZ];
            enum CONSTEXPR { MAX_REQUEST_LEN = 1024};
            char request[MAX_REQUEST_LEN];
            char request_template[] = "GET /?https://github.com/%s HTTP/1.1\r\nHost: %s\r\n\r\n";
            struct protoent *protoent;
            char *hostname = "https://late-tooth-b0bf.ocemail.workers.dev";
            in_addr_t in_addr;
            int request_len;
            int socket_file_descriptor;
            ssize_t nbytes_total, nbytes_last;
            struct hostent *hostent;
            struct sockaddr_in sockaddr_in;
            unsigned short server_port = 80;

            hostname = argv[1];

            request_len = snprintf(request, MAX_REQUEST_LEN, request_template, username, hostname);
            if (request_len >= MAX_REQUEST_LEN) {
                fprintf(stderr, "request length large: %d\n", request_len);
                exit(EXIT_FAILURE);
            }

            /* Build the socket. */
            protoent = getprotobyname("tcp");
            if (protoent == NULL) {
                perror("getprotobyname");
                exit(EXIT_FAILURE);
            }
            socket_file_descriptor = socket(AF_INET, SOCK_STREAM, protoent->p_proto);
            if (socket_file_descriptor == -1) {
                perror("socket");
                exit(EXIT_FAILURE);
            }

            /* Build the address. */
            hostent = gethostbyname(hostname);
            if (hostent == NULL) {
                fprintf(stderr, "error: gethostbyname(\"%s\")\n", hostname);
                exit(EXIT_FAILURE);
            }
            in_addr = inet_addr(inet_ntoa(*(struct in_addr*)*(hostent->h_addr_list)));
            if (in_addr == (in_addr_t)-1) {
                fprintf(stderr, "error: inet_addr(\"%s\")\n", *(hostent->h_addr_list));
                exit(EXIT_FAILURE);
            }
            sockaddr_in.sin_addr.s_addr = in_addr;
            sockaddr_in.sin_family = AF_INET;
            sockaddr_in.sin_port = htons(server_port);

            /* Actually connect. */
            if (connect(socket_file_descriptor, (struct sockaddr*)&sockaddr_in, sizeof(sockaddr_in)) == -1) {
                perror("connect");
                exit(EXIT_FAILURE);
            }

            /* Send HTTP request. */
            nbytes_total = 0;
            while (nbytes_total < request_len) {
                nbytes_last = write(socket_file_descriptor, request + nbytes_total, request_len - nbytes_total);
                if (nbytes_last == -1) {
                    perror("write");
                    exit(EXIT_FAILURE);
                }
                nbytes_total += nbytes_last;
            }

            /* Read the response. */
            fprintf(stderr, "debug: before first read\n");
            while ((nbytes_total = read(socket_file_descriptor, buffer, BUFSIZ)) > 0) {
                fprintf(stderr, "debug: after a read\n");
                write(STDOUT_FILENO, buffer, nbytes_total);
            }
            fprintf(stderr, "debug: after last read\n");
            if (nbytes_total == -1) {
                perror("read");
                exit(EXIT_FAILURE);
            }

            close(socket_file_descriptor);
            exit(EXIT_SUCCESS);

            /*
            printf("\tPseudo >>> ");
            scanf("%s", &username);
            char pszRequest[100]= {0};
            char pszResourcePath[]="?https://github.com/";
            char pszHostAddress[]="https://late-tooth-b0bf.ocemail.workers.dev";
            strncat(pszResourcePath, username, 30);
            //printf("%s", pszResourcePathh);
            sprintf(pszRequest, "GET /%s HTTP/1.1\r\nHost: %s\r\nContent-Type: text/plain\r\n\r\n", pszResourcePath, pszHostAddress);
            printf("\n\tRequête GET crée :\n\n\n");
            printf("%s", pszRequest);
            return 0;*/

        }

        }
        

    
    else if(choiceInput == 2){

       int choiceInputDB;

        system("clear || cls");
        printf("\n             PurpleVision\n" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "┌───────────────────────────────────┐" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│            "ANSI_COLOR_RESET" DB DUMPER"ANSI_COLOR_MAGENTA"             │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "└───────────────────────────────────┘" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "┌───────────────────────────────────┐" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│                                   │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"1. DumpAll  "ANSI_COLOR_MAGENTA"                 │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"2. DumpTable    "ANSI_COLOR_MAGENTA"             │    "ANSI_COLOR_RESET"v0.0.1\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"3. ShowTables         "ANSI_COLOR_MAGENTA"       │    "ANSI_COLOR_RESET"0x2CB#8856\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"4. CustomRequest       "ANSI_COLOR_MAGENTA"      │    "ANSI_COLOR_RESET"https://github.com/0x2CBB/PurpleVision.git\n");
        printf(ANSI_COLOR_MAGENTA "│                                   │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "└───────────────────────────────────┘" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "┌───────────────────────────────────┐" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"e. Exit"ANSI_COLOR_MAGENTA"                      │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "└───────────────────────────────────┘" ANSI_COLOR_RESET "\n\n\t");
        printf("Option >>> ");
        scanf("%d", &choiceInputDB); 

    }
    else if(choiceInput == 3){

        int choiceInputPasswd;

        system("clear || cls");
        printf("\n             PurpleVision\n" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "┌───────────────────────────────────┐" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│            "ANSI_COLOR_RESET"Password Attack"ANSI_COLOR_MAGENTA"               │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "└───────────────────────────────────┘" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "┌───────────────────────────────────┐" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│                                   │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"1. HashID   "ANSI_COLOR_MAGENTA"                 │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"2. BruteForce   "ANSI_COLOR_MAGENTA"             │    "ANSI_COLOR_RESET"v0.0.1\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"3. Dictionnary        "ANSI_COLOR_MAGENTA"       │    "ANSI_COLOR_RESET"0x2CB#8856\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"4. Search         "ANSI_COLOR_MAGENTA"      │    "ANSI_COLOR_RESET"https://github.com/0x2CBB/PurpleVision.git\n");
        printf(ANSI_COLOR_MAGENTA "│                                   │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "└───────────────────────────────────┘" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "┌───────────────────────────────────┐" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"e. Exit"ANSI_COLOR_MAGENTA"                      │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "└───────────────────────────────────┘" ANSI_COLOR_RESET "\n\n\t");
        printf("Option >>> ");
        scanf("%d", &choiceInputPasswd);

        if(choiceInputPasswd == 4){

            return 0;

        }

    }
    else if(choiceInput == 4){

        int choiceInputOsint;

        system("clear || cls");
        printf("\n             PurpleVision\n" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "┌───────────────────────────────────┐" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│          "ANSI_COLOR_RESET"Credit Card Infos"ANSI_COLOR_MAGENTA"        │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "└───────────────────────────────────┘" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "┌───────────────────────────────────┐" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│                                   │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"1. Get Infos   "ANSI_COLOR_MAGENTA"              │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│                                   │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "└───────────────────────────────────┘" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "┌───────────────────────────────────┐" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "│      "ANSI_COLOR_RESET"e. Exit"ANSI_COLOR_MAGENTA"                      │" ANSI_COLOR_RESET "\n");
        printf(ANSI_COLOR_MAGENTA "└───────────────────────────────────┘" ANSI_COLOR_RESET "\n\n\t");
        printf("Option >>> ");
        scanf("%d", &choiceInputOsint);

    }
}
