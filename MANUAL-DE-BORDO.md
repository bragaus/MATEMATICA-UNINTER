# 🧭 Manual de Bordo

> *"Toda nave precisa de um manual. Senão cada tripulante inventa o próprio jeito de pilotar — e aí ninguém acha nada."*

Este é o padrão de escrita do Projeto Exodus. Serve para que uma aula escrita daqui a dois semestres tenha a mesma cara das que já estão aqui.

---

## 📂 Arquivos

- Nome em `kebab-case`, prefixado pela posição na grade: `4.2-arcos-notaveis.md`
- Um arquivo por tema. O número vem da aula e da ordem do tema dentro dela.
- Codificação UTF-8, fim de linha LF, uma quebra de linha no fim do arquivo.

---

## 🏷️ Título

Exatamente um `# H1`, na primeira linha, no formato:

```text
# <emoji> <Nome do Tema>
```

- **Sem** prefixo `TEMA 3` ou `AULA 5` — o número já está no nome do arquivo e no índice.
- **Nunca** em CAIXA ALTA.
- O nome da aula mora no índice do módulo, não no título do tema.

Logo abaixo do título vem a frase de abertura, entre `>`. É ela que carrega o tom da nave.

---

## 🧱 Esqueleto da aula

```markdown
# 🌀 Equação da Parábola

> *"frase de abertura"*

---

## 🔬 <seção matemática>

---

## ✨ Analogias Psicodélicas

---

## 🌌 Aplicações Cósmicas

---

## 💹 Aplicações no Mercado Financeiro

---

## 👨‍💻 Exemplo em C++
```

As seções recorrentes têm nome e emoji fixos:

| Seção | Escreva exatamente |
|-------|--------------------|
| Analogia | `✨ Analogias Psicodélicas` |
| Cósmica | `🌌 Aplicações Cósmicas` |
| Financeira | `💹 Aplicações no Mercado Financeiro` |
| Código | `👨‍💻 Exemplo em C++` |
| Bibliografia | `📚 Referências` |

Quando o exemplo pertence a um subtópico específico, ele desce para `###` e ganha sufixo:
`### 👨‍💻 Exemplo em C++ — Vetor Hacker`.

---

## 🔢 Matemática

O GitHub só renderiza `$...$` e `$$...$$`. **`\(...\)` e `\[...\]` aparecem como texto cru** — não use.

```markdown
inline: $r_1, r_2, \dots, r_n$

display:

$$
\frac{AB}{A'B'} = \text{constante}
$$
```

Notação em português precisa de `\operatorname`, senão o KaTeX quebra:

| Errado | Certo |
|--------|-------|
| `\sen(\alpha)` | `\operatorname{sen}(\alpha)` |
| `\tg(\theta)` | `\operatorname{tg}(\theta)` |

---

## 💻 Código

Toda cerca declara a linguagem — sem isso não há realce de sintaxe:

````markdown
```cpp
int main() { return 0; }
```
````

Use `cpp` para C++, `c` para C, `text` para matriz, diagrama ou saída de terminal.

---

## 📐 Hierarquia e estilo

- Não pule nível: depois de `#` vem `##`, nunca `###` direto.
- Headings não terminam em dois-pontos.
- Travessão é `—` (em-dash). Não misture com `–` nem com `-`.
- Sem HTML cru (`<br>`, `&nbsp;`) — se precisar de alinhamento, use bloco ```` ```text ````.
- Espaço no fim da linha só quando forem exatamente dois, que é quebra de linha em Markdown.

---

## 🗺️ Índice do módulo

Cada módulo tem um `README.md` com:

1. `# <emoji> <Nome do Módulo>` e frase de abertura
2. A estrutura que os arquivos seguem
3. `## 📚 Conteúdo`, com `### Aula N — Nome da Aula` e a lista de temas
4. `## 🧬 Aplicações Cósmicas e Computacionais`
5. `## 📥 Contribua`

Regras da lista:

- Link sempre com prefixo `./`: `[Arcos Notáveis](./4.2-arcos-notaveis.md)`
- **O nome no índice é igual ao título do arquivo.** Se um mudar, o outro muda junto.

---

## 📝 Commits

- Conventional Commits, em português: `fix:`, `docs:`, `style:`, `refactor:`, `chore:`, `build:`
- Uma responsabilidade por commit. Se a mensagem precisa de um "e", são dois commits.
- Até 50 linhas alteradas. Exceção só para o que é indivisível — apagar um arquivo, trocar o fim de linha.

---

> *A padronização não engessa a viagem. Ela só garante que o mapa continue legível quando a nave estiver longe demais para voltar.*
