#include "colors.inc"
#include "textures.inc"

/*  
//camera { location <500,500,-1000> look_at <0,0,0>} //Frente Inclida para Topo/Direita
//camera { location <0,1,-6> look_at <0,0,0>} //Frente
//camera { location <0,11,0> look_at <0,0,0>} //topo
camera { location <0,3,6> look_at <0,0,0>} //Atrás
//camera { location <6,1,0> look_at <0,0,0>} //Lado
 
background { LightSteelBlue }

light_source { <500,1000,-500> color White}     

light_source { <-500,1000,500> color White} 


plane {
  y, 0   
  pigment { checker Green Black }
}                                           
*/                                          

light_source { <0,1,0> color White} //dentro barraca

#local A = 2;   //Altura da barraca
#local L = 2;     //Largura da barraca
#local P = 2;     //Profundidade da barraca
#local R = 0.03;  //Raio das barras
#local AB = 1;    //Altura da base
#local AT = 0.4;   //Altura do topo

#declare TopoSolido =                                 
  merge {
    prism { 
    
      linear_sweep
      linear_spline
      0, // sweep the following shape from here ...
      P+0.05, // ... up through here
      4, // the number of points making up the shape ...
      <(-L/2),0>, <(L/2),0>, <0,AT>, <(-L/2),0>
      rotate <-90, 0, 0>
      translate <0, A, (P+0.05)/2>   
      /*
      cubic_spline
      0, //comeca aqui
      P+0.05, //largura
      6, // numero de pontos
      <0.2,-0.2>, //ponto de controle (nao aparece)
      <(-L/2),0>, 
      <(L/2),0>,
      <0,AT>, 
      <(-L/2),0>, //tem que fechar com o ponto inicial
      <0,-0.2> //ponto de controle (nao aparece)   
      rotate <-90, 0, 0>
      translate <0, A, (P+0.05)/2> */ 
    }
    
    box {<(-L/2)-0.025,A-0.2,(-P/2)-0.025> <(L/2)+0.025,A,(P/2)+0.025>} 
  }
  
#declare Topo =
  difference {
    object { 
      TopoSolido 
    }
    
    object { 
      TopoSolido
      scale <0.9,0.9,0.9> 
    }
    box {<(-L/2),A-1,(-P/2)> <(L/2),A,(P/2)>} 
  
  }
                                 
                                 
#declare Barras =
  merge {
  cylinder{<0,0,0>,<0,A,0>, R
           translate<(-L/2)+R,0,-(P/2)+R>} //frente 1
  cylinder{<0,0,0>,<0,A,0>, R
           translate<(L/2)-R,0,-(P/2)+R>} //frente 2
  cylinder{<0,0,0>,<0,A,0>, R
           translate<(-L/2)+R,0,(P/2)-R>} //atras 1
  cylinder{<0,0,0>,<0,A,0>, R
           translate<(L/2)-R,0,(P/2)-R>} //atras 2
  }     
  
#declare Base =
  box {<(-L/2),0,(-P/2)> <(L/2),AB,(P/2)>} 
                                                            
                                                                  
  
#declare Barraca = 
union { 

    object {
      Topo 
        pigment{ color White }
        finish { diffuse 0.8 specular 0.2 } 
    }  

    object {
      Barras
        texture {Silver2} 
        //pigment{ color Grey } 
    }   
    
    object {
      Base 
        pigment{ color Blue } 
        finish { diffuse 0.8 specular 0.2 }
    }
     
}

//chamada
//object {Barraca}   