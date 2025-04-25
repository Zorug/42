#include "pipex.h"

/*
Contar corretamente quantas palavras existem em uma string de comando, 
respeitando as aspas e ignorando espaços dentro delas.
*/

int	ft_countword(const char *input)
{
	int			word_count; // Quantas palavras já foram contadas
	int			inside_quotes; // Flag: estou dentro de aspas?
	const char	*ch; // Ponteiro que vai percorrer a string

	word_count = 0;
	inside_quotes = 0;
	ch = input;
	while (*ch != '\0') // percorre cada caractere da string até o final.
	{
		// Se encontrar \, pula ele e o próximo caractere 
		// (porque ele está escapado).
		if (*ch == '\\' && *(ch + 1) != '\0')
			ch += 2;
		// Alterna entre “dentro” e “fora” de aspas
		if (*ch == '"' || *ch == '\'')
			inside_quotes = !inside_quotes;
	// Conta uma nova palavra somente se o espaço estiver fora das aspas
		else if (*ch == ' ' && !inside_quotes)
			word_count++;
		ch++;
	}
// Adiciona a última palavra, porque normalmente não tem espaço no final.
	if (!inside_quotes)
		word_count++;
	return (word_count);
}

/*char	*ft_strndup(const char *s, size_t len)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}*/

int	array_size(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

/*Remove cada \ que vem antes de outro caractere
O caractere seguinte é mantido normalmente*/
char	*remove_backslashes(char *s)
{
	size_t	len; // comprimento final da string limpa
	size_t	j;   // índice de leitura da string original
	size_t	k;   // contador de barras invertidas (quantas serão removidas)
	char	*result;

	len = 0;
	j = 0;
	k = 0;
	while (s[j]) // Conta quantas barras invertidas existem
	{
		if (s[j + k] == '\\' && s[j + k + 1] != '\0')
			k++;
		j++;
	}
	// Aloca memória com o tamanho da string original menos as barras + 1 (\0)
	result = malloc(sizeof(char) * (ft_strlen(s) - k + 1));
	j = 0;
	len = 0;
	while (s[j]) /* Copia a string, ignorando os \ */
	{
		if (s[j] == '\\' && s[j + 1] != '\0')
			j++; // pula a barra
		result[len++] = s[j++];
	}
	result[len] = '\0';
	return (result);
}

// remover os símbolos de escape (inverse backslash)
char	**remove_scape_symbol(char **s)
{
	char	**new_array;
	int		i;

	remove_spaces(s); // limpa espaços vazios que sobraram nas strings
	if (!s[0]) // Se a primeira string for nula/vazia, retorna NULL
		return (NULL);
	new_array = malloc(sizeof(char *) * (array_size(s) + 1));
	/* Cria um novo char **, com o mesmo número de elementos de s 
	(mais 1 para o NULL final) */
	i = 0;
	while (i < (array_size(s)))
	{
		new_array[i] = remove_backslashes(s[i]);
		i++;
	/*Cada string passa por remove_backslashes(), que remove os \
		Ao final, fecha o array com NULL*/
	}
	new_array[i] = NULL;
	return (new_array);
}
