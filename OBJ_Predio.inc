/*#include "colors.inc"
#include "shapes.inc"
#include "textures.inc"
#include "woods.inc"
#include "stones.inc"
#include "metals.inc"
#include "golds.inc"
#include "glass.inc"
#include "Texturas.inc"

camera {
  location <-1000,500,-700>
  look_at <0,500,0> 
  
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

//TEXTURE 


#declare blocoPrincipal = difference {

        union{
        box{ <0,0,0>,<300,700,452>
                     texture {Concrete1}
              
        }
        box{ <50,700,26>,<250,1000,426>
                     texture {Concrete1}
              
        }}
             
         union {
                 box{ <50,25,-1>,<250,100,420>
                             texture {Concrete1}
                      
                }
                 box{ <-1,25,10>,<301,690,420>
                             texture {Concrete1}
                      
                }
                
                box{ <55,705,231>,<245,995,421>
                     texture {Concrete1}
              
                }
        
        }

}     
        
        
//vigas vertical
  
#declare vigaVertical =  box{ <-10,100,0>,<310,700,7>
                     texture {Concrete1}
                     
              
        }
#declare vigaVertical2 =  box{ <0 ,100,-7>,<10,700,459>
                    texture {Concrete1}
                      }
////viga vertical parte de cima                     

#declare vigaV =  box{ <40,700,0>,<260,1000,7>
                     texture {Concrete1}
                     
              
        }


#declare vigaV2 =  box{ <145 ,700,22>,<155,1000,429>
                     texture {Concrete1}
                      }


 
                     

//vigas horizontal
#declare vigaHorizontal =  box{ <-5,100,-4>,<305,104,458>
                     texture {Concrete1}
                     
              
        }
        
//viga horizontal parte de cima
#declare vigaH =  box{ <45,996,22>,<255,1000,429>
                     texture {Concrete1}
                     
              
        }
        
        
//janelas

#declare Janela =  box{ <-3,108,10>,<303,190,220>
                     texture{Green_Glass}
                     
                    }
#declare Janela2 =  box{ <10,108,-3>,<140,190,455>
                     texture{Green_Glass}
                     translate x*-3
                    }
//parte menor
#declare JanelaM =  box{ <48,700,24>,<252,770,428>
                     texture{Green_Glass}
                    }

  
                                          

//--------------------------PREDIO----------------------------------------------

#declare predio = union {
        object {blocoPrincipal}
        
        //VIGAS VERTICAIS
        
        object {vigaVertical}
        object {vigaVertical
                translate z*226 }
        object {vigaVertical2}
        object {vigaVertical2
                translate x* 150}
        object {vigaV
                translate z*226}
        object {vigaV2}
        
        
        //VIGAS HORIZONTAIS
        
        object {vigaHorizontal}
        object {vigaHorizontal
                translate y * 600}
        object {vigaHorizontal
                translate y * 200}
        object {vigaHorizontal
                translate y * 400}
        object {vigaH}
        object {vigaH
                translate y* -150}
                
                
         //JANELAS
         object {Janela}
         object {Janela
                translate y * 92}
         object {Janela
                translate y * 206}
         object {Janela
                translate y * 298}
         object {Janela
                translate y * 406}
         object {Janela
                translate y * 498}
         
         object {Janela
                translate z *226}
         
         object {Janela
                translate y * 92
                translate z *226}
         object {Janela
                translate z *226
                translate y * 206}
         object {Janela
                translate z *226
                translate y * 298}
         object {Janela
                translate z *226
                translate y * 406}
         object {Janela
                translate z *226
                translate y * 498}
         
         
         
         //parte de cima
         object {JanelaM}
         object {JanelaM
                translate y* 75 }
         object {JanelaM 
                translate y * 150 }
         object {JanelaM
                translate y * 225}
         
                
                
        
         
         
         
         
         
         
         //outra direção das janelas
         object{Janela2}
         object {Janela2
                translate y * 92}
         object {Janela2
                translate y * 206}
         object {Janela2
                translate y * 298}
         object {Janela2
                translate y * 406}
         object {Janela2
                translate y * 498}
                
         object{Janela2
                translate x * 160}
         object {Janela2
                translate y * 92
                translate x * 160}
         object {Janela2
                translate y * 206
                translate x * 160}
         object {Janela2
                translate y * 298
                translate x * 160}
         object {Janela2
                translate y * 406
                translate x * 160}
         object {Janela2
                translate y * 498
                translate x * 160}       
                
                
        
        
        
        
        

}


//============================================================ MONTANDO ================================

//object {predio}        