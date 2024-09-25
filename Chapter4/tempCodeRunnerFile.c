#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> /* for isdigit() */
#include <math.h>

#define MAXOP 100  /* max size of operand or operator */
#define NUMBER '0' /* signal that a number was found */

/* function prototypes */
int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
char current_var[10];
/* reverse Polish calculator */
#define MAXVAL 100 /* maximum depth of val stack */
int sp = 0;       /* next free stack position */
double val[MAXVAL]; /* value stack */
double variables[26] = {0}; // Array to hold values for variables 'a' to 'z'

/* push: push f onto value stack */
void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

/* pop: pop and return top value from stack */
double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void duplicate(void) {
    if (sp > 0) { // Check if there is at least one element on the stack
        double new_val = val[sp - 1]; // Get the top value
        push(new_val); // Push it back onto the stack
    } else {
        printf("error: stack empty, cannot duplicate\n"); // Error message if stack is empty
    }
}

/* main: reverse Polish calculator */
int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
    if (isalpha(s[0])) {
           int value_to_store = s[0] - 'a'; // Convert char 'a' to index 0
           printf("%d\n", value_to_store);
            if ((type = getop(s)) == '=') {
                double number_to_store = pop();
                variables[value_to_store] = number_to_store;
                printf("Stored %f in variable %c\n", number_to_store, s[0]);
            } else {
                push(variables[value_to_store]); // Push variable value to stack
            }
            continue; // Skip further processing after handling variables
        }
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0) {
                int op1 = (int)pop();
                int op2_int = (int)op2;
                push(op1 % op2_int);
            } else {
                printf("error: zero divisor\n");
            }
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '=':
            
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}

/* getch and ungetch */
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
void ungetch2(char s[]) {
    int i = 0;
    // Calculate the length of the string first
    while (s[i] != '\0') {
        i++;
    }
    
    // Push back characters in reverse order
    while (i > 0) {
        if (bufp >= BUFSIZE) {
            printf("ungetch: too many characters\n");
            return; // Early exit if buffer is full
        } else {
            buf[--bufp] = s[--i]; // Push back characters
        }
    }
}
/* getop: get next operator or numeric operand */
int getop(char s[]) {
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ; /* skip whitespace */
    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
        return c; /* not a number */
    
    i = 0;
    if (c == '-') {
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c; /* negative number */
        else {
            if (c != EOF)
                ungetch(c);
            return '-'; /* subtraction */
        }
    }

    if (isdigit(c)) /* collect integer part */
        while (isdigit(s[++i] = c = getch()))
            ;
    
    if (c == '.') /* collect fraction part */
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    
    return NUMBER;
}
