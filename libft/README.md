# Libft

## Part 1 - Libc functions

### ft_isalpha.c

```c
#include "libft.h"

int	ft_isalpha(int c)
{
//Check if c is an alphabetical character (a to z or A to Z)
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}
```

This function takes an integer **`c`** as a parameter and checks **`if`** it is an alphabetical character (**`a`** to **`z`** or **`A`** to **`Z`**) or not. If it is, it returns the integer **`1`**, meaning it is true. If it isn’t, it returns the integer **`0`**, false.

### ft_isdigit.c

```c
#include "libft.h"

int	ft_isdigit(int c)
{
	if ('0' <= c && c <= '9')
		return (1);
	return (0);
}
```

This function takes an integer **`c`** as a parameter and checks **`if`** it is a digit (**`0`** to **`9`**) or not. If it is, it returns the integer **`1`**. If it isn’t, it returns the integer **`0`**.

### ft_isalnum.c

```c
#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}
```

This function takes an integer **`c`** as a parameter and checks **`if`** it is an alphabetical character (`a` to `z` or `A` to `Z`) or a digit (`0` to `9`) or not. If it is, it returns the integer `1`. If it isn’t, it returns the integer `0`.

### ft_isascii.c

```c
#include "libft.h"

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
```

This function takes an integer **`c`** as a parameter and checks **`if`** it is an ascii character (`'\0’` to `DEL`) or not. If it is, it returns the integer `1`. If it isn’t, it returns the integer `0`.

### ft_isprint.c

```c
#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
```

This function takes an integer **`c`** as a parameter and checks **`if`** it is a printable character (`SPACE` to `‘~’`) or not. If it is, it returns the integer `1`, meaning `TRUE`. If it isn’t, it returns the integer `0`, meaning `FALSE`.

### ft_strlen.c

```c
#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}
```

This function takes a constant string, **`s`**, as a parameter and returns its size, **`size_t`**, the length of the string. It does that by going into each character of the string and adding **`1`** to the **`size_t` `len`** each time **`while`** the **`s[len]`** is different than **`'\0'`**, i.e. the string didn’t end.

### ft_memset.c

```c
#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tmp;

	tmp = (unsigned char *)b;
	while (len > 0)
	{
		*tmp = (unsigned char)c;
		tmp++;
		len--;
	}
	return (b);
}
```

**`memset`**, "memory set", is a function that fills a block of memory with a particular value. It writes `len` bytes of value `c` to the pointer to the block of memory(buffer) `b`. 

A loop assigns the value of `unsigned char c` to what `tmp` is pointing to (i.e., to `b`). 

### ft_bzero.c

```c
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*tmp;

	tmp = (char *)s;
	while (n > 0)
	{
		*tmp = 0;
		tmp++;
		n--;
	}
}
```

**`bzero`** is almost exactly the same function as **`memset`**, but instead of filling a block of memory with a particular value, it writes `**n**` bytes of **`0`** to the pointer to the block of memory **`s`**.

A loop assigns the value of `0` to what `tmp` is pointing to (i.e., to **`s`**).

### ft_memcpy.c

```c
#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dest;
	unsigned char	*source;

	if (src == NULL && dst == NULL)
		return (dst);
	dest = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (n > 0)
	{
		*(dest++) = *(source++);
		n--;
	}
	return (dst);
}
```

**`memcpy`** function copies `**n**` bytes of a block of memory from a **`src`** address to a **`dst`** address. It creates `unsigned char` pointers to both the `source` and the `dest` addresses allowing the copy of each byte individually in the `while` loop `n` times.

### ft_memmove.c

```c
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	char	*source;
	size_t	i;

	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	dest = (char *)dst;
	source = (char *)src;
	if (dest > source)
	{
		while (len-- > 0)
			dest[len] = source[len];
	}
	else
	{
		while (i < len)
		{
			dest[i] = source[i];
			i++;
		}
	}
	return (dst);
}
```

