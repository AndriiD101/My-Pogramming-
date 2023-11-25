#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <stdbool.h>
#include <time.h>



void game_field(const int rows, const int columns, char field[rows][columns]){
    printf("\n");
    int tmp = 0;
    for(int j = 0; j < (rows+2); j++){
        for(int i = 0; i < (columns*4+3); i++){
            // vytlaci prvy stlpec (cisla)
            if(i == 0){
                if(j < rows){
                    if(j+1 < 10){
                        printf(" %d", j+1);
                    } else {
                        printf("%d", j+1);
                    }
                    continue;
                } else {
                    printf("%c%c", ' ', ' ');
                    continue;
                }
            }
            // vytlaci druhy stlpec (medzery)
            if(i == 1){
                printf("%c", ' ');
                continue;
            }
            // medzerove stlpce
            if((i%2) == 1){
                if(j != rows){
                    printf("%c", ' ');
                    continue;
                } else if (j == rows){
                    if(tmp == 0){
                        printf("%c", '\\');
                        tmp = 1;
                        continue;
                    } else if(tmp == 1){
                        printf("%c", '/');
                        tmp = 0;
                        continue;
                    }
                }
            }
            // palickove stlpce
            if((i%4) == 2){
                if(j < rows){
                    printf("%c", '|');
                    continue;
                } else if(j == rows){
                    printf("%c", '^');
                    continue;
                } else {
                    printf("%c", ' ');
                    continue;
                }
            }
            // znakove stlpce
            if((i%4) == 0){
                if(j < rows){
                    printf("%c", field[j][i/4-1]);
                    continue;
                } else if(j == rows){
                    printf("%c", '_');
                    continue;
                } else if(j > rows){
                    printf("%d", i/4);
                    continue;
                }
            }
        }
        printf("\n");
    }
}
int main()
{
  int rows = 4, columns = 4;
  char field[rows][columns];
  game_field(6, 4, field);

  return 0; 
}