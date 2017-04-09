#include "tarfile.h"
Tarfile::Tarfile(){}

void Tarfile::openfile(const char *filename)
{
	file.open(filename,ios::in | ios::binary);
	if(!file.good())
	{
		cout << "File open error!" << endl;
		exit(0);
	}
	file.seekg(0,ios::end);
	total_file_size = file.tellg();
}

Tarfile::~Tarfile(){}

void Tarfile::checkformat()
{
	char ustar_check[6];
	file.seekg(257,ios::beg);
	file.read(ustar_check,5);
	ustar_check[5] = '\0';
	file.seekg(0,ios::beg);
	if(strcmp(ustar_check,"ustar") != 0)
	{
		cout << "File is not tarfile."<< endl;
		file.close();
		exit(0);
	}
}

void Tarfile::put_in()
{
	TarHeader mytar;
	int left_size;
	file.seekg(0,ios::beg);
	while(1)
	{
		left_size = 0;
		file.read(tempbuffer,HEADER_SIZE);
		for(int i = 0; i< 100; i++)
			mytar.filename[i] = tempbuffer[i];
		for(int i = 0; i < 108; i++)
			mytar.filemode[i-100] = tempbuffer[i]; 
		for(int i = 124; i < 136; i++)
			mytar.filesize[i-124] = tempbuffer[i];
		for(int i = 265; i < 297; i++)
			mytar.username[i-265] = tempbuffer[i];
		for(int i = 297; i < 329; i++)
			mytar.groupname[i-297] = tempbuffer[i];
		mytar.type = tempbuffer[156];
		for(int i = 0; i < 11; i++)
			left_size += (mytar.filesize[i] - '0') * pow(8,10-i); 
		mytar.size = left_size;
		if(strlen(mytar.filename) == 0)
			left_size = 512;
		else if(strlen(mytar.filename) > 0)
			output.push_back(mytar);
		if(left_size % 512 != 0)
			left_size = (left_size / 512) * 512 + 512;
		file.seekg(left_size,ios::cur);
		total_file_size -= left_size;
		if(total_file_size <= 0)
			break;
	}
}
void Tarfile::print_mod(int input)
{
	switch(input){
		case 0:
			cout << "---";
			break;
		case 1:
			cout <<	"--x";
			break;
		case 2:
			cout << "-w-";
			break;
		case 3:
			cout << "-wx";
			break;
		case 4:
			cout << "r--";
			break;
		case 5:
			cout << "r-x";
			break;
		case 6:
			cout << "rw-";
			break;
		case 7:
			cout << "rwx";
			break;
		default:
			cout << "Mode error!" << endl;
			break;
	}	
}
void Tarfile::print_result()
{
	int mode_num;
	cout<<"Total "<<output.size()<<" files"<<endl;
	for(int i = 0; i < output.size(); i++)
	{
		if(output[i].type == '5')
			cout << "d";
		else
			cout << "-";
		for(int j = 4; j < 7; j++)
		{
			mode_num = output[i].filemode[j] - '0';
			print_mod(mode_num);
		}
		cout << " " << left << setw(13) << output[i].username;
		cout << left <<setw(13) << output[i].groupname;
		cout << setw(6) << output[i].size << " " ;
		cout << output[i].filename << endl;
	}
}
void Tarfile::closefile()
{
	file.close();
}
