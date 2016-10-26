#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>

char * get_seed_value() {

}

int randomize() {
  int *values;
  int file = open("/dev/random", O_RDONLY);
  read(file, values, 4);
  close(file);

  srand(time(values));
  int rndnum = rand();
  
  return rndnum;
}


int main() {
  printf("%d\n", randomize());
  
  int rand_nums[10];
  int i = 0;
  //  while (i < 10) {
  //rand_nums[i] = randomize();
  //}
  umask(0000);
  int write_file = open("rand_ints.txt", O_RDWR | O_CREAT, 0644);
  write(write_file, rand_nums, sizeof(int) * 10);
  //close(write_file);
  
  //  int rand_nums2[10];
  //int read_file = open("rand_ints.txt", O_RDWR);
  //read(read_file, rand_nums2, sizeof(int) * 10);
  //close(read_file);
  
  return 0;
}
