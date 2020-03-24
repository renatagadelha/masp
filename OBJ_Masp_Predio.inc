/*
#include "colors.inc"
#include "textures.inc"
#include "Texturas.inc"


//camera { location <500,500,-1000> look_at <0,0,0>} //Frente Inclida para Topo/Direita
camera { location <0,100,-900> look_at <0,0,0>} //Frente
//camera { location <0,1,-500> look_at <0,150,0>} //Frente perto Masp  
//camera { location <0,1100,0> look_at <0,0,0>} //Topo 
//camera { location <0,600,0> look_at <0,0,200>} //Topo detalhe recorte
//camera { location <0,50,1000> look_at <0,0,0>} //Atrás
//camera { location <900,1,0> look_at <0,200,0>} //Lateral Dir
//camera { location <-900,1,0> look_at <0,200,0>} //Lateral Esq 

//camera { location <0,200,-500> look_at <0,100,0>} //Frente Cartaz 
//camera { location <300,200,0> look_at <0,200,0>} //Lado 
 
background { LightSteelBlue }

light_source { <0,1000,-500> color White}     

light_source { <0,1000,500> color White}  

light_source { <0,200,-500> color White} 

light_source { <0,80,0> color White} //terreo
light_source { <0,300,0> color White} //1o andar
light_source { <0,600,0> color White} //2o andar


plane {
  y, 0   
  pigment { checker Green Black }
} 
*/

//Centro
#local AltCen = 170; //Altura do Bloco Central
#local LargCen = 810; //Largura do Bloco Central
#local ProfCen = 364; //Profundidade do Bloco Central
#local DeslCent = 100; //Deslocamento para Cima do Bloco Central

#declare Centro = 
difference {
  //Vidro
  box {<-LargCen/2,DeslCent,-ProfCen/2> <LargCen/2,AltCen+DeslCent,ProfCen/2>}
  box {<(-LargCen/2)+2,DeslCent-1,(-ProfCen/2)+2> <(LargCen/2)-2,(AltCen+DeslCent)+1,(ProfCen/2)-2>}
}

#declare GradeFrente =
  difference {
    box {<0,DeslCent,(-ProfCen/2)-2> <2,AltCen+DeslCent,(ProfCen/2)+2>}
    box {<-1,DeslCent-1,(-ProfCen/2)+1> <2+1,(AltCen+DeslCent)+1,(ProfCen/2)-1>}  
  }

#declare GradeLateral =
  difference {
    box {<(-LargCen/2)-2,DeslCent,0> <(LargCen/2)+2,AltCen+DeslCent,2>}
    box {<(-LargCen/2)+1,DeslCent-1,-1> <(LargCen/2)-1,(AltCen+DeslCent)+1,2+1>}
  }
#declare GradeMeio =
  difference {
    box {<(-LargCen/2)-2,DeslCent+(AltCen/2)-1,(-ProfCen/2)+1> <(LargCen/2)+2,DeslCent+(AltCen/2)+1,(ProfCen/2)-1>}
    box {<(-LargCen/2),DeslCent+(AltCen/2)-1,(-ProfCen/2)+1> <LargCen/2,DeslCent+(AltCen/2)+1,(ProfCen/2)-1>}
  }
  

#declare Grade =  
  merge {
    //Grade Frente
    #declare X = -LargCen/2;  // start
    #declare End_X = LargCen/2; // end
    #while ( X <= End_X )
     object{ GradeFrente translate < X, 0, 0> }
    #declare X = X + 30; // next
    #end //-------------- end of loop ----
    
    //Grade Meio do Prédio
    object{GradeMeio}
     
    //Grade Lateral
    #declare Z = -ProfCen/2;  // start
    #declare End_Z = ProfCen/2; // end
    #while ( Z <= End_Z )
     object{ GradeLateral translate < 0, 0, Z> }
    #declare Z = Z + 30; // next                 
    #end //-------------- end of loop ----      
  }
  

#declare Andares = 
union {
  //Andar 1
  box {
    <(-LargCen/2)-4,DeslCent,(-ProfCen/2)-4> <(LargCen/2)+4,DeslCent+12,(ProfCen/2)+4>
  }
  //Andar 2
  box {
    <(-LargCen/2),DeslCent+(AltCen/2)-18,(-ProfCen/2)+1> <LargCen/2,DeslCent+(AltCen/2),(ProfCen/2)-1>
  }
  //Teto
  difference {
    box {
      <(-LargCen/2)-4,AltCen+DeslCent-26,(-ProfCen/2)-4> <(LargCen/2)+4,AltCen+DeslCent+1,(ProfCen/2)+4>
    }
  
    #local LargRec = 30; //Largura do Recorte do Teto
    
    #declare Recorte = box {
      <0,AltCen+DeslCent-15,(-ProfCen/2)+10> <LargRec,AltCen+DeslCent+10,(ProfCen/2)-10>
    }
    
    //Grade Lateral
      #declare X = (-LargCen/2)+10;  // start
      #declare End_X = (LargCen/2)-10; // end
      #while ( X <= End_X )
       object{ Recorte translate < X, 0, 0> }
      #declare X = X + 40; // next                 
      #end //-------------- end of loop ---- 
  }    
}                                                                 
                                                                  
                                                                  
//Viga
#local AltVig = 314; //Altura da Viga
#local LargVig = 930; //Largura da Viga
#local ProfVig = 34; //Profundidade da Viga

#declare Viga = 
difference {
  box {
    <-LargVig/2,0,-ProfVig/2> <LargVig/2,AltVig,ProfVig/2>
  }
  box {
    <-LargCen/2,0,-ProfCen/2> <LargCen/2,AltCen+DeslCent,ProfCen/2>
  }
}
                                     
                                     
#local LarCar = 50; //Largura do Cartaz

#declare Cartaz = 
 union {
  box {
    <-LarCar/2,DeslCent,0> <LarCar/2,AltCen+DeslCent,1>
  }
  intersection {
    box {<-LarCar/2,0,-1> <LarCar/2,AltCen+DeslCent,2>}
    box {
      <-LarCar/2,DeslCent,0> <LarCar/2,DeslCent+LarCar,1>
      rotate <0,0,45>                                    
      scale<0,0.5,0>
      translate <88, 50, 0>
    }
  }
  text {
    ttf "cyrvetic.ttf" "TADS 2018" 0.01, 0
    pigment { Black }
    scale <30,30,30>
    rotate <0,0,90>
    translate <10, 100, -0.1>
  }
}
 
 

#declare Predio = 
union {
  object {
    Centro
    texture{Vidro}
    //pigment{ rgbf<0.7,0.7,0.7,0.9>}
  }
  
  object {
    Andares
    texture{Concreto}
  }
  
 object { //topo
    Viga
    pigment{ color Red }
    translate <0,0,98>
  }
  
  object { //base
    Viga
    pigment{ color Red }
    translate <0,0,-98>
  }
  
  object {
    Grade
    pigment{ color Black }
  } 
  
  object {
    Cartaz
    pigment { checker White rgb<1,1,1>*0.9 scale<10,10,10>}
    translate <(-LargCen/2)+50,0,(-ProfCen/2)-5>
  }   
}
  
//chamada
//object {Predio} 