/*#include "colors.inc"


camera {
  location <0,1900,0>
  look_at <0,0,0>
}
 
background { LightSteelBlue }

light_source { <0,500,0> color White}


plane {
  y, 0   
  pigment { checker Green Black }
} 
*/

#local LargAv = 2068; //largura avenida
#local AltAv = 144; //altura avenida
#local AltCant = 42; //altura canteiro

#declare Avenida =
union{      
      //Avenida Topo
      box {
        <-LargAv/2, 0, 0+(AltCant/2)> <LargAv/2, 0.1, AltAv+(AltCant/2)>
      }
      //Canteiro
      box {
        <-LargAv/2, 0, -AltCant/2> <LargAv/2, 0.2, AltCant/2>
        pigment{ color Flesh }
      }
      //Avenida Baixo
      box {
        <-LargAv/2, 0, 0-(AltCant/2)> <LargAv/2, 0.1, -AltAv-(AltCant/2)>
      }
                  
         
  //pigment{ color Grey }
  //finish {phong 0.8 reflection 0.1}
}
 

   
//chamada
//object {Avenida} 