//Predio 2 Andrei + Masp
#declare Concreto = texture { pigment { granite turbulence 1.0 color_map {
    [0  .25 color White color Gray75] [.25  .5 color White color Gray75]
    [.5 .75 color White color Gray75] [.75 1.1 color White color Gray75]}}
    finish { ambient 0.2 diffuse 0.3 crand 0.03 reflection 0 } normal {
    dents .5 scale .5 }}
         
//Predio Andrei
#declare Concrete1 =
   texture { pigment { granite turbulence 1.5 color_map {
    [0  .25 color White color Gray95] [.25  .5 color White color White]
    [.5 .75 color White color White] [.75 1.1 color White color Gray85]}}
    finish { ambient 0.2 diffuse 0.3 crand 0.003 reflection 0 } normal {
    dents .5 scale .5 }}  //end
    
#declare Vidro =
  texture{
    pigment{ rgbf<0.5,0.5,0.5,0.8>}
    finish { 
      diffuse 0.1
      reflection 0.2
      specular 0.8
      roughness 0.0003
      phong 1
      phong_size 400
    }
  }// end

#declare Street_Texture = 
  texture{ 
    pigment{ color rgb<1,1,1>*0.3}
    normal { bumps 0.5 scale 0.005}
    finish { diffuse 0.9 phong 0.1}
  } // end  
  
#declare Water_Material =  
material{    
 texture{ 
   pigment{ rgbf <0.92,0.99,0.96,0.45> }
   finish { diffuse 0.1 reflection 0.5  
            specular 0.8 roughness 0.0003 
            phong 1 phong_size 400}
 } // end of texture --------------------
 interior{ ior 1.3 caustics 0.15  
 } // end of interior ------------------- 
} // end of material -------------------- 

