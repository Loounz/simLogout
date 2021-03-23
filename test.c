#include "./inc/MyLog.h"

void f(int fd)
{
	LOG(INFO,"Enter f()..",fd);
	int counter = 0;
	counter++;
	LOG(DEBUG,"Exit f()..",fd);
}

int main()
{
	int fd;
	int counter = 0;
	int s = 0;

	counter = SetLogLevel(INFO);
	
	fd = open("./mylog.log",O_RDONLY | O_WRONLY | O_APPEND | O_CREAT);
	if(fd < 0)
	{
		chmod("./mylog.lo",S_IRUSR | S_IWUSR |S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
		fd = open("./mylog.log",O_RDONLY | O_WRONLY | O_APPEND | O_CREAT);
	}
	LOG(DEBUG,"Enter main()..",fd);
	LOG(INFO,"Enter main()..22222",fd);

	for(;;)
	{
		f(fd);
		sleep(1);
		counter++;
		if(counter > 50)
			break;
	}
	LOG(INFO,"Exit main()..",fd);
	close(fd);
	return 0;
}

