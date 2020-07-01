#include "fcgiapp.h"

#include <stdio.h>

int main()
{
  FCGX_Init();
  const int fd = FCGX_OpenStream(stdin);
  FCGX_Request req;
  FCGX_InitRequest(&req, fd, 0);
  while (!FCGX_Accept_r(&req)) {
    printf("Accepted!\n");
    while (FCGX_GetChar(req.in) > 0)
      printf("Reading\n");
    printf("Finished!\n");
  }
}
