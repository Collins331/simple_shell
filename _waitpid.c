#include "main.h"

/**
 * _waitpid - waitpid
 * @pid: input
 * @wstatus: input
 * @options: input
 * Return: result
 */

pid_t _waitpid(pid_t pid, int *wstatus, int options)
{
	pid_t res;

	do {
		res = waitpid(pid, wstatus, options);
	} while (res == -1 && errno == EINTR);
	return (res);
}
