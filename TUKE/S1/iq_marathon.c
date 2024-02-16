#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void draw(const int height, const int width, char world[][width+1]);
char change_direction(const int x, const int y, const int finish_x, const int finish_y, const char direction);
char find_cow(const int height, const int width, int *x, int *y, char world[][width+1]);
void find_finish(const int height, const int width, int *finish_x, int *finish_y, char world[][width+1]);
int solve_maze(const int height, const int width, char world[][width+1]);

int main(){
    FILE* fp = fopen("maze1","r");

    if(fp == NULL){
        perror("Error opening file.");
        return 1; 
    }
    int width,height;
    fscanf(fp , "%d %d ", &width , &height);
    char world[height][width + 1];

    for(int idx_h = 0; idx_h < height; idx_h++) {
       
        fgets(world[idx_h] , width + 1, fp);
        fgetc(fp);
    }
    draw(height, width,world);
    fclose(fp);

    return 0;
}
void draw(const int height, const int width, char world[][width+1]);
char change_direction(const int x, const int y, const int finish_x, const int finish_y, const char direction){
    int width, height;
    for(int idx_h = 0; idx_h < height; idx_h++){
        printf("%s\n", world[idx_h]);
    }

}
char find_cow(const int height, const int width, int *x, int *y, char world[][width+1]){
    for(int idx_h = 0;idx_h < height; idx_h++ ){
        for(int idx_w < width; idx_w++){
            char tmp = world[idx_h][idx_w];
            if(tmp == 'W' tmp ++ 'S'  tmp == 'E' || tmp = 'N'){
                
            }
        }
    }
}