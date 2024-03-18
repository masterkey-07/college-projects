# Atividade 1 – Classificação com Árvores de Decisão - dataset TITANIC

- Considerando a base de dados TITANIC, realize uma análise exploratória do banco de dados e crie um modelo baseado em árvores de decisão a partir destes dados. Siga o link fornecido a seguir para fazer o download do dataset: https://www.kaggle.com/c/titanic/data. Para criação das árvores, siga o tutorial a seguir: https://scikit-learn.org/stable/modules/tree.html. Discuta os resultados obtidos.

- Sabendo que os hiperparâmetros de um modelo de aprendizado de máquinas afetam o comportamento e o desempenho do algoritmo e a construção do modelo de classificação, obtenha árvores de decisão a partir da variação dos parâmetros a seguir:
   - Teste os critérios “gini” e “entropy” na construção das árvores de decisão (Criterion = {“gini”, entropy}).
  - Experimente os métodos de divisão dos nós "best" e "random" (Splitter = {“best”, “random”}).
  - Varie a profundidade máxima da árvore considerando os valores nulo, 2 e 4 (max_depth = {None, 2, 4}).
  - Teste dois valores diferentes para o número mínimo de amostras necessárias para dividir um nó considerando os valores 2 e 10 (min_samples_split = {2, 10}).

Após criar as árvores com as diferentes combinações de parâmetros, analise e discuta as diferenças observadas entre elas. Explique como cada parâmetro influencia na construção de cada modelo de árvore de decisão obtido. Considere uma **competição** entre as árvores, onde a melhor árvore (acurácia balanceada) receberá melhor pontuação (Score).

**Observações:**
- Documente cada etapa do processo de criação das árvores de decisão e da análise de suas diferenças de maneira clara e detalhada.
- Utilize gráficos, tabelas ou qualquer outra forma de representação que facilite a visualização, compreensão e discussão dos resultados.
- Mantenha a objetividade ao relatar as observações e conclusões obtidas durante o exercício.
- Entrega: código + relatório. Prazo: até 23:59h do dia 24/03/2024.