**`memmove`** works similarly to the **`memcpy`** function, copying **`len`** bytes of a block of memory from a `src` address to a `dst` address. However, **`memmove`** compares the sizes of the `source` and `dest`, using different approaches to avoid data overwriting. Specifically, when the destination is greater than the source, it performs a backward copy to prevent premature data corruption, ensuring a non-destructive transfer even when memory regions overlap.

### ft_strlcpy.c

```c
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	count;
	size_t	i;

	count = ft_strlen(src);
	i = 0;
	if (size != 0)
	{
		while (i < (size - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (count);
}
```

**`ft_strlcpy`** copies chars from a **`src`** string to a **`dest`** string, considering a specified buffer **`size`**. It calculates the length of the source string and iteratively copies characters to `dest`, ensuring a null terminator is added within the specified size. The function returns the length of the source string preventing buffer overflows.

### ft_strlcat.c

```c
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	char	*s;
	size_t	len_dest;
	size_t	len_src;
	size_t	len_total;
	size_t	i;

	s = (char *)src;
	len_dest = ft_strlen(dest);
	len_src = ft_strlen(s);
	len_total = 0;
	i = 0;
	if (size > len_dest)
		len_total = len_src + len_dest;
	else
		len_total = len_src + size;
	while (s[i] && (len_dest + 1) < size)
	{
		dest[len_dest] = s[i];
		len_dest++;
		i++;
	}
	dest[len_dest] = '\0';
	return (len_total);
}
```

**`ft_strlcat`** function concatenates characters from a **`src`** string to an existing **`dest`** string, considering a specified buffer **`size`**. It calculates the lengths of the `dest` and `src` strings and appends characters to the destination, ensuring a null terminator is added within the specified size. The function returns the total length after concatenation preventing buffer overflows.

### ft_toupper.c

```c
#include "libft.h"

int	ft_toupper(int c)
{
	int	upper;

	if (c >= 'a' && c <= 'z')
		upper = c - ('a' - 'A');
	else
		upper = c;
	return (upper);
}
```

This function takes an integer `c` as a parameter, checks `if` it is a lower character (`a` to `z`) and, if it is, it converts it into to an `upper` character (`A` to `Z`) and returns it as an integer. If it isn’t, it returns the integer provided unchanged.

### ft_tolower.c

```c
#include "libft.h"

int	ft_tolower(int c)
{
	int	lower;

	if (c >= 'A' && c <= 'Z')
		lower = c + ('a' - 'A');
	else
		lower = c;
	return (lower);
}
```

This function takes an integer `c` as a parameter, checks if it is an upper character (`A` to `Z`) and, if it is, it converts it into to a `lower` character (`a` to `z`) and returns it as an integer. If it isn’t, it returns the integer provided unchanged.

### ft_strchr.c

```c
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}
```

`ft_strchr` locates the first occurrence of a specified character `c` in a string `s`. It declares a variable **`cc`** of type **`char`** to hold the character **`c`**, changing it’s type.Then it uses a **`while`** loop to iterate through the characters of the string **`s`**. If the current character in the string (**`s[i]`**) is equal to the specified character **`cc`** it returns a pointer to the location of the matched character in the string. If the end of the string is reached and the character is not found, it returns **`NULL`**.

### ft_strncmp.c

```c
#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	size_t	i;

	i = 0;
	while ((str1[i] || str2[i]) && i < n)
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return (0);
}
```

**`ft_strncmp`** compares the first **`n`** characters of two strings, **`str1`** and **`str2`**. It uses a **`while`** loop to iterate through the characters, checking for inequality. If a difference is found, it returns the ASCII difference between the first differing characters. If the end of either string or the specified number of characters **`n`** is reached without a difference, it returns **`0`**. This function is useful for lexicographical string comparisons with a specified length limit.

### ft_memchr.c

```c
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	chr;

	str = (unsigned char *) s;
	chr = (unsigned char) c;
	i = 0;
	while (i < n)
	{
		if (str[i] == chr)
			return ((void *) &str[i]);
		i++;
	}
	return (NULL);
}
```

