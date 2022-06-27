#if !defined (_WINDOW_H_)
#define _WINDOW_H_
typedef struct {
    int startx, starty, endx, endy;
    int attrib;
    char name[80];
    int typ;
    char* p;
} window_t;
window_t* window_create(char *name, int startx, int starty, int endx, int endy, int attrib, int typ);
void window_delete(window_t* w);
void window_open(window_t* w);
void window_close(window_t* w);

#endif