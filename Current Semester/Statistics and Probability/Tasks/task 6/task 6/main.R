Segunda <- c(23,29,27,28,25)
Terca <- c(21,24,29,31,31)
Quarta <- c(24,26,25,27,31)
Quinta <- c(21,27,32,21,21)
Sexta <- c(22,33,27,24,33)
Sabado <- c(30,28,25,24,20)
Domingo <- c(21,21,20,30,26)

dias_uteis = cbind(Segunda, Terca, Quarta, Quinta, Sexta)
final_de_semana = cbind(Sabado, Domingo)

mes <- cbind(dias_uteis, final_de_semana)

matriz1 <- matrix(1:8, nrow = 2, ncol=4)
matriz2 <- matrix(1:16, nrow = 4, ncol=4)
matriz_rbind <- rbind(matriz1, matriz2)

rownames(mes) <- paste('Semana ', 1:nrow(mes), sep = '')

mes['Semana 1', 'Segunda']

mean(mes['Semana 1',])

colMeans(mes)


# --------------------------------

IMC <- c(23.0,24.2,18.6,31.1,28.4,26.1,20.0,32.7,37.5)
individuo <- c("ID1","ID2","ID3","ID4","ID5","ID6","ID7","ID8","ID9")
peso <- c(65,70,57,90,92,80,76,89,90)
idade <- c(18,19,22,25,19,24,24,21,20)
altura <- c(168,170,175,170,180,175,195,165,155)
diabetes <- c("NAO","SIM","NAO","SIM","NAO","NAO","SIM","SIM","SIM")

df <- data.frame(IMC ,individuo, peso,idade, altura, diabetes)

amostra <- c(11,6,8,7,13)

summary(amostra)
sd(amostra)
var(amostra)

hist(precip, main="Teste", col="#ffaa00")

boxplot(df$IMC~df$diabetes)

barplot(table(df$diabetes))
