/*#include "colors.inc"
#include "shapes.inc"
#include "textures.inc"
#include "woods.inc"
#include "stones.inc"
#include "metals.inc"
#include "golds.inc"
#include "glass.inc"
#include "Texturas.inc"


//camera {location <0,500,-3000> look_at <0,500,0> }  

  camera {
  location <1000,400,-400>
  look_at <300,500,100> 
  
} 
 
background { LightSteelBlue}
 
light_source { <0,2000,-1000> color White}
light_source { <0,2000,1000> color White} 
light_source { <0,2000,-1000> color White}
light_source { <700,1500,0> color White}
light_source { <-700,1500,0> color White}


plane {
  y, 0   
  pigment { Green }
}
*/


//blocoprincipal
#declare blocoPrincipal = difference {

        box{ <0,0,0>,<276,1000,687>
                     texture{Concreto}
              
        }
             
         union {
                 box{ <38,5,-1>,<238,100,658>
                             texture{Concreto}
                      
                }
                 box{ <-1,5,10>,<277,998,658>
                             texture {Concreto}
                      
                }
        
        }

}
       
        
        
//vigas vertical
  
#declare vigaVertical =  box{ <0,100,0>,<10,1000,7>
                     texture{Concreto}
                     translate x*276
              
        }
#declare vigaVertical2 =  box{ <0,100,0>,<10,1000,7>
                     texture{Concreto}
                     translate x*-10
              
        }        
  //vigas horizontal
#declare vigaHorizontal =  box{ <0,100,0>,<5,104,687>
                     texture{Concreto}
                     translate x*276
              
        }
  //vigas horizontal2
#declare vigaHorizontal2 =  box{ <0,100,0>,<5,104,687>
                     texture{Concreto}
                     translate x*-5
              
        }
         
  
        
        
// janelas
#declare Janela =  box{ <0,108,10>,<3,132,34>
                     texture { Vicks_Bottle_Glass}
                     translate x*276
                    }
#declare Janela2 =  box{ <0,108,10>,<3,132,34>
                     texture { Vicks_Bottle_Glass}
                     translate x*-3
                    }
                    
                    
//ar-condicionado lateral 
                     
//predio
#declare X = 34;
#declare End_X = 34*20;
#declare X2 = 34;
#declare End_X2 = 34*20;
#declare Y = 180;
#declare End_Y = 200*5;
#declare Y2 = 180;
#declare End_Y2 = 200*5;
                     
#declare Predio2 = union {
        object {
           blocoPrincipal     
        }
        
        //vigas verticais
        object {
           vigaVertical
                
        }
        #while ( X <= End_X )
     object {
           vigaVertical
           translate <0,0,X>     
        }
    #declare X = X + 34; // next
    #end //-------------- end of loop ----
        
        //vigas verticais 2
        object {
           vigaVertical2
                
        }
        #while ( X2 <= End_X2 )
     object {
           vigaVertical2
           translate <0,0,X2>     
        }
    #declare X2 = X2 + 34; // next
    #end //-------------- end of loop ----
        
        
        
        
        //vigas horizontais
        object {
           vigaHorizontal     
        }
        
        #while ( Y <= End_Y )
             object {
                   vigaHorizontal
                   translate <0,Y,0>     
                }
             #declare Y = Y + 180; // next
        #end //-------------- end of loop ---- 
        
       //vigas horizontais2
       object {
           vigaHorizontal2     
        }
        
        #while ( Y2 <= End_Y2 )
             object {
                   vigaHorizontal2
                   translate <0,Y2,0>     
                }
             #declare Y2 = Y2 + 180; // next
        #end //-------------- end of loop ---- 
        
        //Janelas
        #declare y_janela = 4;
        #declare y_janela_end = 880;
        #declare y_janela2 = 4;
        #declare y_janela_end2 = 880;
        #declare j = 34;
        #declare i = 34;
        object {
           Janela     
        }
        
        #while ( y_janela <= y_janela_end )
             #declare i =34;
             
             #while ( i<=34*19 )
                object {
                   Janela
                   translate <0,y_janela,i>     
                }
              #declare i = i+34;   // next
             #end //-------------- end of loop ----
              
             
             object {
                   Janela
                   translate <0,y_janela,0>     
                }
             #declare y_janela = y_janela + 28; // next
        #end //-------------- end of loop ----
                                               
                                               
        //janelas2
        object {
           Janela2     
        }
        
        #while ( y_janela2 <= y_janela_end2 )
             #declare j =34;
             
             #while ( j<=34*19 )
                object {
                   Janela2
                   translate <0,y_janela2,j>     
                }
              #declare j = j+34;   // next
             #end //-------------- end of loop ----
              
             
             object {
                   Janela2
                   translate <0,y_janela2,0>     
                }
             #declare y_janela2 = y_janela2 + 28; // next
        #end //-------------- end of loop ----                                       
        

   }
                     
        
        
        
//===============================================================
//montando objeto


//object {Predio2}