**`ft_memchr`** searches the first **`n`** bytes of a block of memory **`s`** for the specified byte **`c`**. It utilizes a **`while`** loop to iterate through the bytes, converting the block to **`unsigned char`** for accurate comparisons. If a match is found, it returns a pointer to the location of the matched byte in the memory block. If the end of the block is reached and the byte is not found, it returns **`NULL`**. This function is valuable for locating a specific byte within a memory block up to a specified length.

### ft_memcmp.c

```c
#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}
```

**`ft_memcmp`** compares the first **`n`** bytes of two memory blocks, **`s1`** and **`s2`**. It utilizes a **`while`** loop to iterate through the bytes, converting both blocks to **`unsigned char`** for accurate comparisons. If a difference is found at any position, it returns the difference between the ASCII values of the differing bytes. If the end of both blocks is reached without a difference, it returns **`0`**. This function is essential for assessing the equality of memory blocks up to a specified length, offering a comparison based on the ASCII values of the differing bytes.

- [ ]  **ft_strnstr.c**

```c
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle[0] == 0)
		return ((char *)haystack);
	while (haystack[i] && i < len)
	{
		while (haystack[i + j] && haystack[i + j] == needle[j] && i + j < len)
		{
			j++;
			if (needle[j] == 0)
				return ((char *)haystack + i);
		}
		i++;
		j = 0;
	}
	return (0);
}
```

**`ft_strnstr`** searches for the first occurrence of the substring **`needle`** within the string **`haystack`**, up to a specified length **`len`**. It uses nested **`while`** loops to iterate through the characters, comparing each character of the substring with the corresponding character in the string. If a match is found and the end of the substring is reached, it returns a pointer to the beginning of the matched substring within the string. If the end of the string or the specified length is reached without finding the substring, it returns **`NULL`**. This function is useful for locating substrings within strings with a length constraint.

### ft_atoi.c

```c
#include "libft.h"

int	ft_atoi(const char *str)
{
	size_t	i;
	size_t	sign;
	size_t	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (result * sign);
}
```

**`ft_atoi`** converts a string **`str`** representing an integer to its corresponding **`int`** value. It uses a **`while`** loop to iterate through the characters, skipping leading whitespaces. It handles the sign of the integer and then iterates through the consecutive digits, updating the result accordingly. It converts consecutive digits in the string into an integer, updating the result by multiplying it by 10 to shift digits and adding the numeric value of the current character (obtained by subtracting '0'), aligning ASCII values with numeric representations. The function returns the final integer value, considering both the sign and the numeric characters encountered.

### ft_calloc.c

```c
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc (count * size);
	if (ptr == NULL)
		return (NULL);
	while (i < count * size)
	{
		ptr[i] = 0;
		i++;
	}
	return (ptr);
}
```

**`ft_calloc`** allocates memory for an array of elements with a specified **`count`** and **`size`**, initializing the allocated memory to zero. It uses **`malloc`** to allocate the memory, checks for allocation success, and then iterates through the allocated block, setting each byte, each element of `ptr`, to zero. The function returns a pointer to the allocated and initialized memory block, or **`NULL`** if the allocation fails. This function is essential for dynamic memory allocation with zero-initialized values.

### ft_strdup.c

```c
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*dest;
	size_t	i;

	i = 0;
	while (s1[i])
		i++;
	dest = (char *)malloc(sizeof(char) * (i + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		dest[i] = s1[i];
		i++;
	}
	dest [i] = '\0';
	return (dest);
}
```

**`ft_strdup`** duplicates a string **`s1`** by allocating memory for a new string `**dest**` and copying the characters from **`s1`** to the newly allocated memory block, `**dest**`. It calculates the length of the input string, allocates memory for the duplicate string, checks for allocation success, and then iterates through the characters, copying them to the new string. The function adds a null terminator to the end of the new string and returns a pointer to the duplicated string. If the allocation fails, it returns **`NULL`**. This function is essential for creating a duplicate string with dynamically allocated memory.

## Part 2 - Additional functions

- [ ]  **ft_substr.c**

```c
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*str;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	return (str);
}
```

**`ft_substr`** extracts a substring from the string **`s`** starting at index **`start`** with a length of **`len`**. It checks for a valid input string and adjusts the length if it exceeds the available characters. The function allocates memory for the substring, copying the characters from the original string. It returns a pointer to the newly created substring, or **`NULL`** if the allocation fails. This function is crucial for obtaining specific portions of a string with dynamically allocated memory.

