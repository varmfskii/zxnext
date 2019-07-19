#include <curses.h>
#include "zxnftp.h"

void cmd_mkdir(char **params) {
  int i;
  
  wmove(status, 0, 0);
  wdeleteln(status);
  waddstr(status, "mkdir(");
  for(i=1; params[i]; i++) {
    waddch(status, '(');
    waddstr(status, params[i]);
    waddch(status, ')');
  }
  waddch(status, ')');
  if (!params[1] || params[2]) {
    waddstr(win, "Error: Incorrect number of arguments. mkdir <dir>\n");
    return;
  }
  call_simple("MD", params[1], FALSE);
  return;
}
