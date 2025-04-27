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
  // Wie die Kalibrierung Schritt für Schritt gemacht wird wird im Github genauer erklärt.
  Station1_CoreXY.init(4, 4, 4);  // Hier wird der Wert nach dem Kalibrieren eingetragen(der Multiplikator)
}

void loop() {
  // mit dem Befehl XXX.motion fährt der Manipulator auf die eingegebenen X, Y, Z Werte (in mm vom 0 punkt entfernt)
  Station1_CoreXY.motion(100, 0, 0, 3000); //(X-Wert, Y-Wert, Z-Wert, Speed)
  delay(1000);
  Station1_CoreXY.motion(100, 100, 0, 3000);
  delay(1000);
  Station1_CoreXY.motion(0, 100, 0, 3000);
  delay(1000);
  Station1_CoreXY.motion(0, 0, 0, 3000);
  delay(1000);
  //Z-ACHSE fährt nach oben und wieder nach unten
  Station1_CoreXY.motion(0, 0, 100, 3000);
  delay(1000);
  Station1_CoreXY.motion(0, 0, 0, 3000);
  delay(1000);

}
