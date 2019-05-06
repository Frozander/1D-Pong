#define A 13
#define B 12
#define C 11
#define D 10
#define E 9

// DURATION OF THE NOTES 
#define BPM 120    //  you can change this value changing all the others
#define H 2*Q //half 2/4
#define Q 60000/BPM //quarter 1/4 
#define EN Q/2   //eighth 1/8
#define S Q/4 // sixteenth 1/16
#define W 4*Q // whole 4/4

//NOTES
#define  LA3 (220.00)
#define F3  (174.61)
#define C4  (261.63)
#define E4  (329.63)
#define F4  (349.23)
#define Ab3 (207.65)
#define LA4 (440.00)
#define Gb4 (369.99)
#define G4  (392.00)
#define Ab4 (415.30)

#define BUZZER_PIN 6

#define MAINDELAY 200

volatile int gameInstance = 0;

volatile int dly = MAINDELAY; //starting delay for speed
volatile int ledIndex; //counter variable for loops

volatile int button1Pin = 2;
volatile int button2Pin = 3;

int leds[20][2]; //two dimensional array for assigning pins to leds (volatile)

int startpin = 9;

volatile int scoreP1 = 0; //variables for keeping scores of teams
volatile int scoreP2 = 0;

void restartGame()
{   

    startpin = random(9, 11);

    scoreP1 = 0;
    scoreP2 = 0;
    gameInstance = 0;
    dly = MAINDELAY;

}

void playTune() //plays a tune when the game ends
{

    tone(BUZZER_PIN,LA3,Q); 
    delay(1+Q); //delay duration should always be 1 ms more than the note in order to separate them.
    tone(BUZZER_PIN,LA3,Q);
    delay(1+Q);
    tone(BUZZER_PIN,LA3,Q);
    delay(1+Q);
    tone(BUZZER_PIN,F3,EN+S);
    delay(1+EN+S);
    tone(BUZZER_PIN,C4,S);
    delay(1+S);
    
    tone(BUZZER_PIN,LA3,Q);
    delay(1+Q);
    tone(BUZZER_PIN,F3,EN+S);
    delay(1+EN+S);
    tone(BUZZER_PIN,C4,S);
    delay(1+S);
    tone(BUZZER_PIN,LA3,H);
    delay(1+H);
    
    tone(BUZZER_PIN,E4,Q); 
    delay(1+Q); 
    tone(BUZZER_PIN,E4,Q);
    delay(1+Q);
    tone(BUZZER_PIN,E4,Q);
    delay(1+Q);
    tone(BUZZER_PIN,F4,EN+S);
    delay(1+EN+S);
    tone(BUZZER_PIN,C4,S);
    delay(1+S);
    
    tone(BUZZER_PIN,Ab3,Q);
    delay(1+Q);
    tone(BUZZER_PIN,F3,EN+S);
    delay(1+EN+S);
    tone(BUZZER_PIN,C4,S);
    delay(1+S);
    tone(BUZZER_PIN,LA3,H);
    delay(1+H);
    
    tone(BUZZER_PIN,LA4,Q);
    delay(1+Q);
    tone(BUZZER_PIN,LA3,EN+S);
    delay(1+EN+S);
    tone(BUZZER_PIN,LA3,S);
    delay(1+S);
    tone(BUZZER_PIN,LA4,Q);
    delay(1+Q);
    tone(BUZZER_PIN,Ab4,EN+S);
    delay(1+EN+S);
    tone(BUZZER_PIN,G4,S);
    delay(1+S);
    
    tone(BUZZER_PIN,Gb4,S);
    delay(1+S);
    tone(BUZZER_PIN,E4,S);
    delay(1+S);
    tone(BUZZER_PIN,F4,EN);
    delay(1+EN);
    
}

void light(int pin[], int duration)
{

    pinMode(A,INPUT); //turns all pins into input
    pinMode(B,INPUT);
    pinMode(C,INPUT);
    pinMode(D,INPUT);
    pinMode(E,INPUT);

    pinMode(pin[0], OUTPUT);  //turns two pins we use to control the led into outputs and lights them up
    digitalWrite(pin[0], HIGH);
    
    pinMode(pin[1], OUTPUT);
    digitalWrite(pin[1], LOW);

    delay(duration); //waits for (duration) miliseconds while given led is on

}


void scoreCheckforP1()
{
    
    if (ledIndex <= 3)
    {
        gameInstance = 1;
        dly -= 5;
    }
    
    else if (ledIndex > 3)
    {
        gameInstance = 4;
    }
       
}

void scoreCheckforP2()
{

    if (ledIndex >= 16)
    {
        gameInstance = 2;
        dly -= 5;
    } 
    
    else if (ledIndex <16)
    {
        gameInstance = 3;
    }
    
}

