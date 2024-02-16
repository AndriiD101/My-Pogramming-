#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

bool is_valid_ip(const char * addr) {
  char *token;
  char temp[20]; 
  strcpy(temp, addr); 
  token = strtok(temp, ".");
  int flag = 0;
  while(token != '\0'){
    for (int i = 0; token[i] != '\0'; i++) {
      if (!isdigit(token[i])){
        return false;
        }
    }
    if(token[0] == '0'){
      return false;
    }
    int num = atoi(token);
    if(num <0){
      return false;
    }
    if(0<num && num<=255){
      flag++;
    }
    token = strtok(NULL, ".");
  }
  if(flag == 4){
    return true;
  }
  return false;
} 

int main()
{

    return 0;
}