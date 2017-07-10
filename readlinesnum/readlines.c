#include <stdio.h>
int main()
{
    int c;
    FILE *fp;
    int lines=0;
    fp=fopen("2007_val.txt","rb");
    if(fp)
    {
       while((c=fgetc(fp)) != EOF)
        {
          if(c=='\n') 
            {
               lines++;
            }
        }
       printf("%d\n",lines);
       fclose(fp);
    }
    return 0;
}
