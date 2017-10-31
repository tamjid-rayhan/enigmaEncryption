#include <stdio.h>
#define DEBUG true

int shift1=0;
int shift2=0;
int shift3=0;

int rotorOffset[]={23,6,1};

char basicOrder[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


// Enigma i Rotor iii BDFHJLCPRTXVZNYEIWGAKMUSQO
char rotor1conn[]={'b','d','f','h','j','l','c','p','r','t','x','v','z','n','y','e','i','w','g','a','k','m','u','s','q','o'};

//Enigma I rotor II AJDKSIRUXBLHWTMCQGZNPYFVOE
char rotor2conn[]={'a','j','d','k','s','i','r','u','x','b','l','h','w','t','m','c','q','g','z','n','p','y','f','v','o','e'};

//Enigma I rotor I EKMFLGDQVZNTOWYHXUSPAIBRCJ
char rotor3conn[]={'e','k','m','f','l','g','d','q','v','z','n','t','o','w','y','h','x','u','s','p','a','i','b','r','c','j'};

//Wide reflector B YRUHQSLDPXNGOKMIEBFZCWVJAT
char reflector[]={'y','r','u','h','q','s','l','d','p','x','n','g','o','k','m','i','e','b','f','z','c','w','v','j','a','t'};

void printArray(char *k);
char rotorForward(char m);



int main(){


//encryption
char m=getchar();

char rf=rotorForward(m);
printf("\nRotorForward output is  %c", rf);

return 0;
}


void printArray(char k[]){
//printf("%s\n",k);
int i;
for(i=0;i<26;i++){
    printf("%c",k[i]);
}
printf("\n");
}



char rotorForward(char m){
    char c;//return value of this function
    char r;//carries the rotor output characters

    int index;//carries the array index for each step

    //shift first rotor
    shift1++;

    //calculate message character index
    index=m-97;

    //calculate first rotor input index
    index=(index+rotorOffset[0]+shift1)%26;

    #ifdef DEBUG
    printf("first rotor input index is %d\n",index);
    printf("First rotor input character is %c\n",basicOrder[index]);
    #endif

    //------first rotor output index-------
    r=rotor1conn[index];
    index=r-97;
    #ifdef DEBUG
    printf("\nfirst rotor output is %c\n\n",r);
    #endif
    //-------------------------------------

    //calculate second rotor input index
    index=(index+rotorOffset[1]+shift2-rotorOffset[0]-shift1)%26;

    #ifdef DEBUG
    printf("Second rotor input index is %d\n",index);
    printf("Second rotor input character is %c\n",basicOrder[index]);
    #endif

    //------second rotor output index--------
    r=rotor2conn[index];
    index=r-97;
    #ifdef DEBUG
    printf("\nsecond rotor output is %c\n\n",r);
    #endif
    //---------------------------------------

    //calculate third rotor input index
    index=(index+rotorOffset[2]+shift3-rotorOffset[1]-shift2)%26;

    #ifdef DEBUG
    printf("Third rotor input index is %d\n",index);
    printf("Third rotor input character is %c\n",basicOrder[index]);
    #endif

    //----third rotor output index-----
    r=rotor3conn[index];
    index=r-97;
    #ifdef DEBUG
    printf("\nthird rotor output is %c\n\n",r);
    #endif

    return r;
}
