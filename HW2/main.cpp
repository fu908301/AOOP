#include "tarfile.h"

int main(int argc,const char *argv[])
{
	Tarfile test;
	test.openfile(argv[1]);
	test.checkformat();	
	test.put_in();
	test.print_result();
	test.closefile();
	return 0;
}
