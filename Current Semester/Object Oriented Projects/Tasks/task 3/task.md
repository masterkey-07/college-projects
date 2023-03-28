7. Suponha um programa em que todo o código está implementado no método main.
   Ele tem um problema de coesão ou acoplamento? Justifique.

Resposta: De coesão, pois o código main fará todas as funcionalidades do código, assim a compreensão do código é mais complicada já que não há a divisão de funções em métodos.

8. Qual princípio de projeto é violado pelo seguinte código?

void onclick() {
num1 = textfield1.value();
c1 = BD.getConta(num1)
num2 = textfield2.value();
c2 = BD.getConta(num2)
valor = textfield3.value();
beginTransaction();
try {
c1.retira(valor);
c2.deposita(valor);
commit();
}  
 catch() {
rollback();
}
}

Resposta : Coesão, o nome das variáveis não são óbvias ao que representam, como a própria função tem um nome extremamente genérico.

9. Costuma-se afirmar que existem três conceitos chaves em orientação a objetos: encapsulamento, polimorfismo e herança.
   Suponha que você tenha sido encarregado de projetar uma nova linguagem de programação.
   Suponha ainda que você poderá escolher apenas dois dos três conceitos que mencionamos.
   Qual dos conceitos eliminaria então da sua nova linguagem? Justifique sua resposta.

   Resposta : Herança, pois através dela há o risco de aumentar significantemente a complexidade do projeto se não for usada sabiamente, como também um dos objetivos da Herança pode ser alcançada através de Implementação de Interfaces como pelo meio de Composição, assim eliminará o risco de complexidade extra em um projeto já de extrema complexidade.

10. Qual princípio de projeto é violado pelo seguinte código? Como você poderia alterar o código do método para atender a esse princípio?

void sendMail(ContaBancaria conta, String msg) {
Cliente cliente = conta.getCliente();
String endereco = cliente.getMailAddress();
"Envia mail"
}

Resposta : Coesão, a função sendMail faz mais que uma ação para poder assim enviar o email, poderá ser divido a função em sub funções e uma função que seja mais específica em sua ação

void sendMail(String endereço, String msg) {
"Envia mail"
}

void getEndereçoDaConta(ContaBancaria conta){
Cliente cliente = conta.getCliente();
return cliente.getMailAddress();
}

void sendMailByContaBancaria (ContaBancaria conta, String msg){
String endereço = getEndereçoDaConta(conta);

sendMail(endereço, msg);
}

11. Qual princípio de projeto é violado pelo seguinte código? Como você poderia alterar o código do método para atender a esse princípio?

void imprimeDataContratacao(Funcionario func) {
Date data = func.getDataContratacao();
String msg = data.format();
System.out.println(msg);
}

Resposta : Coesão, a função faz duas tarefas, pega a data e formata ela, e depois a imprime.

void imprimeData (String mensagem){
System.out.println(mensagem);
}

void formatarData (Date data){
return data.format();
}

void imprimeDataContratacao(Funcionario func) {
Date data = func.getDataContratacao();
String msg = formatarData(data);
imprimeData(msg);
}

12. As pré-condições de um método são expressões booleanas envolvendo seus parâmetros (e, possivelmente, o estado de sua classe) que devem ser verdadeiras antes da sua execução. De forma semelhante, as pós-condições são expressões booleanas envolvendo o resultado do método. Considerando essas definições, qual princípio de projeto é violado pelo código abaixo?

class A {  
 int f(int x) { // pre: x > 0
...
return exp;
} // pos: exp > 0
...
}
class B extends A {  
 int f(int x) { // pre: x > 10
...
return exp;
} // pos: exp > -50
...
}

Resposta : Substituição de Liskov, a classe B troca a regra de negócio estabelecida pela classe A.

13. Calcule o CBO e LCOM da seguinte classe:

class A extends B {

C f1, f2, f3;

void m1(D p) {
"usa f1 e f2"
}
void m2(E p) {
"usa f2 e f3"
}
void m3(F p) {
"usa f3"  
 }
}

[m1,m2] = {f1,f2} e {f2,f3} => {f2}
[m1,m3] = {f1,f2} e {f3} => {}
[m2,m3] = {f2,f3} e {f3} => {f3}

Resposta : CBO(A) = 5 (B,C,D,E,F); LCOM = 1 (m1 e m3 não tem atr. em comum)

14. Qual das seguintes classes é mais coesa? Justifique computando os valores de LCOM de cada uma delas.

class A {

X x = new X();

void f() {
x.m1();
}
void g() {
x.m2();
}
void h() {
x.m3();
}
}
class B {

X x = new X();
Y y = new Y();
Z z = new Z();

void f() {
x.m();
}

void g() {
y.m();
}

void h() {
z.m();
}

}

Resposta : Classe A é mais coesa, pois em todas as suas funções se usa a mesma propriedade (x), assim tendo um LCOM de Zero
Enquanto na classe B todas as funções usam atributos distintos, assim tendo um LCOM de Três.

15. Por que a métrica LCOM mede a ausência e não a presença de coesão? Justifique.

Resposta : A Métrica LCOM, define como coesão o compartilhamento de pelo menos 1 atributo em comum entre os métodos das classes.
E a fórmula para calcular LCOM tentar contar quantas funções não tem atributos em comum entre elas.
Por isso que a métrica mede a ausência e não a presença.

16. Todos os métodos de uma classe devem ser considerados no cálculo de LCOM? Sim ou não? Justifique.

Resposta : Sim, pois todos os métodos de uma classe estão nessa classe por serem consideradas coesas, logo, que compartilham um conceito em comum, portanto todas devem entrar na formula.

17. A definição de complexidade ciclomática é independente de linguagem de programação. Sim ou não? Justifique.

Resposta : Não, pois uma linguagem de programação conterá funcionalidades de trocar o fluxo de controle, portanto, qualquer linguagem de programação será aplicável na complexidade ciclomática, já que ela considera a quantidade de operações de troca do fluxo de controle.

18. Dê um exemplo de código com complexidade ciclomática mínima. Qual é essa complexidade?

int soma (int a,int b){
return a + b;
}

Pela formula definida por Thomas McCabe, é 1

19. Cristina Lopes — professora da Universidade da Califórnia, em Irvine, nos EUA — é autora de um livro sobre estilos de programação (link). Ela discute no livro diversos estilos para implementação de um mesmo problema, chamado frequência de termos. Dado um arquivo texto, deve-se listar as n-palavras mais frequentes em ordem decrescente de frequência e ignorando stop words, isto é, artigos, preposições, etc. O código fonte em Python de todas as versões analisadas no livro está publicamente disponível no GitHub (e, para esse exercício, fizemos um fork do repositório original). Faça uma análise de duas dessas versões:

Monolítica, disponível neste link.

Orientada a objetos, disponível neste link.

Primeiro, revise e estude o código das duas versões (cada versão tem menos de 100 linhas). Em seguida, argumente sobre as vantagens da solução OO sobre a versão monolítica. Para isso, tente extrapolar o tamanho do sistema. Suponha que ele será implementado por desenvolvedores diferentes e que cada um ficará responsável por uma parte do projeto.

Resposta : A Solução OO tem sobre vantagem sobre a solução monolítica em um contexto de uma equipe o desenvolvendo, a facilidade de entendimento, divisão de tarefas, melhor organização de código como mais fácil para se testar.