- [ ]  **ft_strjoin.c**

```c
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	join = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	while (s1[i])
	{
		join[j] = s1[i];
		j++;
		i++;
	}
	i = 0;
	while (s2[i])
	{
		join[j] = s2[i];
		j++;
		i++;
	}
	join[j] = '\0';
	return (join);
}
```

**`ft_strjoin`** concatenates two strings, **`s1`** and **`s2`**, by allocating memory for the combined string. It calculates the length of both input strings, allocates memory for the concatenated string, and then iterates through each character of **`s1`** and **`s2`**, copying them to the newly allocated memory block. The function adds a null terminator at the end of the concatenated string and returns a pointer to the result. If the allocation fails, it returns **`NULL`**. This function is essential for combining two strings into a dynamically allocated new string.

- [ ]  **ft_strtrim.c**

```c
#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*start;
	const char	*end;
	size_t		len;

	if (!s1 || !set)
		return (NULL);
	start = s1;
	while (*start && ft_strchr(set, *start))
		start++;
	end = s1 + ft_strlen(s1);
	while (end > start && ft_strchr(set, *(end - 1)))
		end--;
	if (start >= end)
		return (ft_strdup(""));
	len = end - start;
	return (ft_substr(s1, start - s1, len));
}
```

The **`ft_strtrim`** function trims leading and trailing characters from the input string **`s1`** based on a specified set of characters (**`set`**). It uses pointers (**`start`** and **`end`**) to identify the trimmed portion of the string. The function checks for NULL inputs, trims characters from the beginning and end, and returns a new dynamically allocated string containing the trimmed substring. If the resulting string is empty after trimming, it returns an empty string. The function utilizes helper functions from the **`libft`** library, such as **`ft_strchr`**, **`ft_strlen`**, **`ft_strdup`**, and **`ft_substr`**.

### ft_split.c (seg fault)

```c
// Splits a string s with the given c as separator

#include <stdlib.h>

static	size_t	char_in_str(const char c, const char *charset);
static	size_t	count_words(const char *str, const char *charset);
static	void		wordcpy(char *to, const char *from, const char *charset);
static	void		word_split(char **splitted, const char *str, char *charset);

char	**ft_split(char const *s, char c)
{
	char	**sub_s; // Array to store substrings
	size_t	words; // Number of words in the s string

	words = count_words(s, &c); // Count the number of words in s string
	sub_s = (char **)malloc(sizeof(char *) * (words + 1)); // Allocate memory for the array of strings
	if (sub_s == NULL)
		return (NULL);
	sub_s[words] = 0; // Set the last element of the array to NULL, indicating the end
	word_split(sub_s, s, &c); // Extract and store each word in the array
	return (sub_s);
}

// Looks for c (separators) in s (the main string).
static	size_t	char_in_str(const char c, const char *charset)
{
	size_t	i;

	i = 0;
	if (c == '\0') // If the character is the null terminator, it is considered in the set
		return (1);
	while (charset[i] != '\0') // Iterate through the charset to find a c (separator)
	{
		if (c == charset[i])
			return (1); // If the character is found in the charset, return 1 (true)
		i++;
	}
	return (0); // If the character is not found in the charset, return 0 (false)
}

// Count how many times the separator (charset) is found in s
static	size_t	count_words(const char *s, const char *charset)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (s[i] != '\0') // Iterates through the main input string.
	{
		if (char_in_str(s[i + 1], charset) == 1 // If the next character is the separator and
			&& char_in_str(s[i], charset) == 0) // the current one isn't, increment word count
			words++;
		i++;
	}
	return (words); // Return the number of words found in s
}

// Copies the splitted string into a new array.
static	void	wordcpy(char *to_sub_s, const char *from_s, const char *charset)
{
	size_t	i;

	i = 0;
	while (char_in_str(from_s[i], charset) == 0) // While the current charset is not the separator
	{											 // copy the charset from the main str, from_s
		to_sub_s[i] = from_s[i];				 // to the new substring, to_sub_s
		i++;
	}
	to_sub_s[i] = '\0'; // Null terminate the substring
}

// Allocates the memory for each substrig. Responsible for extracting them
static	void	word_split(char **split_sub_s, const char *s, char *charset)
{
	size_t	i;
	size_t	j;
	size_t	word;

	i = 0;
	word = 0;
	while (s[i] != '\0') // Iterate through the main string s
	{
		if (char_in_str(s[i], charset) == 1) // If the current charset is a separator, move to the next
			i++;
		else
		{
			j = 0;
			while (char_in_str(s[i + j], charset) == 0) // Count the characters until next separator
				j++;
			split_sub_s[word] = (char *)malloc(sizeof(char) * (j + 1)); // Allocate mem for the substring
			wordcpy(split_sub_s[word], s + i, charset); // Copy the substring into the allocated memory
			i = i + j; // Move the index to the next separator or the end of s
			word++; // Move to the next word
		}
	}
}
```

