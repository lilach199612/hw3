#include <stdio.h>
#define LINE 256
#define WORD 30

int Getline(char s[])
{
    int count=0;
    char c;
    int true=1;
    while(true) //check if it is the end of the line
    {
        if(scanf("%c",&c)!=EOF)//chech if it is the end of the text
        {
            s[count]=c;
            count++;
            if(c=='\n')
               true=0;
        } 
        else
            true=0; 
    }
    return count;
}

int getword(char w[])
{
    int count=0;
    char c;
    int true=1;
    while(true)//check if it is the end of the word
    {
        if(scanf("%c",&c)!=EOF)//check if it is the end of the text
        {
            if(c=='\n'||c=='\t'||c==' ')
            {
                true=0;
                w[count]='\0';
                if(c=='\n')//check if it is the end of the line,if its the end change the letter before
                {
                    w[count-1]='\0';
                }
            }
            else
                w[count]=c;
            count++;
        }
        else
        {
            true=0;
            w[count]='\0';
        }
          
    }
    return count;
}
int substring( char * str1, char * str2)
{
    while (*str1 != '\0')//check if it is the end of the string
     {
        char * copyStr1=str1;
        char * copyStr2=str2;
        int true=1;
        while (*copyStr2 != '\0'&&true)//check if from this letter str2 is contains in str1
        {
            if(*copyStr2 != *copyStr1)
                true=0;
            copyStr1++;
            copyStr2++;
        }
        if(true)
            return 1;
        str1++;
    }
    return 0;
}
int similar (char *s, char *t, int n)
{
    while(*t!='\0')
    {
        while((*s!=*t)&&(*s!='\0'))//if it is different letter
        {
            n--;
            s++;
        }
        if(*s!=*t)//if its the end of s but the last letters are different
            return 0; 
        s++;
        t++;
    }
    while(*s!='\0') //If there are more letters in the string
    {
        n--;
        s++;
    }
    if(n==0)
        return 1;
    else
        return 0;
}
void print_lines(char * str)
{
    char s[LINE]={'\0'};
    int numChar=Getline(s);
    while(numChar)//check if it its the end of the text
    {
        numChar=Getline(s);
        s[numChar]='\0';
        char *str1=s;
        int isSubstring=substring(str1,str);
        if(isSubstring)
        {
            int i=0;
            while(s[i])
            {
                printf("%c",s[i]);
                i++;
            }
            //printf("%s",&s);
        }
    }
}
void print_similar_words(char * str)
{
    char w[WORD]={'\0'};
    int numChar=getword(w);
    int count=1;//to know if its the first iteration 
    while(numChar!=0) //check if it its the end of the text
    { 
        char *str1=w;
        char *str2=w;
        char *copystr1=str; 
        char *copystr2=str;  
        int issimlar0=similar(str1,copystr1,0);//check if its the same word
        int issimlar1=similar(str2,copystr2,1);//check if its the same word if we delete one if the letter from str2
        if(issimlar1||issimlar0)
        {
            if(count)//if its the first iteration
                count=0;
            else
                printf("\n"); 
            int i=0;
            while(w[i])
            {
                printf("%c",w[i]);
                i++;
            }
          //  printf("%s",&w);
        }
        numChar=getword(w);
    }
    printf("\n"); 

}
int main()
{
    char searchWord[WORD];
    char *search=searchWord;
    getword(searchWord);
    char searchAction[WORD];
    getword(searchAction);
    if(searchAction[0]=='a')
        print_lines(search);
    else
        print_similar_words(search);
}