library(fdth)

sort(data$`Número de calçado`)

data$`Número de calçado_ord` <- factor(
  data$`Número de calçado`, order = TRUE, levels = c("35", "36", "37", "38", "39", "40", "41", "42", "43", "44"))

x<-barplot((table(data$`Número de calçado_ord`)/length(data$`Número de calçado_ord`))*100, ylab="% de estudantes", xlab="nº de calçado", ylim=c(0,25), col="orange")

text(x, (table(data$`Número de calçado_ord`)/length(data$`Número de calçado_ord`))*100-1, labels=round((table(data$`Número de calçado_ord`)/length(data$`Número de calçado_ord`))*100), col="black", cex=1.0)
  
