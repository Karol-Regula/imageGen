#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

int main(){
  int fd;
  int i, j;

  fd = open ("image.ppm", O_CREAT | O_TRUNC | O_WRONLY, 0644);
  char temp[100];

  sprintf(temp, "P3 500 500 255");
  write(fd, temp, sizeof(temp));


  for(i = 0; i < 500; i++){
    for(j = 0; j < 500; j++){
      if (i%10){
        sprintf(temp, "100 100 255\n");
      }else{
        sprintf(temp, "255 0 10\n");
      }
      write(fd, temp, sizeof(temp));
    }
  }
  return 1;
}