- **`ft_split`** takes a string **`s`** and a separator character **`c`** and returns an array of the new strings of each split. In this function there are another four helper functions, totaling five functions:
1. `**ft_split**` calculates the number of words, allocates memory for an array of substrings, and calls the **`word_split`** function to populate the array. The resulting array is then returned.
2. `**char_in_str**` checks if a `**char c**` (the separator character) is present in the current **`charset`**, i.e. in the current element of the main string. It iterates through **`charset`** and returns **`1`** if a match is found, indicating the presence of the character separator. It will be used in the next three functions, `**count_words**`, `**wordcpy**` and `**word_split**`.
3. **`count_words`** calculates the number of `**words**` in the main input string **`s`** based on the **`charset`**, the separator. It iterates through `**s**` and increments the word count each time a separator is followed by a non-separator character using the `**char_in_str**` function.
4. **`wordcpy`** copies characters from the source string, **`from_s`**, to the destination substring, **`to_sub_s`**, until a separator character is encountered, using `**char_in_str**`. It ensures the copied string is null-terminated. This function is utilized in extracting and storing individual substrings during the splitting process, in `**word_split**`.
5. **`word_split`** allocates memory for each substring in the array and extracts them from the input string **`s`** using the provided separator character set **`charset`**. It iterates through **`s`**, identifies words, allocates memory for each word, and copies the characters using the **`wordcpy`** function. This function is responsible for preparing the array of substrings.

- [ ]  **ft_split.c**

```c
#include "libft.h"

static int	ft_count_words(char const *s, char c);
static void	free_arr_strs(char **arr_strs, size_t i);
static char	**split(char const *s, char c, char **arr_strs, size_t i);

//Function to split a str s, using a sep c, into an array of strings arr_strs
char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**arr_strs;

	i = 0;
	//Allocate memory for the array of strings, arr_str,
	// adding 1 for the NULL terminating pointer at the end of the array
	arr_strs = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!s || !arr_strs)
		return (0);
	//Call split function to populate the array with substrings
	arr_strs = split(s, c, arr_strs, i);
	return (arr_strs);
}

//Function to count the number of words in a str based on the sep
static int	ft_count_words(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

//Function to free the memory allocated for an array of strings
static void	free_arr_strs(char **arr_strs, size_t i)
{
	while (0 < i)
	{
		i--;
		free(arr_strs[i]);
	}
	free(arr_strs);
}

//Function responsible for the actual splitting process
static char	**split(char const *s, char c, char **arr_strs, size_t i)
{
	int	word_len;

	while (*s)
	{
		// Skip consecutive separators
		while (*s == c)
			s++;
		if (*s)
		{
			//Determine the length of the current word
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			//Extract the current word and store it in the array
			arr_strs[i] = ft_substr(s, 0, word_len);
			//Check for memory allocation failure
			if (arr_strs[i] == NULL)
			{
				free_arr_strs(arr_strs, i);
				return (NULL);
			}
			//Move to the next separator or the end of the string
			i++;
			s = s + word_len;
		}
	}
	//Null terminate the array of strings
	arr_strs[i] = NULL;
	return (arr_strs);
}
```

