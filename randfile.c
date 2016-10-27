#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <sys/stat.h>


int randomize() {
  int *values;
  int file = open("/dev/random", O_RDONLY);
  read(file, &values, 4);
  srand(values);
  close(file);
  int rndnum = rand();
  
  return rndnum;
}


int main() {

  //populating array of random nums
  int rand_nums[10];
  int i = 0;
  printf("Generating random numbers:\n");
  while (i < 10) {
    rand_nums[i] = randomize();
    printf("\trandom %d: %d\n", i, rand_nums[i]);
    i++;
  }

  //writing array to file
  printf("Writing numbers to file...\n");
  umask(0000);
  int write_file = open("rand_ints", O_WRONLY | O_CREAT, 0644);
  write(write_file, rand_nums, 40);
  close(write_file);

  //reading array from file
  printf("Reading numbers from file...\n");
  int rand_nums2[10];
  int read_file = open("rand_ints", O_RDONLY);
  read(read_file, rand_nums2, 40);
  close(read_file);

  //checking numbers
  printf("Verification that written values were the same:\n");
  for( i=0; i<10; i++ ) {
    printf("\trandom %d: %d\n", i, rand_nums2[i]);
  }
  
  return 0;
}
