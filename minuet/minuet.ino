#define _B0  31
#define _C1  33
#define _CS1 35
#define _D1  37
#define _DS1 39
#define _E1  41
#define _F1  44
#define _FS1 46
#define _G1  49
#define _GS1 52
#define _A1  55
#define _AS1 58
#define _B1  62
#define _C2  65
#define _CS2 69
#define _D2  73
#define _DS2 78
#define _E2  82
#define _F2  87
#define _FS2 93
#define _G2  98
#define _GS2 104
#define _A2  110
#define _AS2 117
#define _B2  123
#define _C3  131
#define _CS3 139
#define _D3  147
#define _DS3 156
#define _E3  165
#define _F3  175
#define _FS3 185
#define _G3  196 //Violin G String
#define _GS3 208
#define _A3  220
#define _AS3 233
#define _B3  247
#define _C4  262
#define _CS4 277
#define _D4  294 //Violin D String
#define _DS4 311
#define _E4  330
#define _F4  349
#define _FS4 370
#define _G4  392
#define _GS4 415
#define _A4  440 //Violin A String
#define _AS4 466
#define _B4  494
#define _C5  523
#define _CS5 554
#define _D5  587
#define _DS5 622
#define _E5  659//Violin E String
#define _F5  698
#define _FS5 740
#define _G5  784
#define _GS5 831
#define _A5  880
#define _AS5 932
#define _B5  988
#define _C6  1047
#define _CS6 1109
#define _D6  1175
#define _DS6 1245
#define _E6  1319
#define _F6  1397
#define _FS6 1480
#define _G6  1568
#define _GS6 1661
#define _A6  1760
#define _AS6 1865
#define _B6  1976
#define _C7  2093
#define _CS7 2217
#define _D7  2349
#define _DS7 2489
#define _E7  2637
#define _F7  2794
#define _FS7 2960
#define _G7  3136
#define _GS7 3322
#define _A7  3520
#define _AS7 3729
#define _B7  3951
#define _C8  4186
#define _CS8 4435
#define _D8  4699
#define _DS8 4978
#define _NS 0 //Rest

int PIEZO_OUTPUT_PIN = 8;
//array of notes
int minuet[] = {_D5,_G4,_A4,_B4,_C5,_D5,_G4,_G4,_E5,_C5,_D5,_E5,_FS5,_G5,_G4,_G4,_C5,_D5,_C5,_B4,_A4,_B4,_C5,_B4,_A4,_G4,_FS4,_G4,_A4,_B4,_G4,_A4,_D5,_G4,_A4,_B4,_C5,_D5,_G4,_G4};
//note lengths - 80: half note, 40: quarter note, 20: eight note, etc.
int beats[] = {40,20,20,20,20,40,40,40,40,20,20,20,20,40,40,40,40,20,20,20,20,40,20,20,20,20,40,20,20,20,20,120,40,20,20,20,20,40,40,40};
int tempo = 100;
void setup() {
  //Iterate through the song Humoresque's notes
  for (int i = 0; i <sizeof(minuet)/2; i++) {
    //Grab the default duration
    int duration = tempo;
    //Check if the asked for index does not exceed the beat array size
    if(sizeof(beats)/2 -1 >= i){
      //Take in the given note length, divide by 10, multiply by 145
      duration = tempo * beats[i]/10;
    }
    //Sound the piezo!
    tone(PIEZO_OUTPUT_PIN, minuet[i],duration);
    //Minimal delay between notes
    delay(duration*1.2);
  }
}
//Loop is empty to allow the song to be played only once during setup...
void loop(){}
