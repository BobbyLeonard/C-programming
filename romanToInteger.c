#include <stdio.h>
#include <string.h>

struct numeral{
    char symbol;
    int value;
};

struct numeral * loadArrayStruct(struct numeral * arrS);
int romanToInt(char * s);

int main(void)
{   
    int convertedDigits = romanToInt("MCMXCIV");
    printf("Result: %i", convertedDigits);    
}

int romanToInt(char * s)
{
    int returnResult = 0;

    // Generate struct array
    int numeralArrayLength = 7;
    // Empty Array of structs
    struct numeral arrS[numeralArrayLength];  
    // 2nd Empty Array of structs, loaded by function
    struct numeral * arrR = loadArrayStruct(arrS);
    
  
    // Deal with input string
    int slen = strlen(s);
    for (int i = 0; i < slen; i++)
    {
        char currentRchar = s[i];
        for (int j = 0; j < numeralArrayLength; j++)
        {   
            int nextValue = 0;
            int interimResult = 0;
            if (arrR[j].symbol == s[i])
            {   
                if ((s[i] == 'I' && s[i + 1] == 'V') || (s[i] == 'I' && s[i + 1] == 'X') && (i + 1 < slen))
                {   
                    for (int k = 0; k < numeralArrayLength; k++)
                    {
                        if (arrR[k].symbol == s[i + 1])
                        {
                            nextValue = arrR[k].value;
                            break;
                        }    
                    }
                    
                    interimResult = nextValue - arrR[j].value; 
                    returnResult+=interimResult;
                    i+=1;
                    
                }   
                else if ((s[i] == 'X' && s[i + 1] == 'L') || (s[i] == 'X' && s[i + 1] == 'C') && (i + 1 < slen))
                {
                    for (int l = 0; l < numeralArrayLength; l++)
                    {
                        if (arrR[l].symbol == s[i + 1])
                        {
                            nextValue = arrR[l].value;
                            break;
                        }    
                    }
                    
                    interimResult = nextValue - arrR[j].value; 
                    returnResult+=interimResult;
                    i+=1;
                    
                }
                else if ((s[i] == 'C' && s[i + 1] == 'D') || (s[i] == 'C' && s[i + 1] == 'M') && (i + 1 < slen))
                {
                    for (int m = 0; m < numeralArrayLength; m++)
                    {
                        if (arrR[m].symbol == s[i + 1])
                        {
                            nextValue = arrR[m].value;
                            break;
                        }    
                    }
                    interimResult = nextValue - arrR[j].value; 
                    returnResult+=interimResult;
                    i+=1;
                    
                }   
                else
                {
                    returnResult+=arrR[j].value;   
                }
                    
                break;
            }
                 
        }

    }
    return returnResult;
}

struct numeral * loadArrayStruct(struct numeral * arrS)
{
    struct numeral I = {'I', 1};
    arrS[0] = I;
    struct numeral V = {'V', 5};
    arrS[1] = V;
    struct numeral X = {'X', 10};
    arrS[2] = X;
    struct numeral L = {'L', 50};
    arrS[3] = L;
    struct numeral C = {'C', 100};
    arrS[4] = C;
    struct numeral D = {'D', 500};
    arrS[5] = D;
    struct numeral M = {'M', 1000};
    arrS[6] = M;

    return arrS;
}
