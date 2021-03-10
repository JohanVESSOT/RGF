/*
 * Name all the librairie to include befor start the programmation 
*/

#include <wiringPi.h>
#include <stdio.h>

/*
 * Important :
 * Les pins GPIO en out sont de 3.3 V
 * Les pins en out ont tant 15 Kw de puissance (à chercher) 
*/

/*
 * Name all the function befor start the programme
*/
int WiringPiInit();
int LEDcfg(int*,char*);
int ActivePin(int*,char*);


void main(void)
{
    /* Initiaslise some Variable */
    int ledPin1 = 0 ; 
    int ledPin2 = 2 ;
    int ledPin3 = 3 ; 
    int ledPin4 = 21 ;
    int NombrePin = 4 ;
    int TableauPin[4] = {ledPin1,ledPin2,ledPin3,ledPin4} ;
    char TableauModeInit[4] = {OUTPUT,OUTPUT,OUTPUT,OUTPUT} ;
    char TableauModeAct[2] = {HIGH,LOW};  

    // Start the Programme
    printf("Program is starting ... \n");

    // Initialise the WiringPi Library 
    WiringPiInit();

    // Disable all LED 
    for (int i=0 ; i < NombrePin ; i++)
        {
            // Active new LED :
            ActivePin(&TableauPin[i],&TableauModeAct[1]);
        }
    delay (1000);
    // Initialise The Mode of pin selected
    for (int i=0 ; i < NombrePin ; i++)
    {
        LEDcfg(&TableauPin[i],&TableauModeInit[i]);
    }
    /* 
     * Satrt the Endless loop to  turn on and of and on the leds to make a chenillard 
    */
    while(1)
    {
        for (int i=0 ; i < NombrePin ; i++)
        {
            delay(1000); // Attente de 1S
            // Active new LED :
            ActivePin(&TableauPin[i],&TableauModeAct[0]);
            // Disable old LED :
            if (i == 0 )
            {
                ActivePin(&TableauPin[3],&TableauModeAct[1]);
            }
            else 
            {
                ActivePin(&TableauPin[i-1],&TableauModeAct[1]);
            }
        }
    }
}

int WiringPiInit()
{
    printf("Initialisation of the WiringPi sofware\n");
    wiringPiSetup(); //Initialize wiringPi.
    // TODO add a methode to see any probleme on initialisation
    if (TRUE)
    {
        printf("Initialisation Succesfull done\n");
        return TRUE ; 
    }
}


int LEDcfg(int* LED,char* fonction)
{
    printf("Initislise all pins with selected OUTPU/INPUT \n");
    pinMode(*LED,*fonction) ; // Set the pin in mode selected by fonction
    // TODO add a methode to see any probleme on mode selection
    if (TRUE)
    {
        printf("Pin : %d normaly configured in mode : %ld \n",*LED,*fonction);
        return TRUE ; 
    }
}


int ActivePin(int* LED,char* fonction)
{
    printf("Apply a GND or 3.3V to the selected Pin \n");
    digitalWrite(*LED,*fonction) ; // Set the pin in mode selected by fonction
    // TODO add a methode to see any probleme on mode selection
    if (TRUE)
    {
        printf("Pin : %d apply a : %ld \n",*LED,*fonction);
        return TRUE ; 
    }
}