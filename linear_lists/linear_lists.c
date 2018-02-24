/**
 * Michele Morelli
 *
 * Linear lists: C implementation of a stack 
 *
 */

#include "stack_functions.h"

int main(){
    srand(time(NULL)); //pushing random numbers
    STACK_INIT(stack);

    while (1){
        execute_command(&stack, get_input()); 
        draw(&stack);
    }

    return 0;
}

