library(fdth)

altura <- data$`Altura (em centímetros)`

sort(altura)

tab=fdt(altura, start=155,h=3,end=188) # ver os dados ordenados para definir os valores de start, h e end

par(mfrow=c(1,3))

boxplot(altura, ylab = "Altura (em centímetros)", cex.axis=1.6, cex.lab=1.6) #diagrama de caixas
points(mean(altura), pch=3) 

plot(tab, type='rfph', xlab="Altura (em centímetros)",ylab="% Alturas", cex.axis=1.6, cex.lab=1.6) 
par(new=TRUE)
plot(tab,type='rfpp', xlab="Altura (em centímetros)",ylab="% Alturas", col = "black", cex.axis=1.6, cex.lab=1.6) # histograma e poligono de frequencia 

plot(tab,type='cfpp', xlab="Altura (em centímetros)",ylab="% acumulados", ylim=c(0,100), col = "black",cex.axis=1.6, cex.lab=1.6 ) #ogiva de Galton (% acumulados) 

