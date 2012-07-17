/* This file is part of the finger protocol library.
 *
 * The finger protocol library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * The finger protocol library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with the finger protocol library.  If not, see <http://www.gnu.org/licenses/>.
 */


/**
 * @file fprobe.c
 * @author Will Dignazio 
 * fprobe is a small testing utility for probing the fingerd on the
 * localhost machine. It's primary function is to test the finger 
 * protocol library as it is being built. It can be used to make 
 * simple finger like commands as well. Have fun. 
 */

#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

/** 
 * Designed based on the article at 
 * http://www.linuxhowtos.org/C_C++/socket.htm
 */
int main(int argc, char *argv[]) { 
    if(argc < 2) { 
        printf("Use: fprobe <query>\n"); 
        exit(1); 
    }
    
    int sockfd, newsockfd, clilen, n;  
    int portno = 79; // finger runs on port 79
    char *host = "localhost"; // this is a localhost test app
    char buffer[256]; 
    struct sockaddr_in serv_addr, cli_addr;
    
    /* 
     * The specs for finger specify that you need to 
     * make a TCP socket connection to the RUIP 
     * (finger protocol) server. 
     */
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 
    if(sockfd < 0) { 
        printf("Failed to open socket"); 
        exit(1); 
    }
  
    /* Zero out the serv_addr buffer struct */ 
    bzero((char *)&serv_addr, sizeof(serv_addr)); 
    /* Setup the socket buffer */ 
    serv_addr.sin_family = AF_INET; //Should always be AF_INET
    /* port converted to a network byte order. */ 
    serv_addr.sin_port = htons(portno); 

    /* 
     * The argument should be the query from the command line, as
     * the query would be if you were typing it in from a finger 
     * command. 
     */
    //TODO: this..

    return 0; 
}
