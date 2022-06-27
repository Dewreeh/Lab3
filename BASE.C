#include <base.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VMEM (char*)0xB8000000L

void write_char(int x, int y, char ch, char attrib)
{
	char *v = (char*)0xB8000000L;
	v = VMEM + x*160+y*2;
	*(v++) = ch;
	*(v++) = attrib;
}
void write_string(int x, int y, char*string, char attrib)
{
	for(; *string; string++) write_char(x, y++, *string, attrib);
}

char* create_buffer(int endx, int startx, int endy, int starty){
    char *p;
    int size = (endx-startx+1)*(endy-starty+1)*2*sizeof(char);
    p = malloc(size);
    if( !p ) {
        exit(1);
    }
    return p;
}

void clear(int startx, int starty, int endx, int endy, char ch, char attrib){
    int x;
    int y;
    for(x = startx; x <= endx; x++){
        for(y = starty; y<=endy; y++){
            write_char (x, y, ch, attrib);
        }
    }
}
void get_vmem(int startx, int starty, int endx, int endy, char*buffer){
    char *p;
    int i = 0;
    int x;
    int y;
    for(x = startx; x <= endx; x++){
        for(y = starty; y<=endy; y++) {
        p = VMEM + x * 160 + y * 2;
        *buffer++ = *p++;
        *buffer++ = *p;
        }
    }

}

void put_vmem(int startx, int starty, int endx, int endy, char*buffer){
    char *p;
    int i = 0;
    int x;
    int y;
    for(x = startx; x <= endx; x++){
        for(y=starty; y<=endy; y++) {
        p = VMEM + x * 160 + y * 2;
        *p++ = *buffer++;
        *p = *buffer++;
        }
    }
}
void desktop(){
    clear(0, 0, 24, 79, 0xB0, WHITE | BGBLUE);
}
void border(int startx, int starty, int endx, int endy, char attrib, int type){
	if (type == 2){
    	int y, x;
    	clear(startx+1, starty+1, endx-1, endy-1, 0xBA, attrib);
    	clear(startx+2, starty+2, endx-2, endy-2, 0xB0, attrib);
    	write_char(startx+1, starty+1, 0xC9, attrib);
    	write_char(startx+1, endy-1, 0xBB, attrib);
    	write_char(endx-1, starty+1, 0xC8, attrib);
    	write_char(endx-1, endy-1, 0xBC, attrib);
    	for(y = starty+2; y<=endy;y++){
        	write_char(starty+1, y, 0xCD, attrib);
    	}	        
    	for(x = starty+2; x<=endy-2; x++){
        	write_char(endx-1, x, 0xCD, attrib);
    	}
	}
	else if(type == 1){
		clear(startx+1, starty+1, endx-1, endy-1, 0xBA, attrib);
    	clear(startx+2, starty+2, endx-2, endy-2, 0xB0, attrib);
    	write_char(startx+1, starty+1, 0xDA, attrib);
    	write_char(startx+1, endy-1, 0xBF, attrib);
    	write_char(endx-1, starty+1, 0xC0, attrib);
    	write_char(endx-1, endy-1, 0xD9, attrib);
    	for(y = starty+2; y<=endy;y++){
        	write_char(starty+1, y, 0xCD, attrib);
    	}	        
    	for(x = starty+2; x<=endy-2; x++){
        	write_char(endx-1, x, 0xCD, attrib);
    	}
	}
}

void name(int startx, int starty, int endx, int endy, char* ch, char attrib){
    int name_length = strlen(ch);
    int center = (starty+endy-name_length)/2;
    write_string(startx+1, center, "Hello", attrib);
}


	



