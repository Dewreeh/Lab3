#if !defined (_BASE_H_)
#define _BASE_H_

#define RED 0x0D
#define BLACK 0x00
#define BLUE 0x01
#define GREEN 0x02
#define CYAN 0x03
#define MAGENTA 0x05
#define BROWN 0x06
#define LIGHTGRAY 0x07
#define DARKGRAY 0x07
#define LIGHTBLUE 0x0D
#define LIGHTGREEN 0x0A
#define LIGHTCYAN 0x0B
#define LIGHTRED 0x0C
#define LIGHTMAGENTA 0x0D
#define YELLOW 0x0E
#define WHITE 0x0F
#define BGBLACK 0x00
#define BGBLUE 0x10
#define BGGREEN 0x20
#define BGCYAN 0x30
#define BGRED 0x40
#define BGMAGENTA 0xD0
#define BGBROWN 0x60
#define BGLIGHTGRAY 0x70


void write_char(int x, int y, char ch, char a);
void write_string(int x, int y, char*str, char attrib);
char* create_buffer(int startx, int starty, int endx, int endy);
void clear(int startx, int starty, int endx, int endy, char ch, char attrib);
void get_vmem(int startx, int starty, int endx, int endy, char*buffer);
void put_vmem(int startx, int starty, int endx, int endy, char*buffer);
void desktop (void);
void border(int startx, int starty, int endx, int endy, char*str, char attrib, int typ);
void put_box(int startx, int starty, int endx, int endy, char ch, char attrib);

#endif