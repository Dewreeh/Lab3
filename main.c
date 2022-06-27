#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <base.h>
#include <window.h>
int main(void){
    window_t* w1,* w2;
    desktop();
    w1 = window_create("WINDOW1", 0, 4, 18, 27, WHITE | BGRED, 2);
    w2 = window_create("WINDOW2", 5, 17, 15, 20, WHITE | BGBLUE, 1);
    getch();
    window_open(w1);
    getch();
    window_open(w2);
    getch();
    window_close(w2);
    getch();
    window_close(w1);
    getch();
    window_delete(w1);
    getch();
    window_delete(w2);
    return 0;
}



