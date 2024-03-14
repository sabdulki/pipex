#include <unistd.h>
#include <stdio.h>

// int main(int ac, char **av)
// {
// 	int pid;
// 	pid = fork();
// 	if (pid == 0)
// 	{

// 		printf("id = %d, hello world from child\n", pid);
// 		printf("id = %d smth\n", pid);
// 	}
// 	else
// 	{
// 		printf("id = %d, hello world from parent\n", pid);
// 	}
// 	printf("id = %d, where i am?\n", pid);
// 	printf("id = %d, 2222 where i am?\n", pid);
// 	return (0);
// }

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    int num_children = 10;

    for (int i = 0; i < num_children; i++) {
        pid_t pid = fork();

        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pid == 0) {  // Дочерний процесс
            printf("Child process %d is executing\n", i);
            sleep(1);  // Имитация работы дочернего процесса
            exit(EXIT_SUCCESS);
        }
    }

    // Родительский процесс
    printf("Parent process is waiting for child processes to finish...\n");
    for (int i = 0; i < num_children; i++) {
        int status;
        pid_t child_pid = wait(&status);
        if (WIFEXITED(status)) {
            printf("Child process with PID %d exited with status: %d\n", child_pid, WEXITSTATUS(status));
        }
    }

    printf("All child processes have finished. Parent process is done.\n");

    return 0;
}
