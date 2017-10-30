#include <stdio.h>
#define DEBUG true

char initRotorPos[]={'a','a','a'};
//basic alphabatic order
char basicOrder[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
// Enigma i Rotor iii BDFHJLCPRTXVZNYEIWGAKMUSQO
char rotorIIIorder[]={'b','d','f','h','j','l','c','p','r','t','x','v','z','n','y','e','i','w','g','a','k','m','u','s','q','o'};

//char templatechararray[]={'','','','','','','','','','','','','','','','','','','','','','','','','',''};

//Enigma I rotor II AJDKSIRUXBLHWTMCQGZNPYFVOE
char rotorIIorder[]={'a','j','d','k','s','i','r','u','x','b','l','h','w','t','m','c','q','g','z','n','p','y','f','v','o','e'};
//Enigma I rotor I EKMFLGDQVZNTOWYHXUSPAIBRCJ
char rotorIorder[]={'e','k','m','f','l','g','d','q','v','z','n','t','o','w','y','h','x','u','s','p','a','i','b','r','c','j'};
//Wide reflector B YRUHQSLDPXNGOKMIEBFZCWVJAT
char reflector[]={'y','r','u','h','q','s','l','d','p','x','n','g','o','k','m','i','e','b','f','z','c','w','v','j','a','t'};

void initializeRotors();
void printArray(char *k);
void shiftArrayOnePosition(char *k, int size);
char rotorIII(char m);
char rotorII(char m);
char rotorI(char m);
int main(){
//printf("%d %d",'a','z');
//Code for changing the array initializations according to rotor starting position
initializeRotors();
char m=getchar();
//printf("  %c", m);
char r3=rotorIII(m);
printf("  %c", r3);
char r2=rotorII(r3);
printf("  %c", r2);
char r1=rotorI(r2);
printf("  %c", r1);
return 0;
}
void shiftArrayOnePosition(char *k, int size) {
    int i;
    char temp;
    /*Save first element in a temporary variable and
    shift remaining elements by one index left */
    temp = k[0];

    for(i = 0; i < size-1; i++) {
        k[i] = k[i+1];
    }
    /* Now put the firt element of
    original array to last index */
    k[i] = temp;
}

void initializeRotors(){
int shift,i;
shift =initRotorPos[0]-97;
for(i=0;i<shift;i++){
    shiftArrayOnePosition(rotorIIIorder,26);
}
shift =initRotorPos[1]-97;
for(i=0;i<shift;i++){
    shiftArrayOnePosition(rotorIIorder,26);
}
shift =initRotorPos[2]-97;
for(i=0;i<shift;i++){
    shiftArrayOnePosition(rotorIorder,26);
}
#ifdef DEBUG
printArray(rotorIIIorder);
printArray(rotorIIorder);
printArray(rotorIorder);
#endif // DEBUG
}
void printArray(char k[]){
//printf("%s\n",k);
int i;
for(i=0;i<26;i++){
    printf("%c",k[i]);
}
printf("\n");
}
char rotorIII(char m){
    char c;
    int index=m-97;
    shiftArrayOnePosition(rotorIIIorder,26);
    c=rotorIIIorder[index];
    return c;
}
char rotorII(char m){
char c;
int index=m-97;
c=rotorIIorder[index-1];
    return c;
}
char rotorI(char m){
char c;
int index=m-97;
c=rotorIorder[index];
    return c;
}
