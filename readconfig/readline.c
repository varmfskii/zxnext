#include <arch/zxn.h>
#include <arch/zxn/esxdos.h>
#include "myfile.h"

int readline(char *line, int sz, file *fp) {
  int i;
  unsigned char c;

  for(i=0; i<sz-1; i++) {
    if (fp->ix==fp->valid) {
      fp->ix=0;
      if(!(fp->valid=esx_f_read(fp->fp, fp->buf, BSIZE))) {
	line[i]='\0';
	return 0;
      }
    }
    c=fp->buf[fp->ix++];
    if (c=='\n') break;
    line[i]=c;
  }
  line[i++]='\0';
  return i;
}
