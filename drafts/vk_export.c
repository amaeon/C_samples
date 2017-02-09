#include <stdio.h>
#include <string.h>

#define MAXLEN 2000
#define EMPTY 0
#define MBTAG 1
#define COMMENT 2
#define TAG 3


int gettag(FILE *f, char *s, int limit);
int getimgnm(char *s, char *nm);

int main(int argc, char const *argv[])
{
	FILE *f;
	f=fopen("in.html","r");

	int num = 0;
	char str[MAXLEN];
	char oldnm[MAXLEN];
	char newnm[MAXLEN];
	while(gettag(f,str,MAXLEN)>0){
		//printf("%s\n",str);
		if(getimgnm(str,oldnm)>0){
			++num;
			if(num<10)
				sprintf(newnm,"00%d.jpg",num);
			else if(num<100)
				sprintf(newnm,"0%d.jpg",num);
			else 
				sprintf(newnm,"%d.jpg",num);
			printf("%s -> %s\n",oldnm,newnm);
			rename(oldnm,newnm);
		}
	}

	fclose(f);
	return 0;
}

int gettag(FILE *f, char *s, int limit)
{
	int state = EMPTY;
	int c_lvl = 0;
	int i = 0;
	int c;
	while((c=fgetc(f))!=EOF && i<limit){
		if(state==EMPTY){
			// printf("%c EMPTY\n",c); // TEST
			if(c=='<'){
				s[i++]=c;
				state=MBTAG;
			}
		}
		else if(state==MBTAG){
			// printf("%c MBTAG\n",c); // TEST
			s[i++]=c;
			if(c=='>'){
				s[i]='\0';
				return i;
			}
			if(i>3){
				if(s[1]!='!' && s[2]!='-' && s[3]!='-')
					state=TAG;
				else{
					i=0;
					state=COMMENT;
				}
			}
		}
		else if(state==COMMENT){ // not detecting other tags inside a comment
			// printf("%c COMMENT\n",c); // TEST
			s[i]=c;
			i= (i+1)%5;
			if(c=='>' && s[(i-2)%5]=='-' && s[(i-3)%5]=='-'){
				i=0;
				state=EMPTY;
			}
		}
		else if(state==TAG){
			// printf("%c TAG\n",c); // TEST
			s[i++]=c;
			if(c=='>'){
				s[i]='\0';
				return i;
			}
		}
	}
	return -1;
}

int getimgnm(char *s, char *nm)
{
	char *pos = NULL;
	if(strstr(s,"img")!=NULL){
		if((pos=strstr(s,"src="))!=NULL){
			pos+=3;
			while(*(++pos)!='\"' && *pos!='\0');
			while(*(++pos)!='\"' && *pos!='\0');
			while(*(--pos)!='/');
			while(*(++pos)!='\"')
				*nm++=*pos;
			*nm='\0';
			return 1;
		}
	}
	return -1;
}