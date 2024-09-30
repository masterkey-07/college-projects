library(fdth)
library(dplyr)

sexo <- data$'Sexo'

agrupamento <- data$`Altura (em centímetros)` ~ data$Sexo

boxplot(agrupamento, xlab='Sexo', ylab='Altura')
points(1:nlevels(data$Sexo), tapply(data$`Altura (em centímetros)`, data$Sexo, mean),  pch=3)

