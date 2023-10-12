from turtle import * 
import colorsys


#texto
penup()
goto(0,200) 
pendown()
color("pink") 
write("Felices alergias ;D", 
      align = "center", 
      font=("Georgia", 20, "normal"))



#fondo
speed(20)
bgcolor("purple")
h=0

#tallo
penup()
goto(0,-80) 
pendown()
color("green") #Pueden cambiar el color
begin_fill()
rt(90)
fd(400) 
lt(90)
fd(20) 
lt(90)
fd(400)
lt(90) 
fd(20)
end_fill()

penup()
goto(0,-300) 
pendown()
color("white") 
write("insertar 'Primavera' de 31 minutos", 
      align = "center", 
      font=("Times new roman", 9, "normal"))

#Petalos
penup()
goto(10,0)
pendown()
for i in range (16):
    for j in range (10):
        color("yellow")
        h+=0.005
        rt(90)
        circle(150-j*6,90)
        lt (90)
        circle(150-j*6,90)
        rt(180)
    circle(40,24)


#centroflor    
penup()
goto(-5,-7)
pendown()
color("orange")
begin_fill()
circle(37)
end_fill()
done()