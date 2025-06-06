# 🛠️ Exemplos Práticos: Do Solo ao Espaço

Esta seção reúne aplicações diretas de todos os conceitos anteriores, mostrando como fórmulas “simples” guiam missões reais de exploração espacial e sensoriamento planetário.

---

## 🌌 1. Cálculo de Altitude de Crateras

Um rover em Marte mede a sombra projetada por uma rocha de 0,5 m de altura—ela faz 0,2 m de sombra. Em outro ponto, a sombra de uma formação rochosa faz 1,8 m. Qual a altura dessa formação?

\[
\frac{0{,}5}{0{,}2} = \frac{h}{1{,}8} \quad \Rightarrow \quad h = 4{,}5 \text{ m}
\]

- **Interpretação planetária:** As rochas em Marte têm “rugosidade” variável; esse cálculo gera mapas de relevo que guiam o trajeto do rover.

---

## 🌠 2. Mapeamento de Altimetria Lunar

Uma sonda orbita a Lua a 100 km de altitude e emite um feixe laser para medir a cratera Tycho. O pulso retorna em 0,000667 s. Supondo velocidade da luz \( c = 3 \times 10^8 \) m/s, qual a profundidade aproximada da cratera?

1. Tempo de ida e volta:  
   \[
   d_{\text{ida+volta}} = c \times t = 3 \times 10^8 \times 6,67 \times 10^{-4} = 2 \times 10^5 \text{ m}
   \]
2. Distância de ida (do satélite à superfície):  
   \[
   d_{\text{ida}} = \frac{2 \times 10^5}{2} = 1 \times 10^5 \text{ m} = 100 \text{ km}
   \]
3. Se a sonda está a 100 km, a cratera está praticamente no nível de base. A “profundidade” se mede comparando com altitude média local (ex.: 1 km de topo de montanha lunar), deduzindo 99 km de “desnível” (hipotético).  

- **Visão astronômica:** Esse tipo de triangulação laser baseia-se indiretamente no Teorema de Tales e relações métricas, pois envolve proporções de distâncias e tempos de retorno.

---

## 🌌 3. Navegação Interestelar (Simples)

Suponha que um sistema estelar binário esteja em direções conhecidas, formando um triângulo com a Terra. Ângulos medidos:  
- \( \angle A = 35^\circ \)  
- \( \angle B = 55^\circ \)  
Distância entre estrelas (lado c) = 4 UA (Unidades Astronômicas).

Queremos calcular a distância Terra–Estrela A (\( a \)) usando a Lei dos Senos:

\[
\frac{a}{\sen(A)} = \frac{c}{\sen(C)} \quad \text{onde} \quad C = 180^\circ - (A + B) = 90^\circ
\]
\[
\frac{a}{\sen(35^\circ)} = \frac{4}{\sen(90^\circ)} = 4 \quad \Rightarrow \quad a = 4 \times \sen(35^\circ) \approx 4 \times 0{,}574 = 2{,}296 \text{ UA}
\]

- **Interpretação interestelar:** Ao planejar uma sonda que vai para a estrela A, essa distância (2,296 UA) orienta a trajetória e o tempo estimado de viagem a velocidades sub-luz.

---

## 🛰️ 4. Cálculo de Área de Painel Solar

Em uma estação espacial, um painel solar trapezoidal tem dois lados medindo 4 m e 6 m, com ângulo formado de \( 120^\circ \). Para calcular sua área, usa-se o Teorema das Áreas:

\[
A = \frac{1}{2} \times 4 \times 6 \times \sen(120^\circ) = 12 \times \frac{\sqrt{3}}{2} = 6\sqrt{3} \approx 10{,}39 \text{ m}^2
\]

- **Contexto orbital:** Essa área determina a potência máxima gerada pelo painel em órbita alta, onde o Sol incide com menores perdas atmosféricas.  

---

## ⚙️ 5. Configuração de Antena na Sonda

Ao montar a antena de comunicação, engineering designers formam um triângulo entre o transmissor, receptor e o centro de massa da sonda. Suponha que dois lados medem 1,8 m e 2,2 m, com ângulo de \( 45^\circ \) entre eles. Qual o comprimento do terceiro lado (a) usando a Lei dos Cossenos?

\[
a^2 = 1{,}8^2 + 2{,}2^2 - 2 \times 1{,}8 \times 2{,}2 \times \cos(45^\circ)
\]
\[
a^2 = 3{,}24 + 4{,}84 - 2 \times 3{,}96 \times \tfrac{\sqrt{2}}{2} = 8{,}08 - 3{,}96\sqrt{2}
\]
\[
3{,}96\sqrt{2} \approx 3{,}96 \times 1{,}414 = 5{,}601 \quad \Rightarrow \quad a^2 = 8{,}08 - 5{,}601 = 2{,}479
\]
\[
a = \sqrt{2{,}479} \approx 1{,}575 \text{ m}
\]

- **Significado prático:** O comprimento \( a \approx 1,575 \) m define a estrutura que garante o alinhamento de feixe entre antena e Terra.

---

## 📚 Referências

- IEZZI, G. *Fundamentos de Matemática Elementar*, Vol. 3  
- LEITE, A. E.; CASTANHEIRA, N. P. *Geometria Plana e Trigonometria*
