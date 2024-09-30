library(dplyr)
library(ggplot2)

dados <- read_excel("./data.xlsx")


dados <- dados %>%
  mutate(Expectativas_Convertidas = ifelse(`Quais são as suas expectativas com relação a unidade curricular de Probabilidade e Estatística?` != "", TRUE, FALSE))

# Agora, podemos criar o gráfico de barras com os valores convertidos
grafico <- ggplot(dados, aes(x = `Sexo`, fill = Expectativas_Convertidas)) +
  geom_bar(position = "stack") +
  scale_fill_manual(values = c("TRUE" = "blue", "FALSE" = "red"), labels = c("Com Descrição", "Sem Descrição")) +
  labs(x = "Sexo", y = "Contagem", fill = "Expectativas") +
  ggtitle("Quantidade de expectativas descritas por Sexo") +  geom_text(aes(label = scales::percent(..count../sum(..count..)), y = ..count..), 
                                                                      position = position_stack(vjust = 0.5), stat = "count", 
                                                                      color = "white", size = 3)

# Exibindo o gráfico
print(grafico)
