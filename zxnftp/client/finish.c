#include "zxnftp.h"
#include <unistd.h>

void finish(void) { 
  close(server); 
  endwin();
} 