- **`ft_split`** is a function that takes a string **`s`** and a separator character **`c`** and returns an array of strings, each representing a word in the original string. It uses helper functions to count the number of words, allocate memory for the array, and then extract and store each word in the array.
1. **`ft_count_words`**: A helper function that counts the number of words in the input string **`s`** based on the separator **`c`**. It iterates through the string, skipping consecutive separators, and increments the count for each word.
2. **`free_arr_strs`**: A helper function that frees the memory allocated for the array of strings. It iterates through the array and frees each individual string and then frees the array itself.
3. **`split`**: A helper function responsible for the actual splitting process. It iterates through the input string, skipping consecutive separators, and extracts each word using the **`ft_substr`** function. The extracted word is then stored in the array of strings. If memory allocation fails during this process, it frees the previously allocated memory and returns **`NULL`**.

- [ ]  **ft_itoa.c**

```c
#include "libft.h"

static int	int_len(long nbr);
static char	*malloc_for_str(int len);

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*str;
	long	nbr;

	nbr = n;
	len = int_len(nbr);
	str = malloc_for_str(len);
	if (!str)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	while (nbr != 0)
	{
		str[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		str[0] = '-';
	str[len] = 0;
	return (str);
}

static int	int_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

static char	*malloc_for_str(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	tmp[0] = '0';
	return (tmp);
}
```

**`ft_itoa`** converts an integer **`n`** into a string representation by allocating memory for the result. It calculates the length of the integer and allocates memory accordingly. The function then iterates through the digits of the integer, converting them to characters and placing them in reverse order in the string. If the integer is negative, a minus sign is added. The function returns a pointer to the resulting string. If the allocation fails, it returns **`NULL`**. This function is essential for converting integers into string representations.

- [ ]  **ft_strmapi.c**

```c
#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*res;

	res = malloc((ft_strlen(s) +1) * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = 0;
	return (res);
}
```

**`ft_strmapi`** applies a function **`f`** to each character of the string **`s`**, creating a new string with the results. It allocates memory for the result, iterates through the characters, and applies the function to each character and its corresponding index. The function returns a pointer to the resulting string. If the allocation fails, it returns **`NULL`**. This function is crucial for creating transformed versions of strings based on a specified mapping function.

- [ ]  **ft_striteri.c**

```c
#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
```

**`ft_striteri`** applies a function **`f`** to each character of the string **`s`** along with its corresponding index. It iterates through the characters of the string, applying the function to each character and its index. This function is useful for performing operations on each character of a string with the awareness of its position.

### ft_putchar_fd.c

```c
#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
```

**`ft_putchar_fd`** writes a single character **`c`** to the specified file descriptor **`fd`** using the **`write`** function.

### ft_putstr_fd.c

```c
#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(fd, &str[i], 1);
		i++;
	}
}
```

**`ft_putstr_fd`** writes the string **`str`** to the specified file descriptor **`fd`** by iterating through its characters and using the **`write`** function.

### ft_putendl_fd.c

```c
#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
	}
	write (fd, "\n", 1);
}
```

**`ft_putendl_fd`** writes the string **`s`** followed by a newline character to the specified file descriptor **`fd`**. It iterates through the characters of the string and uses the **`write`** function.

## Part 3 - Bonus

### ft_lstnew.c

```c
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new = malloc(sizeof(t_list));

	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
```

`ft_lstnew` takes a pointer to a generic data type `content`, allowing it to be any data type. It returns a pointer to the `new` node of type `t_list` (defined in `libft.h`). This function creates a `new` node for a linked list. It allocates memory for `new`, sets its `content` to the provided parameter, allowing storage of any data type. The recursive nature of the structure of `t_list`, defined with the `typedef struct s_list` in the `libft.h` allows each node to point to the `next` node, forming a linked list. For that reason, the `next` pointer of the `new` node is set to `NULL`, marking the end of the list.

### ft_lstadd_front.c

```c
void ft_lstadd_front(t_list **lst, t_list *new)
{
    new->next = *lst;
    *lst = new;
}
```

