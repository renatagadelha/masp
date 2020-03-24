global_settings{ assumed_gamma 1.0 }
#default{ finish{ ambient 0.1 diffuse 0.9 }}

#include "colors.inc"
#include "shapes.inc"
#include "textures.inc"
#include "woods.inc"
#include "stones.inc"
#include "metals.inc"
#include "golds.inc"
#include "glass.inc"
#include "Texturas.inc"

#include "OBJ_Masp.inc" 
#include "OBJ_Avenida.inc"
#include "OBJ_Predio2.inc"
#include "OBJ_predio.inc"


light_source { <0,3000,-1000> color White}
//light_source { <0,3000,1000> color White}

//light_source { <0,100,200> color White} //Feirinha 

camera { location <500,500,-1000> look_at <0,0,0>} //Frente Inclinada para Topo/Direita
//camera { location <-500,500,-1000> look_at <0,0,0>} //Frente Inclinada para Topo/Esquerda
//camera { location <0,1,-1600> look_at <0,0,0>} //Frente
//camera { location <0,800,-1600> look_at <0,0,0>} //Frente Inclinada para Baixo 
 
//camera { location <0,1800,-200> look_at <0,0,-200>} //Topo
//camera { location <0,1,1000> look_at <0,0,0>} //Atrás 

//camera { location <0,1,-1200> look_at <0,0,0>} //Frente Masp
//camera { location <0,100,-500> look_at <0,0,0>} //Frente Masp - Feirinha 

//camera { location <0,80,-200> look_at <0,80,-1000>} //Frente - Olhando o parque
 

// sky ---------------------------
plane{<0,1,0>,1 hollow
       texture{
        pigment{ bozo turbulence 0.92
          color_map {
           [0.00 rgb <0.2, 0.3, 1>*0.5]
           [0.50 rgb <0.2, 0.3, 1>*0.8]
           [0.70 rgb <1,1,1>]
           [0.85 rgb <0.25,0.25,0.25>]
           [1.0 rgb <0.5,0.5,0.5>]}
          scale<1,1,1.5>*2.5
          translate<1.0,0,-1>
          }// end of pigment
          #if (version = 3.7 )  finish {emission 1 diffuse 0}
          #else                 finish { ambient 1 diffuse 0}
          #end 
        }// end of texture
        scale 10000
     }// end of plane

// fog on the ground -------------------------------------------------
/*fog { fog_type   2
      distance   50
      color      White  
      fog_offset 0.1
      fog_alt    1.5
      turbulence 1.8
    } */

// ground ------------------------------------------------------------
plane { <0,1,0>, 0 
        texture{ 
        pigment{color rgb<0.35,0.65,0.0>*0.8} //verde
        //pigment{color rgb<0.5,0.5,0.5>*0.3} //cinza
                 normal {bumps 0.75 scale 0.015}
                 finish {ambient 0.1 diffuse 0.8}
               } // end of texture
      } // end of plane
 
 
 
 
//Avenida
object {
  Avenida   
  translate<0,0,-595>
  texture{Street_Texture}
}


//Masp   
object {
  Masp
}


//predio 1
object {
  predio
  translate<620,0,-300>
}

//predio2
object {
  Predio2
  translate<-900,5,-200> 
}


//---------------------------------------------------------------------------------------
//---------------------------------------------------------------------------------------
#include "EXT_Tree_00.inc" // include type of tree
//#include "Tree_10.inc" // include type of tree
//-------------------------------------------------------------------------------------// 
#include "EXT_Random_Planting_000.inc" 
//-------------------------------------------------------------------------------------// 
object{ Random_Planting_000( object{ Tree_00}, //  Object_to_Plant, //                                   
                              6, // Number_in_X, // number of objects in x direction
                              4, // Number_in_Z, // number of objects in z direction
                             2.75, // Base_Distance_X, //
                             2.75, // Base_Distance_Z, // 
                             10,   // Base_Tilt_Angel, // degrees
                             1.00, // Tilt_Angel_Ramdom_Factor, // 
                             1.00, // Base_Object_Scale, // ~ 1
                             0.350, // Object_Scale_Ramdom_Factor, // ~ 0.5
                             // integers 0 ~ 65536
                             6332, // Seed_0, // Ramdom seed for tilt on x-axis 
                             1153, // Seed_1, // Ramdom seed for rotating around y-axis
                             1642, // Seed_2, // Ramdom seed for scaling
                             2655  // Seed_3, // Ramdom seed for moving in x and z
                           ) //--------------------------------------------------------//
        scale <50,50,50>*1
        rotate<0,0,0> 
        translate< -400,0.00, -1400>}
//-------------------------------------------------------------------------------------//
//---------------------------------------------------------------------------------------

       



