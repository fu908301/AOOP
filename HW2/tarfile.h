#ifndef __TARFILE_H__
#define __TARFILE_H__

#define HEADER_SIZE 512

#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdio>
#include <ctype.h>
#include <iomanip>
#include <cmath>
#include <vector>
#include <stdlib.h>
#include <ctime>

using namespace std;
struct TarHeader {
    char filename[100];
    char filemode[8];
    char userid[8];
    char groupid[8];
    char filesize[12];
    char mtime[12];
    char checksum[8];
    char type;
    char lname[100];
    /* USTAR Section */
    char USTAR_id[6];
    char USTAR_ver[2];
    char username[32];
    char groupname[32];
    char devmajor[8];
    char devminor[8];
    char prefix[155];
    char pad[12];
	int size;
};

class Tarfile{
	public:
		Tarfile();
		void openfile(const char *filename);
		void checkformat();
		void put_in();
		void print_mod(int input);
		void print_result();
		void closefile();
		~Tarfile();
	private:
		fstream file;
		char tempbuffer[512];
		int total_file_size;
		vector <TarHeader> output;
};
#endif
