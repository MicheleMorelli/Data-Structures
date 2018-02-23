#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define STACK_SIZE 10
#define STACK_INIT(X) STACK X = {.T = 0}

typedef struct {
    int T; // the stack pointer
    int st[STACK_SIZE]; 
} STACK;

void push(STACK *stack, int value);
int pop(STACK *stack);
void draw();
int get_input();
void execute_command(STACK *stack, int input);
int overflow();
int underflow();
int stack_is_empty(STACK *stack);

int main(){
    srand(time(NULL)); //pushing random numbers
    STACK_INIT(stack);

    while (1==1){
        execute_command(&stack, get_input()); 
    }

    return 0;
}

void push(STACK *stack, int value){
   if (stack->T >= STACK_SIZE - 1){
        overflow();
   } 
   else{
    stack->T++;
    stack->st[stack->T] = value;
    printf("Pushed %d onto the stack.\nT is now %d.\n", value, stack->T);
   }
}

int pop(STACK *stack){
    int returned_value;
    if (stack_is_empty(stack)){
        underflow();
    }
    else{
        returned_value = stack->st[stack->T];
        stack->T--;
        printf("Popped %d from the stack.\nT is now %d.\n", returned_value, stack->T);
        return returned_value;
    }   

}

int overflow(){
    printf("OVERFLOW!!\n\n");
    return 1;
}

int underflow(){
    printf("UNDERFLOW!!\n\n");
    return 1;
}

int stack_is_empty(STACK *stack){
    return (!stack->T) ? 1 : 0;
}

int get_input(){
    int val;
    printf("1- Push\n2- Pop\n3- Show state\n");
    scanf("%d", &val);
    return val;
}

void execute_command(STACK *stack, int input){
    switch(input){
        case 1:
            push(stack, rand() % 50 + 1); //using random nums for simplicity
            break;

        case 2:
            pop(stack);
            break;

        case 3:
        default:
            //draw();
            break;
    }
}
