#include <stdio.h>
#include <string.h>
#include "txtfind.h"

int getline1 (char s[])
{
int count=0;
while (s[count]!='\n')
{
count++;
}
return count;
}

int getword (char w[])
{
    int count=0;
    while(w[count]!='\n'|| w[count]!='\t' || w[count]!=' ')
    {
        count++;
    }
    return count;
}

int substring (char *str1 , char *str2)
{
int count =0;
int size1=strlen(str1);
int size2=strlen(str2);
int i=0;
int j=0;

while(i<size1 && j<size2)
{
      if (str1[i]==str2[j])
      {
          count++;
          j++;
      }
      else {
          j=0;
          count=0;
      }
      i++;
    
    if (count ==size2){
        i=size1;
    }
}
if (count==size2){
    return 1;
}

return 0;
}
int helpEquals(char *s, char *t, int size){
   for (int i=0; i<size ; i++){
       if (s[i]!=t[i])
       return 0;
   }
   return 1;

}
int similar (char *s, char *t, int n)
{
    int i=0;
    int j=0;
    int sizeT=strlen(t);
int sizeS=strlen(s);
   
if (sizeT>sizeS)
return 0;

// if (sizeT!=sizeS && n==0)
// return 0;
// if (sizeS==sizeT){
//     int y= helpEquals(s,t,sizeT);
//     if(y==1 &&n==0){
//         return 1;
//     }
//     if(y==0){
//         return 0;
//     }
// }
while (j<sizeT)
{
    if (t[j]!=s[i])
    {
        n--;
        i++;
        //j--???
    }
    else{
        i++;
        j++;
    }
    if (n<0)
     {return 0;}
}
while (i<sizeS)
{
    n--;
    i++;
}
if (n!=0)
{
return 0;
}
return 1;
}

void print_lines(char* str, char *word)
{
  char strLine[LINE];
  int lenLine = 0;

  if(*str != '\0')
    lenLine =getline1(str);
int i=0;
while(i<lenLine)
{
    strLine[i]=str[i];
    i++;
}
  while(*str != '\0')
  {
    if(  lenLine>0 && ( substring(strLine, word) ) )
        printf("%s\n", strLine);

    str+=lenLine;
    lenLine = getline1(str);
    i=0;
    while(i<lenLine)
    {
        strLine[i]=str[i];
        i++;
    }
  } 
}

void print_similar_words(char* str, char *w)
{
  int lenWord =0;
  char strWord[WORD];
  lenWord =getword(strWord);
  while(*str !=  EOF)
  {
    if(  lenWord > 0 && ( similar(str ,strWord ,0) || similar(str ,strWord ,1) )  )
        printf("%s\n", strWord);
    char strWord[WORD];
    lenWord = getword(strWord);
  } 
}

int main()
{
int i=0;
char c;
char func;
char wordSearch[WORD];
char tempW[WORD];
char line[LINE];

printf("%d", similar("caats", "cat", 1));

while ( (c=getc(stdin)) != ' '  )
{
    wordSearch[i]=c;
    i++;
}
 wordSearch[i]='\0';
 printf(" wordserach: %s \n", wordSearch);
 i=0;
 while ((c=getc(stdin)) != '\n' )
{
    if (c=='a'||c=='b')
        func=c;
    i++;
}
 printf(" func: %c \n", func);

if (func=='a')
{//print_lines();
while((c=getc(stdin))!= EOF)
{
    line[0]=c; i++;
    while((c=getc(stdin))!= '\n')
    {
        line[i]=c;
        i++;
    }
    line[i]='\0';

    int con=substring(line, wordSearch);
    if (con)
       { 
           printf("%s\n",line);
            con=0;
       }
   i=0;
    }
}

if (func=='b')
{//print_similar_words();
int j=0;
while((c=getc(stdin))!= EOF)
{
    if((c)!= ' ' && (c)!= '\t' && (c)!= '\n')
    {
        tempW[j]=c;
        j++;
    }
    else 
    {
        tempW[j]='\0';
        j=0;
        int con0=similar(tempW,wordSearch,0);
        int con1=similar(tempW,wordSearch,1);
        if (con0 || con1)
        {
            printf("%s\n",tempW);
            con0=0;
            con1=0;
        }
    }
}
}

return 0;
}