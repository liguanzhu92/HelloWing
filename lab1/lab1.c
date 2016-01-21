/* CSE 5460 homework 1*/
 #include<stdio.h>
 #include<string.h>

void FileSize(char *Filename, char *OutputFile)
{
    FILE *fp, *fp1;
    char OutPut[100],append[10];
    fp = fopen(Filename, "r");
    fp1 = fopen(OutputFile, "w+");
    if((fp== NULL)||(fp1 == NULL))
    {
        return;
    }   
    fseek(fp, 0, SEEK_END);
    int iSize = ftell(fp);
    strcpy(OutPut,"Size of file is ");
    sprintf(append,"%d",iSize);
    strcat(OutPut,append);
    strcat(OutPut,"\n");
    //printf("%s", OutPut);
    fputs(OutPut, fp1);
    fclose(fp);
    fclose(fp1);
}

void Search(char *Filename, char *SearchStr, char *OutputFile)
{
    
    int iFindNum = 0;
    FILE *fp, *fp1;
    char str[iLength], OutPut[100], append[10];
    fp = fopen(Filename, "r");
    fp1 = fopen(OutputFile, "a+");
    if((fp== NULL)||(fp1 == NULL))
    {
        return;
    }

    while(fgets(str, 2048, fp) != NULL) 
    {
        if((strstr(str, SearchStr)) != NULL) 
        {
            iFindNum++;
        }
        //fp++；
    }
    strcpy(OutPut,"Number of matches is ");
    sprintf(append,"%d",iFindNum);
    strcat(OutPut,append);
    strcat(OutPut,"\n");
    //printf("%s", OutPut);
    fputs(OutPut, fp1);
    fclose(fp);
    fclose(fp1);
}

 int main(int argc, char *argv[])
 {
 	if(argc != 4)
 	{
 		printf("ILLEGAL INPUTS. Usage:  <inputfile> <string> <output>\n");
 	}
 	else
 	{
 		FileSize(argv[1], argv[3]);
 		Search(argv[1], argv[2], argv[3]);
 	}
 	return 0;
 }