`ft_lstadd_front` sets the `new` element's `next` address to point to the start of the existing list, `lst`, i.e. to the first node of the list, making it the `next` element of the list, instead of the first. Then it sets the existing list, `lst` pointer to point to the `new` element, making the `new` node the first element of the list. So the `new` element is added to the front of the list, `lst`.

### ft_lstsize.c

```c
#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		count;

	tmp = lst;
	count = 0;
	while (tmp)
	{
		tmp = tmp->next;
		count++;
	}
	return (count);
}
```

**`ft_lstsize`** calculates and returns the number of elements in a linked list. It takes a pointer to the first node of the list, **`lst`**, and iterates through each node, incrementing a counter **`count`** for each node encountered. The function continues until the end of the list is reached (when **`tmp`** becomes **`NULL`**). It then returns the count, representing the size of the linked list. This function is crucial for determining the number of elements in a linked list.

### ft_lstlast.c

```c
#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}
```

**`ft_lstlast`** returns a pointer to the last node of a linked list. It takes a pointer to the first node of the list, **`lst`**, and checks if the list is empty. If the list is not empty, it iterates through the list using a temporary pointer **`tmp`** until it reaches the last node, which is identified when **`tmp->next`** becomes **`NULL`**. The function then returns a pointer to the last node or **`NULL`** if the list is empty. This function is essential for obtaining the last element in a linked list.

### ft_lstadd_back.c

```c
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (!new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}
```

**`ft_lstadd_back`** adds a new node **`new`** to the end of a linked list **`lst`**. It takes a double pointer to the first node of the list (**`lst`**) and the new node (**`new`**). If the new node is not **`NULL`**, it checks if the list is empty. If the list is empty, the new node becomes the first node. If the list is not empty, it finds the last node in the list using **`ft_lstlast`**, and makes the last node's **`next`** point to the new node, effectively adding the new node to the end of the list. This function is crucial for appending elements to the end of a linked list.

### ft_lstdelone.c

```c
#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
```

**`ft_lstdelone`** deletes a single node from a linked list. It takes a pointer to the node to be deleted (**`lst`**) and a function pointer **`del`** that is responsible for freeing the content of the node. The function first applies **`del`** to free the content of the node and then uses **`free`** to release the memory occupied by the node itself.

### ft_lstclear.c

```c
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = tmp;
	}
	free(*lst);
	*lst = NULL;
}
```

**`ft_lstclear`** deletes the entire linked list. It takes a double pointer to the first node of the list (**`lst`**) and a function pointer **`del`** to free the content of each node. The function iterates through the list, deleting each node using **`ft_lstdelone`**, and then sets the list pointer to **`NULL`** after clearing all nodes. This function is crucial for freeing the memory occupied by the entire linked list.

- [ ]  **ft_lstiter.c**

```c
#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*tmp;

	tmp = lst;
	while (tmp)
	{
		f(tmp->content);
		tmp = tmp->next;
	}
}
```

**`ft_lstiter`** applies a given function **`f`** to each node's content in a linked list. It takes a pointer to the first node of the list (**`lst`**) and a function pointer **`f`** that performs an operation on the content of each node. The function iterates through the list, applying **`f`** to the content of each node, effectively performing an operation on each element of the list.

- [ ]  **ft_lstmap.c**

```c
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_obj;

	if (!lst || !f || !del)
		return (NULL);
	new_list = NULL;
	while (lst)
	{
		new_obj = ft_lstnew(f(lst->content));
		if (!new_obj)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_obj);
		lst = lst->next;
	}
	return (new_list);
}
```

**`ft_lstmap`** creates a new linked list by applying a given function **`f`** to each element of the original linked list **`lst`**. It takes a pointer to the first node of the original list (**`lst`**), a function pointer **`f`** that transforms the content of each node, and a function pointer **`del`** that frees the content of a node. The function iterates through the original list, applying **`f`** to create a new node with transformed content for each element. If memory allocation fails during this process, it clears the newly created list using **`ft_lstclear`** and returns **`NULL`**. Otherwise, it returns a pointer to the new list.

This function is crucial for creating a new list where each element's content is transformed based on a specified function.