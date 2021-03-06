#include <stdio.h>
//#define DEBUG

int shift1=0;
int shift2=0;
int shift3=0;

int rotorOffset[]={0,0,0};
int ringSetting[]={26,26};

char basicOrder[]={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


// Enigma i Rotor iii BDFHJLCPRTXVZNYEIWGAKMUSQO
char rotor1conn[]={'b','d','f','h','j','l','c','p','r','t','x','v','z','n','y','e','i','w','g','a','k','m','u','s','q','o'};

//Enigma I rotor II AJDKSIRUXBLHWTMCQGZNPYFVOE
char rotor2conn[]={'a','j','d','k','s','i','r','u','x','b','l','h','w','t','m','c','q','g','z','n','p','y','f','v','o','e'};

//Enigma I rotor I EKMFLGDQVZNTOWYHXUSPAIBRCJ
char rotor3conn[]={'e','k','m','f','l','g','d','q','v','z','n','t','o','w','y','h','x','u','s','p','a','i','b','r','c','j'};

//Wide reflector B YRUHQSLDPXNGOKMIEBFZCWVJAT
char reflector[]={'y','r','u','h','q','s','l','d','p','x','n','g','o','k','m','i','e','b','f','z','c','w','v','j','a','t'};

//Enigma I rotorI inverse UWYGADFPVZBECKMTHXSLRINQOJ
char invRotor3[]={'u','w','y','g','a','d','f','p','v','z','b','e','c','k','m','t','h','x','s','l','r','i','n','q','o','j'};

//Enigma I rotor II inverse
char invRotor2[]={'a','j','p','c','z','w','r','l','f','b','d','k','o','t','y','u','q','g','e','n','h','x','m','i','v','s'};

//Enigma I rotor III inverse
char invRotor1[]={'t','a','g','b','p','c','s','d','q','e','u','f','v','n','z','h','y','i','x','j','w','l','r','k','o','m'};


void printArray(char *k);
char rotorForward(char m);

char message[30];

int main(){
    int i;
printf("Enter message: ");
           gets(message);

for(i=0;i<strlen(message);i++){

char rf=rotorForward(message[i]);
//printf("\nRotorForward output is  %c\n", rf);
printf("%c",rf);
}
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

    //shift second rotor
    if(shift1==ringSetting[0])
    {
        shift2++;
    }
    //shift third rotor
    if(shift2==ringSetting[1]){
    shift3++;
    }
    if(shift1==26)
        {shift1=0;}
    if(shift2==26)
        {shift2=0;}
    if(shift3==26)
        {shift3=0;}

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
    index=index+rotorOffset[1]-rotorOffset[0];

    if (index<0){
    index =26+index;
    }


    index=(index+shift2-shift1);
    index=index%26;
    if (index<0){
    index =26+index;
    }

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
    index=index+rotorOffset[2]-rotorOffset[1];

    if (index<0){
    index =26+index;
    }


    index=(index+shift3-shift2);
    index=index%26;
    if (index<0){
    index =26+index;
    }

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

    //calculate reflector input index
    index=(index-rotorOffset[2]-shift3);
    if(index<0){
    index=26+index;
    }
    index=index%26;


    #ifdef DEBUG
    printf("Reflector input index is %d\n",index);
    printf("reflector input character is %c\n",basicOrder[index]);
    #endif

    //------reflector output-----------
    r=reflector[index];
    index=r-97;

    #ifdef DEBUG
    printf("\nreflector output is %c\n\n",r);
    #endif

    //calculate inverse third rotor input index
    index=(index+rotorOffset[2]+shift3)%26;

     #ifdef DEBUG
    printf("Inverse 3rd rotor input index is %d\n",index);
    printf("Inverse 3rd rotor input character is %c\n",basicOrder[index]);
    #endif

    //----Inverse third rotor output index----
    r=invRotor3[index];
    index=r-97;
    #ifdef DEBUG
    printf("\nInverse third rotor output is %c\n\n",r);
    #endif

    //calculate inverse second rotor input index
    index=index+rotorOffset[1]-rotorOffset[2];
    if(index<0){
    index=26+index;
    }

    index=(index+shift2-shift3);
    index=index%26;

    if(index<0){
    index=26+index;
    }

    #ifdef DEBUG
    printf("Inverse 2nd rotor input index is %d\n",index);
    printf("Inverse 2nd rotor input character is %c\n",basicOrder[index]);
    #endif

    //----------Inverse second rotor output index-------
    r=invRotor2[index];
    index=r-97;
    #ifdef DEBUG
    printf("\nInverse second rotor output is %c\n\n",r);
    #endif
    //--------------------------------------------------


    //calculate inverse first rotor input index
    index=index+rotorOffset[0]-rotorOffset[1];
    if(index<0){
    index=26+index;
    }

    index=(index+shift1-shift2);
    index=index%26;
    if(index<0){
    index=26+index;
    }

    #ifdef DEBUG
    printf("Inverse 1st rotor input index is %d\n",index);
    printf("Inverse 1st rotor input character is %c\n",basicOrder[index]);
    #endif

    //----------Inverse first rotor output index-------
    r=invRotor1[index];
    index=r-97;
    #ifdef DEBUG
    printf("\nInverse first rotor output is %c\n\n",r);
    #endif

    //calculate plugboard input index
    index=index-rotorOffset[0];
    if(index<0){
    index=26+index;
    }

    index=(index-shift1)%26;

    if(index<0){
    index=26+index;
    }

    //-----Final Output------
    r=basicOrder[index];

    return r;
}
