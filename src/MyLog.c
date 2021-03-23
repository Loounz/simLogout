#include "../inc/MyLog.h"


//default log level DEBUG
int LogLevel = DEBUG << 1 -1;

void LOG(int level,char *s,int fd)
{

	time_t t;
	struct tm* ti;
	char temp[1024];
	char levl[10];
	switch(level)
	{
		case 1:
			strcpy(levl,"FATALERR");
			break;
		case 2:
			strcpy(levl,"ERROR");
			break;
		case 4:
			strcpy(levl,"WARNING");
			break;
		case 8:
			strcpy(levl,"INFO");
			break;
		case 16:
			strcpy(levl,"DEBUG");
			break;
	};
	if(level & LogLevel)
	{
		time(&t);
		ti = localtime(&t);
		printf("%s [ %s:%d %s ]%s\n",asctime(ti),__FILE__,__LINE__,levl,s);
                bzero(temp,sizeof(temp));
                sprintf(temp,"%s [%s :Line %d %s ]%s\n",asctime(ti),__FILE__,__LINE__,levl,s);
                write(fd,temp,sizeof(temp));

	}
};

int SetLogLevel(int level)
{
	LogLevel = (level << 1) - 1;
}

