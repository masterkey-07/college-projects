# Relatório sobre traceroute

**Aluno** : Victor Jorge Carvalho Chaves
**RA** : 156.740


## O que é `traceroute` e para que serve?

`traceroute` é um utilitário de terminal, um programa com o propósito de detectar todos os caminhos (máquinas) que um pacote passou até chegar no endereço destino.

## Utilização do traceroute em 8 endereços

Ao utilizar o `traceroute` ele gera o seguinte resultado

#### (\*) significa que está oculto ou não suporta a interface do traceroute

| Sequência | IP ou Host             | Tempo 1   | Tempo 2   | Tempo 3   |
| --------- | ---------------------- | --------- | --------- | --------- |
| 1         | 10.13.0.1              | 17.739 ms | 27.615 ms | 27.592 ms |
| 2         | bb6a9069.virtua.com.br | 27.532 ms | 27.590 ms | 27.490 ms |
| 3         | *                      | *         | *         | *         |


Sabendo disso, será possível entender e analisar os as rotas dos seguintes websites :
- [www.ovale.com.br](https://www.ovale.com.br)
- [www.uol.com.br](https://www.uol.com.br)
- [www.uio.no](https://www.uio.no)
- [www.sydney.edu.au](https://www.sydney.edu.au)
- [www.unifesp.br](https://www.unifesp.br)
- [www.embraer.com](https://www.embraer.com)
- [www.mercadolivre.com.br](https://www.mercadolivre.com.br)
- [www.google.com](https://www.google.com)

## Análise dos resultados obtidos

### Roteadores demorando muito para receber os pacotes

No endereço [www.uio.no](https://www.uio.no), foi identificado uma demora de mais de 200ms para chegar até o endereço.

Pegando o trajeto gerado pelo `traceroute`...

é encontrado dois roteadores que tinham um aumento significativo de recebimento do pacote.

Os IP'S : 200.230.220.46 e o 109.105.97.65

Usando o site IPINFO, é visto que ambos os roteadore se encontram no extremo norte, um dele nos Estados Unidos e outro em Netherlands.

Com essa distância, pode ser uma explicaação para o aumento do tempo para receber o pacote.

### Um dos principais Backbone no Brasil

Em 5 rotas, os pacotes passaram pelo mesmo roteador da Embratel, o embratel-T0-0-1-0-uacc05.spoph.embratel.net.br (200.247.144.1).

Ao qual ele está na capital de São Paulo.


## Como utilizar o `traceroute` para detectar problemas? 

Podemos usar ele para detectar problemas pois conseguimos ver todo o trajeto que os pacotes passam até chegar ao seu destino (ou não).

Assim conseguimos analisar cada roteador que ele passou e verificar se tem alguma coisa estranha, como também verificar os falsos negativos e falso positivos, por ele realizar 3 tentativas para cada roteador.

Outros casos que ele consegue detectar:
- Grande deslocamento
- Roteadores que ficou preso
- Roteadores que passou novamente
- Anomalias