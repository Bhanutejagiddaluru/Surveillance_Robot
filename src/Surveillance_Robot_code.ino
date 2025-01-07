#define ENA      // define enable end for driver module
#define ENB   
#define IN_1     // define pin for driver module
#define IN_2  
#define IN_3 
#define IN_4 

int speedCar = ; //input v for turning
int speedCar1 = ;  //input v for go forward or backward

void setup() {
  Serial.begin(115200);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN_1, OUTPUT);
  pinMode(IN_2, OUTPUT);
  pinMode(IN_3, OUTPUT);
  pinMode(IN_4, OUTPUT);
  
  pinMode(INT_1, INPUT);
  pinMode(INT_2, INPUT);


  //check the connection of Bluetooth, otherwise block here





  

  server.begin();
  
}

void goahead() //car moves forward
{  
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  analogWrite(ENA, speedCar1);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(ENB, speedCar1);
}

void goleft() //car turns left
{  
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, HIGH);
  analogWrite(ENB, speedCar);  
}

void goback() //car moves back
{  
  digitalWrite(IN_1, HIGH);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCar1);

  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCar1);
}

void goright() //car turns right
{ 
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, HIGH);
  analogWrite(ENA, speedCar);
  
  digitalWrite(IN_3, HIGH);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCar);
}

void gostop() //car stops
{  
  digitalWrite(IN_1, LOW);
  digitalWrite(IN_2, LOW);
  analogWrite(ENA, speedCar);

  digitalWrite(IN_3, LOW);
  digitalWrite(IN_4, LOW);
  analogWrite(ENB, speedCar);
}

void loop() {
  //Monitor data coming from the client



  

  //if receive data successfully
  if(client)
  {
    Serial.println("New Client.");
    while(client.connected())
    {
      if(client.available())
      {
        char c = client.read();
        if(c == '1') // move forward when receive 1
        { 
          gostop();
          goahead();
        }
        if(c == '2') // turn left when receive 2
        { 
          gostop();
          goleft();
          delay(300);
          gostop();
        }
        if(c == '3') // move backward when receive 3
        { 
          gostop();
          goback();
        }
        if(c == '4') // turn right when receive 4
        { 
          gostop();
          goright();
          delay(300);
          gostop();
        }
        if(c == '5') // stop when receive 5
        { 
          gostop();
        }
      }      
    }
        //close server when receive 0
        if(c == '0')
        {
            client.stop();
            Serial.println("Client Disconnected.");
        }
      }
    }
    client.stop();
  }
