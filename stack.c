#include <stdio.h>
#define STACK_SIZE 10
#define STACK_INIT(X) STACK X = {.T = 0}

typedef struct {
    int T; // the stack pointer
    int st[STACK_SIZE];
} STACK;

void push(STACK *stack, int value);
int pop(STACK *stack);
void draw();
void get_input();
void overflow();
void underflow();
void stack_is_empty();

int main(){
    STACK_INIT(stack);
    push(&stack, 67);
    printf("\nT is now %d.\n", stack.T);
    pop(&stack);
    pop(&stack);

    return 0;
}

void push(STACK *stack, int value){
   if (stack->T >= STACK_SIZE - 1){
        overflow();
   } 
   else{
    stack->T++;
    stack->st[stack->T] = value;
   }
   printf("Pushed %d onto the stack.\nT is now %d.\n", value, stack->T);
}

int pop(STACK *stack){
    int returned_value;
    if (!stack->T){
        underflow();
    }
    else{
        returned_value = stack->st[stack->T];
        stack->T--;
        printf("Popped %d from the stack.\nT is now %d.\n", returned_value, stack->T);
        return returned_value;
    }   

}

void overflow(){
    printf("OVERFLOW!!\n\n");
}

void underflow(){
    printf("UNDERFLOW!!\n\n");
}
