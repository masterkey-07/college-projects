library(fdth)

altura <- data$`Altura (em centímetros)`

sort(altura)

tab = fdt(altura, start=155,h=4,end=188) # ver os dados ordenados para definir os valores de start, h e end

plot(tab, type='fh', xlab="Altura (em centímetros)",ylab="Qtd. Altura")
