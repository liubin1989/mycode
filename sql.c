#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h> 
 
#include <sybfront.h> 
#include <sybdb.h> 
 
 
int main(void)
{
 	dbinit();
	LOGINREC *loginrec = dblogin();
	DBSETLUSER(loginrec,"sa");       
	DBSETLPWD(loginrec,"123456");
	DBSETLCHARSET(loginrec,"UTF-8");
	DBPROCESS *dbprocess = dbopen(loginrec, "192.168.5.157:1433");
	if(dbprocess == FAIL)
	{
		printf("Conect to MS SQL SERVER fail, exit!\n");
		return -1; 
	}
	printf("Connect to MS SQL SERVER success!\n");
       
	if(dbuse(dbprocess, "test") == FAIL)
		printf("Open database failed!\n");
	else
		printf("Open database success!\n");
       
	dbcmd(dbprocess, "select No,Name from test");
	if(dbsqlexec(dbprocess) == FAIL)
	{
		printf("Query table 'StuInfo' error.\n");
		return -1; 
	}
     
	DBINT result_code;
	char szStuID[20]={};
	char szName[80]={};
	char szAge[10]={};
	int rows = 0;
	while ((result_code = dbresults(dbprocess)) != NO_MORE_RESULTS){
		if (result_code == SUCCEED){
			dbbind(dbprocess, 1, CHARBIND, (DBINT)0, (BYTE*)szStuID);
			dbbind(dbprocess, 2, CHARBIND, (DBCHAR)0, (BYTE*)szName);
			printf("StuID\tName\tAge\n", szStuID);
			while (dbnextrow(dbprocess) != NO_MORE_ROWS){                        
				printf("%s\t", szStuID);
				printf("%s\t", szName);
			}
		}
	}       

	dbclose(dbprocess);

	return 0;
} 
