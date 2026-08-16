# Teorema de Braga  

eu imaginei o infinito e refleti...  

o universo é um espelho circular causando EFEITO de infinito...  

logo falei EUREKA o infinito é apenas um efeito, coloque um espelho na frente do outro, existe um efeito de infinito, no universo, porem, mais denso e profundo a ponto de causar quase uma alucinação sinergica; é como se a gente fosse esse * e o universo ( ) nos estamos no meio ( * ) imagine que o ( ) é um circulo ok e nos estamos no meio, pra qualquer lugar que a gente olhar reflete meio que tudo, imagine um espelho circular gigante e voce no meio dele ou melhor, no inicio dele... agora olhe pra qualquer lugar, advinha oque acontece se fosse apenas ampliar a camera ??? isso mesmo é inifinito para sempre, mas é so um efeito.... enfim pensei como eu posso representar isso com numero?  

ja sei !!  

010203040506070809  
908070605040302010  
  
 1 2 3 4 5 6 7 8 9  
9 8 7 6 5 4 3 2 1  
  
918273645546372819  
  
EUREKA  
  
desde então venho procurando padrões nesse numero 918273645546372819  

voce entendeu como cheguei nele? eu liguei a sequencia numero com zero, para não termos o problem do infinito entre 1, 2, 3... depois refleti ele como o universo, ai pensei ok, e se eu tirar os zeros e descer a coluna de cima para baixo?.... para não ter que ficar escrevendo tantos numeros é tipo as duas colunas iniciais zipadas. enfim me deparei com esse numero que é tipo:  

oi meu nome é espelho, eu tenho propriedades que gritam ESPELHO ESPELHO ESPEEEEEEEEEEEELHO;  

a primeira é obvia é um palindromo perfeito e a segunda é que cada par do digito equidistante do centro soma o digito + 1.  

oque isso quer dizer né? kkk é tipo assim vamos partir do principio que  

$$
\text{Para qualquer número } n, \text{ a soma de cada par de dígitos equidistantes do centro é sempre } n+1.
$$

oque isso quer dizer né? kkkk vamos abstrair a linguagem matematica
escolha qualquer numero que da pra contar com os dedos... 7 por exemplo  

vamos construir sua sequencia com zeros  
01020304050607  

agora vamos refletir ele como num espelho circular  
70605040302010  

agora vamos por um embaixo do outro  
01020304050607  
70605040302010  

agora vamos tirar os zeros  
 1 2 3 4 5 6 7  
7 6 5 4 3 2 1  

agora vamos descer a primeira coluna para termos uma sequencia de uma linha  
e pronto temos que ℬ(7) = 71625344352617  

para não ter que falar 1 kilo de texto sempre e explicar o caminho do pensar toda hora podemos resumir toda essa logica em:  

$$
\text{Braga}(n) = \bigoplus_{i=1}^{n} \left( (n - i + 1), \; i \right)
$$

isso vale para qualquer numero sem virgula maior que 1 (eu to tentando ao maximo não usar nenhum jargão matematico kkk)
