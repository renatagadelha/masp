/*
#include "colors.inc"
#include "textures.inc"
#include "stones.inc"
#include "Texturas.inc"
*/

#include "OBJ_Masp_Predio.inc" 

 /*
//camera { location <0,300,-1000> look_at <0,0,0>} //Frente Inclida para Topo/Direita
//camera { location <0,1,-1200> look_at <0,0,0>} //Frente   
camera { location <0,1200,0> look_at <0,0,0>} //topo
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
#local LM0 = 1000;  //largura quarterão do Masp
#local PM0 = 412;   //profundidade da area abaixo do Masp
#local LM1 = 750;   //largura da primeira parte do mirante
#local PM1 = 162;   //profundidade da primera parte do mirante
#local LM2 = 392;   //largura da segunda parte do mirante
#local PM2 = 162;   //profundidade da segunda parte do mirante  
#local AP = 30;     //altura da parede do mirante
#local LP = 1;      //largura da parede do mirante


#declare Muros = union {
  //M0
  difference{
    box {<-(LM0/2),0,-(PM0/2)><(LM0/2),AP,(PM0/2)>} 
    box {<(-LM0/2)+LP,0,(-PM0/2)-100><(LM0/2)-LP,AP+100,(PM0/2)>}
    box {<(-LM1/2)+LP,0,(-PM1/2)-100><(LM1/2)-LP,AP+100,(PM1/2)+200>}
  }

  //M1
  difference{
    box {<-(LM1/2),0,-(PM1/2)><(LM1/2),AP,(PM1/2)>}  
    box {<(-LM1/2)+LP,0,(-PM1/2)-100><(LM1/2)-LP,AP+100,(PM1/2)>}
    box {<(-LM2/2)+LP,0,(-PM2/2)-100><(LM2/2)-LP,AP+100,(PM2/2)+100>} 
    translate<0,0,(PM0/2)+(PM1/2)>
  }
  
  
  //M2
  difference{
    box {<-(LM2/2),0,-(PM2/2)><(LM2/2),AP,(PM2/2)>} 
    box {<(-LM2/2)+LP,0,(-PM2/2)-100><(LM2/2)-LP,AP+100,(PM2/2)>} 
    translate<0,0,(PM0/2)+PM1+(PM2/2)>
  }     
}

//Piso
#declare Piso = union {
  //M0
    box {<-(LM0/2),0,-(PM0/2)><(LM0/2),0.2,(PM0/2)>} 

  //M1
    box {<-(LM1/2),0,-(PM1/2)><(LM1/2),0.2,(PM1/2)> translate<0,0,(PM0/2)+(PM1/2)>}  

  //M2
    box {<-(LM2/2),0,-(PM2/2)><(LM2/2),0.2,(PM2/2)> translate<0,0,(PM0/2)+PM1+(PM2/2)>}     
     
} 


#local LE = 90;    //largura do espelho

#declare Espelho = merge {
  difference{
    box {<-(LE/2),0,-(PM0/2)><(LE/2),AP,(PM0/2)>} 
    box {<-(LE/2)+4,0,-(PM0/2)+4><(LE/2)-4,AP,(PM0/2)-4>}  
  }
  box {
    <-(LE/2)+1,0,-(PM0/2)+1><(LE/2)-1,AP,(PM0/2)-1>
    material{Water_Material}
  } 
}

   

#declare Mirante =
  union {
    object {Muros} 
    object {Piso}  
    
    object {
      Espelho
      translate<(-LM0/2)+(LE/2),0,-1>
    }
    
    object {
      Espelho
      translate<(LM0/2)-(LE/2),0,-1>
    }
    
    //pigment{Flesh}
    texture{T_Grnt13} 
  }

//chamada
//object {Mirante}