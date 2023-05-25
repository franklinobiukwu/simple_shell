#ifndef STRUCTS_H
#define STRUCTS_H
typedef struct env_list_s
{
	char *env_variable;
	char *env_value;
	char *env_str;
	struct env_list_s *next;
} env_l;

#endif
