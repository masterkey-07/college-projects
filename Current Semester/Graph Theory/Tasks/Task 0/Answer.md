2. Considere o exemplo das rotas aéreas de uma das grandes companhias aéreas da América do Sul (Azul, Avianca, LATAM, Gol). 
Atribua a elas um modelo de rede, explicitando quem são vértices e arestas. Explique como você pode explorar este modelo para achar um caminho entre cidades que não tem conexões diretas.
Leve em consideração que voos tem horários distintos, o que precisa ser considerado para efeito de conexão (grupo).

Vértices: São as cidades com aeroportos. (Por exemplo: Congonhas (CGH), Guarulhos (GRU), Galeão (GIG), Salvador (SSA), etc.)

Arestas: Considera a Direção do Voo, como também seu horário de saída e chegada.

Algoritmo de Busca: A partir do vértice de início, serão verificados todos os caminhos possíveis até o vértice final, ponderando os tempos de início e chegada para que o viajante consiga pegar os voos corretamente (considerando a possibilidade em tempo de espera em cada vértice), chegando assim ao destino final. O algoritmo priorizará o caminho que permita ao viajante chegar mais cedo ao destino final, mas o preço da viagem também pode ser adicionado como variável da aresta, caso se deseje encontrar a viagem mais barata.