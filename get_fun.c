#include "shell.h"

void (*get_comd_fun(vars_t *vars)) (vars_t *vars)
{
	unsigned int iter;

	builtins_t comds[] = {
		{"exit", get_exit},
		{"env", get_env},
		{NULL, NULL}
	};
	for (iter = 0; comds[iter].f != NULL; iter++)
	{
		if (_strcmp(vars->av[0], comds[iter].name) == 0)
			break;
	}
	if (comds[iter].f != NULL)
		comds[iter].f(vars);

	return (comds[iter].f);
}

