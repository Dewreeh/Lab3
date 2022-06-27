#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <base.h>
#include <window.h>

window_t* window_create(char*name, int startx, int starty, int endx, int endy, int attrib, int typ){

        window_t *w= malloc(sizeof(window_t));
        w->startx = startx;
        w->starty = starty;
        w->endx = endx;
        w->endy = endy;
        w->attrib = attrib;
        w->typ = typ;
        strcpy(w->name,name);
        return w;
    
}
void window_delete(window_t* w){
    free(w->p);
    free(w);
}
void window_open(window_t*w){
    w->p = create_buffer(w->startx, w->starty, w->endx, w->endy);
    get_vmem(w->startx, w->starty, w->endx, w->endy, w->p);
    clear(w->startx + 1, w->starty + 1, w->endx - 1, w->endy - 1, ' ', w->attrib);
    border(w->startx, w->starty, w->endx, w->endy, w->name, w->attrib, w->typ);
    
}
void window_close(window_t*w){
    put_vmem(w->startx, w->starty, w->endx, w->endy, w->p);
}



