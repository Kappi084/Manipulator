# include "Motion.h"
 // Diese Libary wurde speziell für das CNC-Shieled programmiert.


     ###.                     .##*                    .*=             
    =%%*                      *%%+                     ****-          
    #%%-           %%#        %%%:                      .=****-       
   :#%#           +%%*       =%%#                           +****:    
   +%%=     #%%+  #%%%%%%%*  *%%:     =#%%%%%%%#-              =****- 
   #%#    =%%#.  -%%#+++++- .%%#    *%%%#-..-#%%%#               .+***
  =%%*  :#%%=    *%%:       +%%=  :%%%-        %%%-         .-+******.
  %%%%%%%%#.     %%#        %%#.  #%%.         #%%:        -***+=     
 -%%%%%%%%%%#   +%%+       =%%#  -%%+         :%%#                    
 +%%=     %%#.  %%%:       *%%:  -%%*         *%%+                    
 #%#     -%%*  :%%%-.     :%%#   .#%%#:   .+#-#%%.                    
=%%+     %%%-   *%%%%%%#  +%%-     *%%%%%%%%*=%%*                     
                        


void setup() {
  //Dies ermöglicht ein milimetergenaues Ansteuern der Motoren
  Station1_Servo.init(0, 10, 0); //(Grade offen (Greifer), Grade gescholssen (Greifer), Grade Null Dreheinheit)
}

void loop() {
  //mit diesem Befehl kann man einfach mit den Worten open oder closed den Greifer öffnen oder schließen
  //(der Servomotor fährt die vorhin bestimmten Positionen an (XXX.init))
  Station1_Servo.motion("close", 0); //("close" or "open", Winkel der Dreheinheit)
  delay(1000);
  Station1_Servo.motion("open", 0);
  delay(1000);
  Station1_Servo.motion("open", 180);
  delay(1000);
  Station1_Servo.motion("open", 0);
  delay(1000);
  Station1_Servo.motion("close", 0);
  delay(1000);  
}