void setup() 
{

    randomSeed(analogRead(0)); // gets a truly random seed, not to be repetitive

    pinMode(button1Pin, INPUT_PULLUP); //sets up two buttons as INPUT_PULLUP
    pinMode(button2Pin, INPUT_PULLUP);

    pinMode(BUZZER_PIN, OUTPUT); //sets up a pin for the BUZZER_PIN

    attachInterrupt(0, scoreCheckforP1, FALLING); // Attaches an ISR to pin 2 as p1
    attachInterrupt(1, scoreCheckforP2, FALLING); // Attaches an ISR to pin 3 as p2

    //assigns pins that control each led in a multidimensional array
    leds[0][0] = A;
    leds[0][1] = B;

    leds[1][0] = B;
    leds[1][1] = A;

    leds[2][0] = B;
    leds[2][1] = C;

    leds[3][0] = C;
    leds[3][1] = B;

    leds[4][0] = C;
    leds[4][1] = D;

    leds[5][0] = D;
    leds[5][1] = C;

    leds[6][0] = D;
    leds[6][1] = E;

    leds[7][0] = E;
    leds[7][1] = D;

    leds[8][0] = A;
    leds[8][1] = C;

    leds[9][0] = C;
    leds[9][1] = A;

    leds[10][0] = B;
    leds[10][1] = D;

    leds[11][0] = D;
    leds[11][1] = B;

    leds[12][0] = C;
    leds[12][1] = E;

    leds[13][0] = E;
    leds[13][1] = C;

    leds[14][0] = A;
    leds[14][1] = D;

    leds[15][0] = D;
    leds[15][1] = A;

    leds[16][0] = B;
    leds[16][1] = E;

    leds[17][0] = E;
    leds[17][1] = B;

    leds[18][0] = A;
    leds[18][1] = E;

    leds[19][0] = E;
    leds[19][1] = A;

}


void loop() //gameInstance control loop
{    
    
    if (gameInstance == 0) {
        beginning();
    }
    else if (gameInstance == 1)
    {
        leftToRight();
    }   
    else if (gameInstance == 2)
    {
        rightToLeft();
    }
    
    else if (gameInstance == 3)
    {
        scoreP2++;
        dly = MAINDELAY;
        scoreDisplay();

        ledIndex = 10;
        leftToRight();
    } 
    else if (gameInstance == 4)
    {
        scoreP1++;
        dly = MAINDELAY;
        scoreDisplay();

        ledIndex = 9;
        rightToLeft();
    }

}

void leftToRight() //moves the game from left to right
{
    
    while((ledIndex < 20) && (gameInstance != 2)) //loops the leds to right while gameInstance isn't 2
    {
        light(leds[ledIndex], dly);

        ledIndex++;
    }
    
    
    if (ledIndex == 20) //calls gameInstance 4 if index reaches 20
    {
        gameInstance = 4;
    }
    
    
}

void rightToLeft() //moves the game from right to left
{

    while((ledIndex > -1) && (gameInstance != 1)) //loops the leds to left while gameInstance isn't 1
    {
        light(leds[ledIndex], dly);

        ledIndex--;
    }
    
    if (ledIndex == -1) //calls gameInstance 3 if index reaches 20
    {
        gameInstance = 3;
    }
}

void scoreDisplay()
{
    
    //Display p1 score

    if (scoreP1 == 1) {
        light(leds[0], 800);
    } 
    else if (scoreP1 == 2)
    {
        light(leds[0], 400);
        light(leds[1], 400);
    } 
    else if (scoreP1 == 3)
    {
        light(leds[0], 266);
        light(leds[1], 266);
        light(leds[2], 266);
    } 
    else if (scoreP1 == 4)
    {
        light(leds[0], 200);
        light(leds[1], 200);
        light(leds[2], 200);
        light(leds[3], 200);
    }
    


    //Display p2 score

    if (scoreP2 == 1) 
    {
        light(leds[19], 800);
    } 
    else if (scoreP2 == 2)
    {
        light(leds[19], 400);
        light(leds[18], 400);
    } 
    else if (scoreP2 == 3)
    {
        light(leds[19], 266);
        light(leds[18], 266);
        light(leds[17], 266);
    } 
    else if (scoreP2 == 4)
    {
        light(leds[19], 200);
        light(leds[18], 200);
        light(leds[17], 200);
        light(leds[16], 200);
    }

    if ((scoreP1 == 5) or (scoreP2 == 5)) //when any ıf the players reach the score of 5 restart game and celebrate
    {
        playTune();
        delay(3000);
        restartGame();
    }

}

void beginning() //the beginning state
{

    startpin = random(9, 11); //choses a random pin
    
    if (startpin == 9) //sets the index as starting pin and changes game instance to 1
    {
        ledIndex = startpin;
        gameInstance = 1;
    }
    else if (startpin == 10) //sets the index as starting pin and changes game instance to 2
    {
        ledIndex = startpin;
        gameInstance = 2;
    }

}
