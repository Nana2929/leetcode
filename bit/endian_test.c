

#include <stdio.h>
typedef union {
  unsigned long l;
  unsigned char c[4];
} EndianTest;
// A union is an object similar to a structure except that all of its members start at the same location in memory.
// A union can only represent one of its members at a time, and the size of a union is the size of its largest member.

typedef union {
  unsigned int l;
  unsigned char c[4];
} EndianTest2;

int main() {
  EndianTest et;
  et.l = 0x12345678;
  printf("本系統位元組順序為：");
  if (et.c[0] == 0x78 && et.c[1] == 0x56 && et.c[2] == 0x34 && et.c[3] == 0x12) {
    printf("Little Endian\n");
    // my ikmpc is little-endian; The endianess is based on hardware only. OS cannot overwrite it since it is the order in which data is written/ read from/to hardware. 
  } else if (et.c[0] == 0x12 && et.c[1] == 0x34 && et.c[2] == 0x56 && et.c[3] == 0x78) {
    printf("Big Endian\n");
  } else {
    printf("Unknown Endian\n");
  }
  printf("0x%lX 在記憶體中的儲存順序：n", et.l);
  for (int i = 0; i < 4; i++) {
    printf("%p : 0x%02Xn\n", &et.c[i], et.c[i]);
  }
  // check union size,
  // long is 8 bytes; char[4] is 4 bytes
  // take the larger one: 8 bytes

  printf("sizeof(EndianTest) = %lu\n", sizeof(EndianTest)); // sizeof(EndianTest) = 8

  EndianTest2 et2;
  et2.l = 0x12345678;
  // print size
  printf("sizeof(EndianTest2) = %lu\n", sizeof(EndianTest2)); // sizeof(EndianTest2) = 4
  return 0;


}