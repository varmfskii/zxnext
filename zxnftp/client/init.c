#include "zxnftp.h"
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <curses.h>
#include <locale.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void init(void) {
  struct sockaddr_in address;
  char line[BLKSZ];
  int i, c, colon;
  FILE *in;

  if (!(in=fopen("zxnftp.cfg", "r"))) {
    fprintf(stderr, "Unable to open zxnftp.cfg\n");
    exit(1);
  }
  for(i=colon=0; i<BLKSZ && (c=getc(in))!=EOF && c!='\n'; i++) {
    line[i]=c;
    if (c==':') colon=i;
  }
  fclose(in);
  line[i]='\0';
  line[colon]='\0';
  addr=strdup(line);
  port=atoi(line+colon+1);
#ifndef NONET
  // init socket
  server=socket(AF_INET, SOCK_STREAM, 0); 
  if (server == -1) error("socket creation failed", 1); 
  address.sin_family = AF_INET; 
  address.sin_addr.s_addr = inet_addr(addr); 
  address.sin_port = htons(port); 
  if (connect(server, (struct sockaddr *)&address, sizeof(address)) != 0)
    error("connection with the server failed", 2);
  call_id();
#else
  id=strdup("No Network Test");
#endif
  //init windows
  setlocale(LC_ALL, "");
  initscr();
  getmaxyx(stdscr, h, w);
  
#ifdef DEBUG
  win=newwin(h-1, w/2, 1, 0);
  debug=newwin(h-1, w-w/2, 1, w/2);
  scrollok(debug, TRUE);
#else
  win=newwin(h-1, w, 1, 0);
#endif
  scrollok(win, TRUE);
  status=newwin(1, w, 0, 0);
  noecho();
  raw();
  nl();
  wclear(status);
  //wrefresh(status);
#ifdef DEBUG
  wclear(debug);
  //wrefresh(debug);
#endif
  wclear(win);
  waddstr(win, "ZXFTP client\n");
  waddstr(win, "connected to server: ");
  waddstr(win, line);
  waddch(win, ':');
  waddstr(win, line+colon+1);
  waddch(win, '\n');
  waddstr(win, "server id: ");
  waddstr(win, id);
  waddch(win, '\n');
  //wrefresh(win);
} 
