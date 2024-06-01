O objetivo desta atividade é explorar o uso de redes neurais convolucionais modelo VGG16 para tarefas de classificação de imagens/cenas aéreas e praticar o uso da biblioteca PyTorch. Desta forma, o intuito é treinar e avaliar a VGG16 em diferentes cenários, desde o treinamento inicial até o uso de Transfer Learning com diferentes níveis de descongelamento. Para a atividade, siga os seguintes passos:

**0.    Preparação do banco de dados**
- Utilizar o conjunto de dados “UC Merced – Land Use Classification” chamado de “UC Merced (UCM) Captions”, disponível no repositório do github através do seguinte link: https://github.com/isaaccorley/torchrs#remote-sensing-image-captioning-dataset-rsicd;
- Separar os dados (dataset) em porções de treino (80%) e teste (20%).


**1.    Carregamento da VGG16.**
- Carregar o modelo VGG16;
- Exemplos de como realizar as operações podem ser encontrados nos seguintes locais:
  - Kaggle: "Fine-Tuned Classifier with VGG and PyTorch" (https://www.kaggle.com/code/saekiryosuke/fine-tuned-classifier-with-vgg16-and-pytorch);
  - GitHub: "VGG Transfer Learning Notebook" (https://github.com/Leo-xxx/pytorch-notebooks/blob/master/Torn-shirt-classifier/VGG16-transfer-learning.ipynb).

**2.    Treinar a rede inicial fromScratch (pretrained=False)**
- Treine a VGG16 inicial (sem pesos pré-treinados);
- Acompanhe a função de perda.

**3.    Treinar Transfer learning da rede com descongelamento parcial (pretrained=True)**
- Treine a VGG16 usando Transfer Learning, descongelando apenas a camada FC (Fully-Conected layer);
- Acompanhe a função de perda.

**4.    Treinar Transfer Learning da rede com descongelamento completo (pretrained=True)**
- Treine a VGG16 usando Transfer Learning, descongelando a última camada convolutiva Conv (Convolutional layer) e a FC (Fully-Conected layer);
- Acompanhe a função de perda.

**5.    Avaliação e comparação:**
- Criar gráficos de linhas para a função de perda de entropia cruzada (Cross-entropy) por 50 épocas, obtendo um gráfico por treino/arquitetura (cenário de treinamento inicial, Transfer Learning com FC descongelada e Transfer Learning   com descongelamento da última camada convolutiva e FC). Analise os gráficos;
- Criar um gráfico de barras comparativo da acurácia obtida entre as três arquiteturas. Analise os resultados obtidos;
- Salvar e informar o melhor modelo para cada uma das três abordagens.

**Observações:**
- Certifique-se de comentar cada etapa, mantendo a objetividade e deixando evidente os parâmetros escolhidos;
- Mantenha a organização, funcionalidade, eficiência, legibilidade e boas práticas de programação para desenvolver o código;
- Seguir as normas de entrega de documentos e prazos informadas na página inicial da turma no google classroom;
- Entrega: código em júpiter notebook;
- Prazo: até 23:59h do dia 26/04/2024.