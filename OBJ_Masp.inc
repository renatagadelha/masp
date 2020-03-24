/*
#include "colors.inc"
#include "stones.inc"
#include "_Texturas.inc"
*/

#include "OBJ_Mirante.inc"
#include "OBJ_Masp_Predio.inc" 
#include "OBJ_Barraca.inc"
/*
camera { location <500,500,-1000> look_at <0,0,0>} //Frente Inclida para Topo/Direita
//camera { location <0,1,-1200> look_at <0,0,0>} //Frente   
//camera { location <0,1200,0> look_at <0,0,0>} //topo
//camera { location <0,1,1000> look_at <0,0,0>} //Atrás
//camera { location <0,500,1000> look_at <0,0,0>} //Atrás  Inclinada para o Topo 

//camera { location <0,100,-1000> look_at <0,0,0>} //Frente barraquinhas
//camera { location <0,150, 600> look_at <0,0,0>} //Atras barraquinhas
//camera { location <-700,100,-200> look_at <0,0,-200>} //Lateral barraquinhas 
//camera { location <0,500,-200> look_at <0,0,-200>} //Topo barraquinhas - precisa retirar o Masp
 
background { LightSteelBlue }

light_source { <0,500,-1000> color White} 
light_source { <0,500,1000> color White}

light_source { <0,100,-1000> color White} 
light_source { <0,100,1000> color White}


plane {
  y, 0   
  pigment { checker Green Black }
} 
*/

#declare Base =
polygon {
  8,
  <-500,0.1,-437>, <500,0.1,-437>,  //base
  <500,0.1,0>, <420,0.1,146>, //direita
  <80,0.1,437>, <-90,0.1,437>, //topo
  <-432,0.1,209>,<-500,0.1,89>  //esquerda
  //pigment{ color Flesh }
  texture{T_Stone19} 
} 

#declare Barracas = 
union {
    #declare X = 0;  // start
    #declare End_X = 50; // end
    #while ( X <= End_X )
     object{ Barraca translate < X, 0, 0> }  //fila 1
     object{ Barraca translate < X, 0, -4> } //fila 2
     
     object{ Barraca translate < X, 0, -12> } //fila 3
     object{ Barraca translate < X, 0, -16> } //fila 4
    #declare X = X + 5; // next
    #end //-------------- end of loop ----
}


#declare Masp = 
union { 
    //Rua
    object {
      Base 
        scale <1.2,0,1.2>
        texture{Street_Texture}
        //pigment{ color Grey }
        translate<0,-0.01,0>   
      
    }
    //calçada Masp
    object {
      Base
    }

    //Marcação Calçada 
    object {Base}

    object {
      Mirante
      translate<0,0,-230> 
    }
         
    //Prédio Masp
    object {
      Predio
      //scale <0.9,0.9,0.9>
      translate<0,0,-200> 
    }
    
    object {
      Barracas
      scale<15,15,15>
      translate<-380,10,-70>  
    }  
}

  
//chamada
//object {Masp} 