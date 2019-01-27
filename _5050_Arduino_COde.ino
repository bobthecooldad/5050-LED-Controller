// RGB Controller
     
    #define redpin_strip_1 13
    #define greenpin_strip_1 12
    #define bluepin_strip_1 11
    
    #define redpin_strip_2 10
    #define greenpin_strip_2 9
    #define bluepin_strip_2 8
     
    #define redpin_strip_3 7
    #define greenpin_strip_3 6
    #define bluepin_strip_3 5    

    #define redpin_strip_4 4
    #define greenpin_strip_4 3
    #define bluepin_strip_4 2

    #define switch_input_1 14 // Select What Strip To control
    #define switch_input_2 15 // To change Cycle Speed
    #define switch_input_3 16 // Turn Off Red
    #define switch_input_4 17 // Turn Off Blue
    #define switch_input_5 18 // Turn Off Green
    #define switch_input_6 19 // MISC <--- Unpopulated
    

    unsigned long previous_time = 0 ;// Using Millis instead of delay <-- this will be used to store the time that the led last turned on
    unsigned long previous_time_2 = 0 ; 
    unsigned long previous_time_3 = 0 ;
    unsigned long previous_time_4 = 0 ;
    unsigned long previous_time_5 = 0 ; 
    unsigned long previous_time_6 = 0 ;

    unsigned long previous_time_blue_false = 0 ;
    unsigned long previous_time_1_blue_false = 0 ;
    unsigned long previous_time_2_blue_false = 0 ;
    unsigned long previous_time_3_blue_false = 0 ;

    unsigned long previous_time_red_false = 0 ;
    unsigned long previous_time_1_red_false = 0 ;
    unsigned long previous_time_2_red_false = 0 ;
    unsigned long previous_time_3_red_false = 0 ;
    
    unsigned long previous_time_green_false = 0 ;
    unsigned long previous_time_1_green_false = 0 ;
    unsigned long previous_time_2_green_false = 0 ;
    unsigned long previous_time_3_green_false = 0 ;

    unsigned long previous_time_led_flash = 0 ;// Using Millis instead of delay <-- this will be used to store the time that the led last turned on
    unsigned long previous_time_led_flash_2 = 0 ; 
    unsigned long previous_time_led_flash_3 = 0 ;
    unsigned long previous_time_led_flash_4 = 0 ;
    unsigned long previous_time_led_flash_5 = 0 ; 
    unsigned long previous_time_led_flash_6 = 0 ;
    
    unsigned long current_time = 0;
    
    unsigned long previous_time_button_check_1 = 0; // Disables multiple presses down to 1 in a given time
    unsigned long previous_time_button_check_2 = 0;
    unsigned long previous_time_button_check_3 = 0;
    unsigned long previous_time_button_check_4 = 0;

    unsigned long previous_time_led_flash_duration = 0;
    unsigned long previous_time_led_script = 0;

    int delay_of_button_press = 2000; //How long until another press is allowed
    
    int cycle_time = 1000 ; 
    int cycle_time_1 = 1000 ;
    int cycle_time_2 = 1000 ;
    int cycle_time_3 = 1000 ;
    int cycle_time_4 = 1000 ;
    int cycle_time_5 = 1000 ; 
    
    int cycle_time_1_led = 0;
    int cycle_time_2_led = 0;
    int cycle_time_3_led = 0;
    int cycle_time_4_led = 0;
    int cycle_time_5_led = 0;
    int cycle_time_6_led = 0;

    int cycle_time_led_flash = 1000;
    
    int red_wanted = true ;
    int green_wanted = true ;
    int blue_wanted =  true ;

    bool red_output = redpin_strip_1 ;
    bool green_output = greenpin_strip_1 ;
    bool blue_output = bluepin_strip_1 ;
    
    int strip_count_flash = 1 ;
    int strip_count = 0;

    int blue_wanted_strip_1 = true;
    int blue_wanted_strip_2 = true;
    int blue_wanted_strip_3 = true;
    int blue_wanted_strip_4 = true;

    int green_wanted_strip_1 = true;
    int green_wanted_strip_2 = true;
    int green_wanted_strip_3 = true;
    int green_wanted_strip_4 = true;

    int red_wanted_strip_1 = true;
    int red_wanted_strip_2 = true;
    int red_wanted_strip_3 = true;
    int red_wanted_strip_4 = true;
  
    int switch_input_1_counter = 0 ;
    int switch_input_2_counter = 0 ;
    int switch_input_3_counter = 0 ;
    int switch_input_4_counter = 0 ;
    int switch_input_5_counter = 0 ;
    int switch_input_6_counter = 0 ;

    int strip_to_be_edited = 0;
    int strip_count_switch = 0;
    
    int switch_1_loop_check = 0;
    int switch_2_loop_check = 0;   
    int switch_3_loop_check = 0;
    int switch_4_loop_check = 0;   
    int switch_5_loop_check = 0;
    int switch_6_loop_check = 0;    
    
    int switch_1_input_loop_check = 0;
    int switch_2_input_loop_check = 0;
    int switch_3_input_loop_check = 0;
    int switch_4_input_loop_check = 0;
    int switch_5_input_loop_check = 0;
    int switch_6_input_loop_check = 0;

    int run_1_check = 0;
    int run_2_check = 0;
    int run_3_check = 0;
    int run_4_check = 0;
    int run_5_check = 0;
    int run_6_check = 0;
    
    
 
       
  void led_script_effect(bool red_wanted, bool green_wanted , bool blue_wanted, int cycle_time_1_led , int cycle_time_2_led, int cycle_time_3_led, int cycle_time_4_led, int cycle_time_5_led, int cycle_time_6_led){
    int r,g,b ; 
    unsigned long current_time = (millis ()) ;
    

    if(red_wanted == true && green_wanted == true && blue_wanted == true){
    
       // fade from blue to violet
      if (current_time - previous_time >= cycle_time_1_led && run_1_check == 0){
        for (int r = 0; r < 256; r++) { 
            analogWrite(redpin_strip_1, r);
          previous_time = current_time; // <-- Store Current Time
          run_1_check = 1;
          Serial.println("red is outputting : ");
          Serial.println (r); 
          Serial.println(redpin_strip_1);
        }
      }    

      if (current_time - previous_time_2 >= cycle_time_2_led && run_2_check == 0){ 
      
      // fade from violet to red
        for (b = 255; b > 0; b--) { 
          analogWrite(bluepin_strip_1, b);
          previous_time_2 = current_time ;
          run_2_check = 1;
        } 
      }
      if (current_time - previous_time_3 >= cycle_time_3_led && run_3_check == 0){
      
      // fade from red to yellow
        for (g = 0; g < 256; g++) { 
          analogWrite(greenpin_strip_1, g);
          previous_time_3 = current_time ;
          run_3_check = 1;
        } 
      }
      
      if (current_time - previous_time_4 >= cycle_time_4_led && run_4_check == 0){
      // fade from yellow to green
        for (r = 255; r > 0; r--) { 
          analogWrite(redpin_strip_1, r);
          previous_time_4 = current_time;
          run_4_check = 1;
        }
      } 

      if (current_time - previous_time_5 >= cycle_time_5_led && run_5_check == 0){
        // fade from green to teal
        for (b = 0; b < 256; b++) { 
          analogWrite(bluepin_strip_1, b);
          previous_time_5 = current_time;
          run_5_check = 1;
        }  
      } 
      if (current_time - previous_time_6 >= cycle_time_6_led && run_6_check == 0){
        // fade from teal to blue
        for (g = 255; g > 0; g--) { 
          analogWrite(greenpin_strip_1, g);
          previous_time_6 = current_time;
          run_6_check = 1;
          
        }
      }
    }
  
  
  if(red_wanted == true && green_wanted == true && blue_wanted == false){
      
       // fade from blue to violet
      if (current_time - previous_time >= cycle_time){
        for (r = 0; r < 256; r++) { 
          analogWrite(redpin_strip_1, r);
          previous_time_blue_false = current_time; // <-- Store Current Time
        }
      }    

      if (current_time - previous_time_3 >= cycle_time_2){
      
      // fade from red to yellow
        for (g = 0; g < 256; g++) { 
          analogWrite(greenpin_strip_1, g);
          previous_time_1_blue_false = current_time ;
        } 
      }
      
      if (current_time - previous_time_4 >= cycle_time_3){
      // fade from yellow to green
        for (r = 255; r > 0; r--) { 
          analogWrite(redpin_strip_1, r);
          previous_time_2_blue_false = current_time;
        }
      } 

      } 
      if (current_time - previous_time_6 >= cycle_time_5){
        // fade from teal to blue
        for (g = 255; g > 0; g--) { 
          analogWrite(greenpin_strip_1, g);
          previous_time_3_blue_false = current_time;
          
        }
      }
    }
          

    void led_flash(){
      
    unsigned long current_time = (millis ()) ;   
   
    Serial.println("led_flash"); // Lets me know if i have gone into flash
    Serial.println("Strip Count Switch");
    Serial.println(strip_count_switch);
    //Serial.println("Previous Time Led Flash");
    //Serial.println(previous_time_led_flash);   
    //Serial.println("Time to Flash");
    //Serial.println(cycle_time_led_flash);
    //Serial.println("current time");
    //Serial.println(current_time);
       
    if (strip_count_switch == 1 && current_time - previous_time_led_flash >= cycle_time_led_flash){// This will set the output when run multiple times, Should allow multiple process :)
      red_output == redpin_strip_1 ;
      green_output == greenpin_strip_1 ; 
      blue_output == bluepin_strip_1 ;
      Serial.println("Led Flash First If Command");
      previous_time_led_flash = current_time;
    }
       
    if (strip_count_switch == 2 && current_time - previous_time_led_flash >= cycle_time_led_flash){// This will set the output when run multiple times, Should allow multiple process :)
      red_output == redpin_strip_2 ;
      green_output == greenpin_strip_2 ; 
      blue_output == bluepin_strip_2 ; 
      Serial.println("Led Flash Secound If Command");
      previous_time_led_flash = current_time;

    }
    if (strip_count_switch == 3 && current_time - previous_time_led_flash >= cycle_time_led_flash){// This will set the output when run multiple times, Should allow multiple process :)
      red_output == redpin_strip_3 ;
      green_output == greenpin_strip_3 ; 
      blue_output == bluepin_strip_3 ; 
      Serial.println("Led Flash third If Command");
      previous_time_led_flash = current_time;

    }
    if (strip_count_switch == 4 && current_time - previous_time_led_flash >= cycle_time_led_flash){// This will set the output when run multiple times, Should allow multiple process :)
      red_output == redpin_strip_4 ;
      green_output == greenpin_strip_4 ; 
      blue_output == bluepin_strip_4 ;   
      Serial.println("Led Flash Forth If Command");
      previous_time_led_flash = current_time;    

    }   

    digitalWrite(red_output, HIGH);
    digitalWrite(blue_output, HIGH);
    digitalWrite(green_output, HIGH);
    if (current_time - previous_time_led_flash_duration >= cycle_time_led_flash) { // <---------- Will pause all lights would be better if only turned off 1/ paused 1 commands whilst pulsing
      digitalWrite(red_output, LOW);
      digitalWrite(blue_output, LOW);
      digitalWrite(green_output, LOW);    
    }    
   }
    
    
    void setup() {
      
      pinMode(redpin_strip_1, OUTPUT);
      pinMode(greenpin_strip_1, OUTPUT);
      pinMode(bluepin_strip_1, OUTPUT);
      
      pinMode(redpin_strip_2, OUTPUT);
      pinMode(greenpin_strip_2, OUTPUT);
      pinMode(bluepin_strip_2, OUTPUT);

      pinMode(redpin_strip_3, OUTPUT);
      pinMode(greenpin_strip_3, OUTPUT);
      pinMode(bluepin_strip_3, OUTPUT);
      
      pinMode(redpin_strip_4, OUTPUT);
      pinMode(greenpin_strip_4, OUTPUT);
      pinMode(bluepin_strip_4, OUTPUT);

      pinMode(switch_input_1 , INPUT);
      pinMode(switch_input_2 , INPUT);
      pinMode(switch_input_3 , INPUT);
      pinMode(switch_input_4 , INPUT);
      pinMode(switch_input_5 , INPUT);
      pinMode(switch_input_6 , INPUT);

      Serial.begin(9600); 
      
    }

    void loop() {
          
      unsigned long current_time = (millis ()) ; 

      int cycle_time_1 = cycle_time + cycle_time;
      int cycle_time_2 = cycle_time + cycle_time_1;
      int cycle_time_3 = cycle_time + cycle_time_2;
      int cycle_time_4 = cycle_time + cycle_time_3;
      int cycle_time_5 = cycle_time + cycle_time_4;
      int cycle_time_6 = cycle_time + cycle_time_5;
      int cycle_total_time = cycle_time + cycle_time_1 + cycle_time_2 + cycle_time_3 + cycle_time_4 + cycle_time_5 + cycle_time_6;
      
      switch_1_loop_check == 0;
      switch_2_loop_check == 0;
      switch_3_loop_check == 0;
      switch_4_loop_check == 0;      
      switch_5_loop_check == 0;
      switch_6_loop_check == 0; // Unpopulated

      run_1_check == 0;
      run_2_check == 0;
      run_3_check == 0;
      run_4_check == 0;
      run_5_check == 0;
      run_6_check == 0;
     
      
      //Serial.print("Cycle 1 time:  ");
      //Serial.println(cycle_time_1);
      //Serial.print("Cycle 2 time:  ");
      //Serial.println(cycle_time_2);
      //Serial.print("Cycle 3 time:  ");
      //Serial.println(cycle_time_3);
      //Serial.print("Cycle 4 time:  ");
      //Serial.println(cycle_time_4);
      //Serial.println("Cycle 5 time:  ");
      //Serial.println(cycle_time_5)      
      
   
      int switch_input_voltage = analogRead(switch_input_1); 
      
      if (switch_input_voltage >= 1023 && current_time - previous_time_button_check_1 >= delay_of_button_press){// To control which strip to speed up or disable Color <--- Will be a TBA feature.
        //Serial.println("Switch 1 has been triggered");
        //Serial.println(switch_input_1);
        previous_time_button_check_1 = current_time ; 
        switch_input_1_counter = (switch_input_1_counter + 1) ;
        
        if (switch_input_1_counter <= 5 && switch_1_loop_check == 0){
          switch_input_1_counter = (switch_input_1_counter + 1);
          switch_1_loop_check = 1;
        }
        
        if (switch_input_1_counter >= 5 && switch_1_loop_check == 0){
          switch_1_loop_check = 1;
          switch_input_1_counter =  (0);
        }
          
        //Serial.println("input_switch_1_counter = ");
        //Serial.println(switch_input_1_counter);
        
        if (switch_input_1_counter == 1 && switch_1_input_loop_check == 0){
          strip_to_be_edited = 1;
          strip_count_switch = strip_to_be_edited;
          led_flash();
          Serial.println("Loop First if on Led Flash");
          switch_1_input_loop_check == 1;
        }
        if (switch_input_1_counter == 2 && switch_1_input_loop_check == 0){
          strip_to_be_edited = 2;
          strip_count_switch = strip_to_be_edited;
          led_flash();
          Serial.println("Loop secound if on Led Flash");
          switch_1_input_loop_check == 1;
        }
        
        if (switch_input_1_counter == 3 && switch_1_input_loop_check == 0){
          strip_to_be_edited = 3;
          strip_count_switch = strip_to_be_edited;
          led_flash();
          Serial.println("Loop third if on Led Flash");
          switch_1_input_loop_check == 1;   
        }    
        
        if (switch_input_1_counter == 4 && switch_1_input_loop_check == 0){
          strip_to_be_edited = 4;
          strip_count_switch = strip_to_be_edited;
          led_flash();
          Serial.println("Loop Forth if on Led Flash");
          switch_input_1_counter = 0;  
          switch_1_input_loop_check == 1;
                    
        }
      } 
      
      
      
      int switch_input_2_voltage = analogRead(switch_input_2); // To change the Cycle Speed
      
      if (switch_input_2_voltage >= 1023 && current_time - previous_time_button_check_2 >= delay_of_button_press){

        Serial.println("Secound Switch Trigger");
        Serial.println(switch_input_2_counter);
        Serial.println(switch_2_loop_check);
        previous_time_button_check_2 = current_time ; 
        switch_input_2_counter = (switch_input_2_counter + 1) ;
        
        if (switch_input_2_counter <= 5 && switch_2_loop_check == 0){ // Need to decide how many steps
          switch_input_2_counter = (switch_input_2_counter + 1);
          switch_2_loop_check = 1;
        }
        
        if (switch_input_2_counter > 5){
          switch_2_loop_check = 1;
          switch_input_2_counter = 0;
        }
          
        //Serial.println("input_switch_1_counter = ");
        //Serial.println(switch_input_1_counter);
        
        if (switch_input_2_counter == 1 && switch_2_input_loop_check == 0){ // Reset to default
          cycle_time = 1000;
          Serial.println("Loop First speed 1000");
          switch_2_input_loop_check == 1;
        }
        if (switch_input_2_counter == 2 && switch_2_input_loop_check == 0){ // 2 Secounds
          cycle_time = 2000;
          Serial.println("Loop speed 2000");
          switch_2_input_loop_check == 1;
        }
        if (switch_input_2_counter == 3 && switch_2_input_loop_check == 0){ // 3 Secounds
          cycle_time = 3000;
          Serial.println("Loop speed 3000");
          switch_2_input_loop_check == 1;
        }
        if (switch_input_2_counter == 4 && switch_2_input_loop_check == 0){ // 4 Secounds
          cycle_time = 4000;
          Serial.println("Loop speed 4000");
          switch_2_input_loop_check == 1;
        }
        if (switch_input_2_counter == 5 && switch_2_input_loop_check == 0){ // 5 Secounds
          cycle_time = 5000;
          Serial.println("Loop speed 5000");
          switch_2_input_loop_check == 1;
        }
                                              
        }

      if (current_time - previous_time_led_script >= cycle_total_time){      
        led_script_effect(red_wanted = red_wanted_strip_1, green_wanted = green_wanted_strip_1, blue_wanted = blue_wanted_strip_1,cycle_time_1_led = cycle_time_1, cycle_time_2_led = cycle_time_2, cycle_time_3_led = cycle_time_3 ,cycle_time_4_led = cycle_time_4, cycle_time_5_led = cycle_time_5 ,cycle_time_6_led = cycle_time_6 );// Call first Led Strip <-- Has to be at the end for all the settings to work :)
        led_script_effect(red_wanted = red_wanted_strip_2, green_wanted = green_wanted_strip_2, blue_wanted = blue_wanted_strip_2,cycle_time_1_led = cycle_time_1, cycle_time_2_led = cycle_time_2, cycle_time_3_led = cycle_time_3 ,cycle_time_4_led = cycle_time_4, cycle_time_5_led = cycle_time_5 ,cycle_time_6_led = cycle_time_6 );
        led_script_effect(red_wanted = red_wanted_strip_3, green_wanted = green_wanted_strip_3, blue_wanted = blue_wanted_strip_3,cycle_time_1_led = cycle_time_1, cycle_time_2_led = cycle_time_2, cycle_time_3_led = cycle_time_3 ,cycle_time_4_led = cycle_time_4, cycle_time_5_led = cycle_time_5 ,cycle_time_6_led = cycle_time_6 );
        led_script_effect(red_wanted = red_wanted_strip_4, green_wanted = green_wanted_strip_4, blue_wanted = blue_wanted_strip_4,cycle_time_1_led = cycle_time_1, cycle_time_2_led = cycle_time_2, cycle_time_3_led = cycle_time_3 ,cycle_time_4_led = cycle_time_4, cycle_time_5_led = cycle_time_5 ,cycle_time_6_led = cycle_time_6 );
        previous_time_led_script = current_time;
      }
      } 
