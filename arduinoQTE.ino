int pinA = 2;
int pinB = 3;
int pinC = 4;
int pinD = 5;
int pinE = 6;
int pinF = 7;
int pinG = 8;
int D1 = 9;
int pushButton [] = {10,11,12,13};
int statusButton = LOW;
int game[10] = {5,5,5,5,5,5,5,5,5,5};
int x = 0;
int score = 0;
int goodPush = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(pinA, OUTPUT);     
  pinMode(pinB, OUTPUT);     
  pinMode(pinC, OUTPUT);     
  pinMode(pinD, OUTPUT);     
  pinMode(pinE, OUTPUT);     
  pinMode(pinF, OUTPUT);     
  pinMode(pinG, OUTPUT);   
  pinMode(D1, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(pushButton[i], INPUT);
  }
  randomSeed(analogRead(0));
  for (int i = 0; i < 10; i++) {
      game[i] = random(1,5);
  }
}

void ledDisplay(int toDisplay) {
  switch (toDisplay) {
    case 1:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, HIGH);   
      digitalWrite(pinG, HIGH);
      break;
    case 2:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, LOW);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, HIGH);   
      digitalWrite(pinD, LOW);   
      digitalWrite(pinE, LOW);   
      digitalWrite(pinF, HIGH);   
      digitalWrite(pinG, LOW);
      break;
    case 3:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, LOW);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, LOW);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, HIGH);   
      digitalWrite(pinG, LOW);
      break;
    case 4:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, LOW);
      break;
    case 5:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, LOW);   
      digitalWrite(pinB, HIGH);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, LOW);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, LOW);
      break;
    case 6:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, HIGH);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, LOW);   
      digitalWrite(pinE, LOW);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, LOW);
      break;
    case 7:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, LOW);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, HIGH);   
      digitalWrite(pinG, HIGH);
      break;
    case 8:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, LOW);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, LOW);   
      digitalWrite(pinE, LOW);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, LOW);
      break;
     case 9:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, LOW);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, LOW);
      break;
    case 0:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, LOW);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, LOW);   
      digitalWrite(pinE, LOW);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, HIGH);
      break;
     case 10:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, LOW);   
      digitalWrite(pinB, LOW);   
      digitalWrite(pinC, LOW);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, LOW);   
      digitalWrite(pinF, LOW);   
      digitalWrite(pinG, LOW);
      break;
    default:
      digitalWrite(D1, HIGH);
      digitalWrite(pinA, HIGH);   
      digitalWrite(pinB, HIGH);   
      digitalWrite(pinC, HIGH);   
      digitalWrite(pinD, HIGH);   
      digitalWrite(pinE, HIGH);   
      digitalWrite(pinF, HIGH);   
      digitalWrite(pinG, HIGH);
      break;
  }
}

// the loop routine runs over and over again forever:
void loop() {
  if (x < 10) {
    ledDisplay(100);
    delay(1000);
    ledDisplay(game[x]);
    x++;
    while (statusButton == LOW) {
      for (int i = 0; i < 4; i++) {
        statusButton = digitalRead(pushButton[i]);
        if (statusButton == HIGH && pushButton[i] == 10 && game [x] == 1) {
          Serial.print("ok\n");
          goodPush = 1;
        } else if (statusButton == HIGH && pushButton[i] == 11 && game [x] == 2) {
          Serial.print("ok\n");
          goodPush = 1;
        } else if (statusButton == HIGH && pushButton[i] == 12 && game [x] == 3) {
          Serial.print("ok\n");
          goodPush = 1;
        } else if (statusButton == HIGH && pushButton[i] == 13 && game [x] == 4) {
          Serial.print("ok\n");
          goodPush = 1;
        }
      }
    }
    if (goodPush == 1) {
      score++;
    }
    goodPush = 0;
    statusButton = LOW;
  } else {
    ledDisplay(score);
    Serial.print(score);
    Serial.print('\n');
  }
  //ledDisplay(8);
}
