/*
 * =====================================================================================
 *       Filename: udp_sender.c
 *
 *    Description: This file is an client to send any messages through the server you made.
 * 
 *        Created:  2024.06.14
 *       Compiler:  gcc
 *
 * =====================================================================================
 */



#include "network_utils.h"

int main(int argc, char **argv){
    printf("Dest=[%s, %d] msg = %s\n", argv[1], atoi(argv[2]), argv[3]);
    send_udp_msg(argv[1], atoi(argv[2]), argv[3], strlen(argv[3]));    
}