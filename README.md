# TCC_Alarme-de-Incendio
Projeto de conclusão do curso técnico de Eletroeletrônica do Colégio Técnico da Unicamp (COTUCA) em agosto de 2017.

O projeto consiste em um simulador de alarme de incêncio controlado por `Arduino`. 
Este alarme contém um sensor de temperatura (LM35), sensor de fumaça (Chave Óptica) e um sensor de Luz (P22).

Este projeto foi feito em conjunto dos alunos, colegas de classe e amigos Guilherme Oliveira e Leonardo Rodrigues.

## Funcionamento

O projeto consiste em basicamente em um Arduíno fazendo o monitoramento de três componentes eletrônicos transdutores de temperatura, fumaça e luz, sendo eles o LM35 (Sensoriamento de temperatura), a chave óptica (Sensor de fumaça) e o P22 (Sensor de chamas/luz). O projeto também possui um display fazendo a amostragem dos valores de temperatura, luz e fumaça (no caso, mostra o nível lógico da chave óptica). 

Todas as ligações e conexões de todos os componentes foram feitas através de uma protoboard e os componentes ficaram suspensos no topo de uma caixa de acrílico. Para simular o incêndio, foi utilizada uma vela de balão e uma tampa para apagar a chama.

Quando um dos componentes atingir o seu “nível crítico” mostrado no display (Valor pré-determinado no Arduíno para que o Buzzer [alarme] seja ativado), o alarme de incêndio será ativado, que neste caso é um Buzzer e um LED vermelho piscando. Após a temperatura ambiente ter se resfriado, a chama se apagado e a fumaça ter sida dispersada, o alarme irá ser desativado automaticamente.

Os três componentes podem ser selecionados através de três chaves retentivas que se encontram na protoboard do projeto, que desativam a alimentação dos componentes.
