#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>


int main(int argc, char *argv[])
{
	int i = argc;
	printf("ARGC : %d\n", argc);
	
	if ( argc < 3 ) {
		printf("Usage : %s <filename1> <filename2>\n", argv[0]);
		printf("or\nUsage : %s <filename1> <filename2> ... <directory name>\n", argv[0]);
		return 0;
	}
	else{
		
		for(int j=1;j<=i-2;j++)
		{
			FILE *fd, *dest;
			char cpyFileName[50];
			sprintf(cpyFileName,"%s/testFileName%d.txt",argv[i-1],j);

			//ready files
			fd = fopen(argv[j], "r");
			dest = fopen(cpyFileName, "w");
			//length
			fseek(fd,0,SEEK_END);
			int len;
			len = ftell(fd);
			fseek(fd,0,SEEK_SET);
			int val;
			char buf[30];
			val = fread(buf, 1, len, fd);
			fwrite(buf, 1, val, dest);

			printf("Length : %d\n", len);
			printf("%s\n", buf);
			
			fclose(dest);
			fclose(fd);
		}
		return 0;
	}
}