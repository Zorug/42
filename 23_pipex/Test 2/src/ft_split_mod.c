#include "pipex.h"

/*
Extrair a próxima palavra da string s, que pode ser:
- uma palavra simples (ls)
- uma sequência entre aspas ("hello world")
- ou contendo escapes (a\ b)
*/
char	*get_string(const char *s)
{
	int	k; // usado temporariamente para percorrer dentro de aspas
	int	wordlen; 	//  vai acumular o comprimento total da palavra que 
					// será extraída
	wordlen = 0;
	// Vai percorrendo os caracteres até encontrar um espaço, 
	// quebra de linha ou o fim da string
	while (s[wordlen] != '\0' && s[wordlen] != ' ' && s[wordlen] != '\n')
	{
	// - Entra no modo "coletar tudo dentro das aspas"
	// - Vai continuar contando os caracteres até encontrar a aspas 
	//   de fechamento correspondente
	// - Também trata escapes (contra tab)
		if (s[wordlen] == '\"' || s[wordlen] == '\'') // dentro das aspas
		{
			k = 1;
			// s[wordlen + k] != s[wordlen] → espera encontrar a 
			// mesma aspas de fechamento
			while (s[wordlen + k] != '\0' && s[wordlen + k] != s[wordlen])
			{
				if (s[wordlen + k] == '\\' && s[wordlen + k + 1] != '\0')
					k++; // pula o caractere escapado
				k++;
			}
			wordlen += k + 1;
			// Quando termina, soma tudo (k + 1) ao wordlen → inclui aspas 
			// de abertura e fechamento
		}
		else // sem aspas
			wordlen++;
	}
	/*Copia wordlen caracteres de s
	Cria uma nova string alocada dinamicamente com a palavra
	Essa string pode incluir aspas, que serão removidas depois por 
	clean_words()*/
	return (ft_strndup(s, wordlen));
}

/*
"'banana'"      → "banana" → Remove aspas simples (')
"\"hello world\"" → "hello world" → Remove aspas duplas (")
" teste "        → "teste" → Remove espaços no início/fim (quando combinam)
*/
void	clean_words(int words, char **array)
/*
words: número de palavras no array
array: vetor de strings (ex: { "\"banana\"", "'abc'", "normal", NULL })
*/
{
	int	i;
	int	len;

	i = 0;
	while (i < words)
	{
		len = ft_strlen(array[i]);
		/*
	len >= 2: precisa ter ao menos dois caracteres (pra ter "início e fim")
    array[i][0] == '\"' || '\'': começa com aspas (ou espaço)
    array[i][len - 1] == array[i][0]: termina com a mesma coisa que 
	começou
⚠️ Ou seja: só remove se abre e fecha igual
		*/
		if (len >= 2 && (array[i][0] == '\"' || array[i][0] == '\''
			|| array[i][0] == ' ') && ((array[i][len - 1] == array[i][0])
			|| array[i][0] == '\0'))
		{
			ft_memmove(array[i], array[i] + 1, len - 2);
			array[i][len - 2] = '\0';
			/*
	Move a string uma posição à esquerda, ignorando o primeiro caractere
	E substitui o penúltimo caractere por \0, apagando o último
			*/
		}
		i++;
	}
}

/*
Diferente da ft_split() normal, ela:
    - Respeita aspas (" " ou ' ')
    - Lida com espaços dentro das aspas
    - Remove símbolos de escape (\)
    - Remove as aspas externas
*/
char	**ft_split_mod(char *s)
{
	size_t	index;
	size_t	words;
	char	**array;
	char	**new_array;

	index = 0;
	words = ft_countwords(s); // Conta quantas "palavras" existem
	array = malloc((words + 1) * sizeof(char *)); // Aloca espaço para o array
	if (!s || !array)
		return (NULL);
	while (index < words)
	{
		while (*s == ' ' || *s == '\n')
			s++; // pula espaços
		array[index] = get_string(s); // extrai uma palavra (respeitando aspas)
		s += ft_strlen(array[index]); // avança na string
		index++;
	}
	array[index] = NULL; // Finaliza o array
	clean_words(words, array); 	//Remove aspas ou espaços que estavam no 
								//início e no fim das palavras
	new_array = remove_scape_symbol(array);// Remove símbolos de escape (\)
	ft_free_array(array); // Libera array original
	return (new_array);
}
