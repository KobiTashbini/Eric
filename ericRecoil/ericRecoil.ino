int data;  
void setup() {  
    Serial.begin(9600);  
    
    pinMode(2, OUTPUT);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
    pinMode(5, OUTPUT);
    pinMode(6, OUTPUT);
    pinMode(7, OUTPUT); 
     pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);
    pinMode(13, OUTPUT); 
}  
void loop() {  
    if (Serial.available()) {  
        data = Serial.read();  
        if (data == 'A') {  
            digitalWrite(2, HIGH);
         
        } else if(data == 'a'){  
         digitalWrite(2, LOW);  
       
        }  
         else if (data == 'B') {  
            digitalWrite(3, HIGH);
       
        } else if(data == 'b'){  
         digitalWrite(3, LOW);  
    
        }  
          else if (data == 'C') {  
            digitalWrite(4, HIGH);
       
        } else if(data == 'c'){  
         digitalWrite(4, LOW);  
    
        }  
         else if (data == 'D') {  
            digitalWrite(5, HIGH);
       
        } else if(data == 'd'){  
         digitalWrite(5, LOW);  
    
        }  
         else if (data == 'E') {  
            digitalWrite(6, HIGH);
       
        } else if(data == 'e'){  
         digitalWrite(6, LOW);  
    
        }  
         else if (data == 'F') {  
            digitalWrite(7, HIGH);
       
        } else if(data == 'f'){  
         digitalWrite(7, LOW);  
    
        }  
        else if (data == 'G') {  
            digitalWrite(8, HIGH);
       
        } else if(data == 'g'){  
         digitalWrite(8, LOW);  
    
        }
          else if (data == 'H') {  
            digitalWrite(9, HIGH);
       
        } else if(data == 'h'){  
         digitalWrite(9, LOW);  
    
        } 
          else if (data == 'I') {  
            digitalWrite(10, HIGH);
       
        } else if(data == 'i'){  
         digitalWrite(10, LOW);  
    
        } 
          else if (data == 'J') {  
            digitalWrite(11, HIGH);
       
        } else if(data == 'j'){  
         digitalWrite(11, LOW);  
    
        } 
          else if (data == 'J') {  
            digitalWrite(12, HIGH);
       
        } else if(data == 'j'){  
         digitalWrite(12, LOW);  
    
        } 
          else if (data == 'K') {  
            digitalWrite(13, HIGH);
       
        } else if(data == 'k'){  
         digitalWrite(13, LOW);  
    
        }   
        else
        {
          
        }
    }  
}  
