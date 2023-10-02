#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void output_magic(unsigned char *e_ident);
void output_class(unsigned char *e_ident);
void output_data(unsigned char *e_ident);
void output_version(unsigned char *e_ident);
void output_abi(unsigned char *e_ident);
void output_osabi(unsigned char *e_ident);
void output_type(unsigned int e_type, unsigned char *e_ident);
void output_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);

/**
 * check_elf - a function that checks whether the given file
 * is an ELF file
 * @e_ident: A pointer storing magic numbers
 *
 */
void check_elf(unsigned char *e_ident)
{
	int m;

	for (m = 0; m < 4; m++)
	{
		if (e_ident[m] != 127 &&
		    e_ident[m] != 'E' &&
		    e_ident[m] != 'L' &&
		    e_ident[m] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * output_magic -A function to print magic numbers of ELF header
 * @e_ident: an array containing the ELF magic numbers to be printed
 *
 */
void output_magic(unsigned char *e_ident)
{
	int m;

	printf(" Magic: ");

	for (m = 0; m < EI_NIDENT; m++)
	{
		printf("%02x", e_ident[m]);

		if (m == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * output_class - a function to print the class of an ELF header
 * @e_ident: A pointer  to an array storing the ELF class.
 */
void output_class(unsigned char *e_ident)
{
	printf(" Class: ");

	switch (e_ident[EI_CLASS])
	{
	case ELFCLASSNONE:
		printf("none\n");
		break;
	case ELFCLASS32:
		printf("ELF32\n");
		break;
	case ELFCLASS64:
		printf("ELF64\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 * output_data -a function to print the data of an ELF header
 * @e_ident: A pointer to an array storing the ELF class to print.
 */
void output_data(unsigned char *e_ident)
{
	printf(" Data: ");

	switch (e_ident[EI_DATA])
	{
	case ELFDATANONE:
		printf("none\n");
		break;
	case ELFDATA2LSB:
		printf("2's complement, little endian\n");
		break;
	case ELFDATA2MSB:
		printf("2's complement, big endian\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_CLASS]);
	}
}

/**
 *  * output_version - a function to print the version of an ELF header
 *   * @e_ident: A pointer to an array storing the ELF version to print.
 *    */
void output_version(unsigned char *e_ident)
{
	 printf(" Version: %d",
			  e_ident[EI_VERSION]);

	switch (e_ident[EI_VERSION])
	{
	case EV_CURRENT:
		printf(" (current)\n");
		break;
	default:
		printf("\n");
		break;
	}
}

/**
 * output_osabi -a function to print the OS?ABI of an ELF header
 * @e_ident: A pointer to an array storing the ELF version to print
 */
void output_osabi(unsigned char *e_ident)
{
	printf(" OS/ABI: ");

	switch (e_ident[EI_OSABI])
	{
	case ELFOSABI_NONE:
		printf("UNIX - System V\n");
		break;
	case ELFOSABI_HPUX:
		printf("UNIX - HP-UX\n");
		break;
	case ELFOSABI_NETBSD:
		printf("UNIX - NetBSD\n");
		break;
	case ELFOSABI_LINUX:
		printf("UNIX - Linux\n");
		break;
	case ELFOSABI_SOLARIS:
		printf("UNIX - Solaris\n");
		break;
	case ELFOSABI_IRIX:
		printf("UNIX - IRIX\n");
		break;
	case ELFOSABI_FREEBSD:
		printf("UNIX - FreeBSD\n");
		break;
	case ELFOSABI_TRU64:
		printf("UNIX - TRU64\n");
		break;
	case ELFOSABI_ARM:
		printf("ARM\n");
		break;
	case ELFOSABI_STANDALONE:
		printf("Standalone App\n");
		break;
	default:
		printf("<unknown: %x>\n", e_ident[EI_OSABI]);
	}
}

/**
 * output_abi - a function to print the ABI version of an ELF header
 * @e_ident: A pointer to an array storing the ELF ABI version to print
 */
void output_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n",
		e_ident[EI_ABIVERSION]);
}

/**
 * output_type - a function to print the type of an ELF header
 * @e_type: The type of ELF header
 * @e_ident: A pointer to an array storing the ELF class to print
 */
void output_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
		e_type >>= 8;

	printf(" Type: ");

	switch (e_type)
	{
	case ET_NONE:
		printf("NONE (None)\n");
		break;
	case ET_REL:
		printf("REL (Relocatable file)\n");
		break;
	case ET_EXEC:
		printf("EXEC (Executable file)\n");
		break;
	case ET_DYN:
		printf("DYN (Shared object file)\n");
		break;
	case ET_CORE:
		printf("CORE (Core file)\n");
		break;
	default:
		printf("<unknown: %x>\n", e_type);
	}
}

/**
 *output_entry - a function to print the entry point address of an ELf header
 * @e_entry: the entry point address of the ELF
 * @e_ident: A pointer to an array storing the ELF class to print
 */
void output_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	printf(" Entry point address: ");

	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
		e_entry = ((e_entry << 8) & 0xFF00FF00) |
			  ((e_entry >> 8) & 0xFF00FF);
		e_entry = (e_entry << 16) | (e_entry >> 16);
	}

	if (e_ident[EI_CLASS] == ELFCLASS32)
		printf("%#x\n", (unsigned int)e_entry);

	else
		printf("%#lx\n", e_entry);
}

/**
 * close_elf - a function to close the ELF file
 * @elf: it is the file descriptor of the ELF file
 *
 */
void close_elf(int elf)
{
	if (close(elf) == -1)
	{
		dprintf(STDERR_FILENO,
			"Error: Can't close fd %d\n", elf);
		exit(98);
	}
}

/**
 * main - a function to display the information stored in the ELF
 * header atthe start of an ELF file
 * @argc: The number of arguments passed to the function
 * @argv: An array of pointers to the passed arguments in the function
 *
 * Return: 0 (success)
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
		free(header);
		close_elf(o);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	check_elf(header->e_ident);
	printf("ELF Header:\n");
	output_magic(header->e_ident);
	output_class(header->e_ident);
	output_data(header->e_ident);
	output_version(header->e_ident);
	output_osabi(header->e_ident);
	output_abi(header->e_ident);
	output_type(header->e_type, header->e_ident);
	output_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}

