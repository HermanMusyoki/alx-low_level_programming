#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void Determine_elf(unsigned char *e_ident);
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
 * Determine_elf - a function that determines if a file is an ELF file.
 * @e_ident: A pointer that stores array of ELF magic numbers.
 *
 */
void Determine_elf(unsigned char *e_ident)
{
	int pos;

	for (pos = 0; pos < 4; pos++)
	{
		if (e_ident[pos] != 127 &&
		    e_ident[pos] != 'E' &&
		    e_ident[pos] != 'L' &&
		    e_ident[pos] != 'F')
		{
			dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
			exit(98);
		}
	}
}

/**
 * output_magic -a function that outputs the magic numbers of an ELF header.
 * @e_ident: A pointer that stores the magic numbers in ELF
 */
void output_magic(unsigned char *e_ident)
{
	int pos;

	printf(" Magic: ");

	for (pos = 0; pos < EI_NIDENT; pos++)
	{
		printf("%02x", e_ident[pos]);

		if (pos == EI_NIDENT - 1)
			printf("\n");
		else
			printf(" ");
	}
}

/**
 * output_class -a function that outputs the class of an ELF header.
 * @e_ident: A pointer to an array storing the ELF class.
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
 * output_data - a function that outputs the data of an ELF header.
 * @e_ident: A pointer to an array storing the ELF class.
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
 * output_version - a function that outputs the version of an ELF header.
 *  @e_ident: A pointer to an array storing the ELF version.
 */
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
 * output_osabi - a function that outputs the OS/ABI of an ELF header.
 * @e_ident: A pointer to an array storing the version of the ELF
 *
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
 * output_abi -a function that outputs the ABI version of an ELF header.
 * @e_ident: A pointer to an array storing the version of ELF ABI
 */
void output_abi(unsigned char *e_ident)
{
	printf(" ABI Version: %d\n",
		e_ident[EI_ABIVERSION]);
}

/**
 * output_type -a function that outputs an ELF header type
 * @e_type: The ELF type to be printed
 * @e_ident: A pointer to an array storing the ELF class.
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
 * output_entry - a function that outputs the entry point of an ELF header.
 * @e_entry: a variable for the address of the ELF entry point.
 * @e_ident: A pointer to an array storing  the ELF class.
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
 * close_elf - a function that exits an ELF file.
 * @elf: The file descriptor for the textfile elf
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
 * main -a function that shows the information contained in the
 * ELF header at the beggining of an ELF file.
 * @argc: The number of arguments passed to the function
 * @argv: An array of pointers cointaing arguments passed to the program
 *
 * Return: always 0 (success)
 *
 */
int main(int __attribute__((__unused__)) argc, char *argv[])
{
	Elf64_Ehdr *header;
	int fd, text;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		exit(98);
	}
	text = read(fd, header, sizeof(Elf64_Ehdr));
	if (text == -1)
	{
		free(header);
		close_elf(fd);
		dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
		exit(98);
	}

	Determine_elf(header->e_ident);
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
	close_elf(fd);
	return (0);
}

