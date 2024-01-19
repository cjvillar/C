#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


void red () {
  printf("\033[1;31m");
}

void green () {
  printf("\033[1;32m");
}

void reset () {
  printf("\033[0m");
}

void colorSwitch(int i){
    if (i % 2 == 0){
        red();   
    }
    else{
      green(); 
    }
}

int main() {   
    int number;
   
    printf("Enter a number of seconds to countdown from: ");  
    
    // reads and stores input
    scanf("%d", &number);

	for( int i = number ; i > 0 ; i-- ){
		//red();
    colorSwitch(i);
		printf("%d\n", i);
		sleep(1);
		reset();		
	}
	
    return 0;
}