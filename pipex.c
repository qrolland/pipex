/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qrolland <qrolland@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 22:53:28 by qrolland          #+#    #+#             */
/*   Updated: 2022/11/28 17:50:07 by qrolland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_paths(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH", 4))
		i++;
	paths = ft_split(envp[i] + 5, ':');
	return (paths);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*path;
	char	*slash;
	int		i;

	paths = get_paths(envp);
	i = 0;
	while (paths[i])
	{
		slash = ft_strjoin(paths[i], "/");
		path = ft_strjoin(slash, cmd);
		free(slash);
		if (access(path, F_OK | X_OK) == 0)
		{
			ft_free_strs(paths);
			return (path);
		}
		free(path);
		i++;
	}
	ft_free_strs(paths);
	return (0);
}

void	command_one(int *pipefd, int *fd, char **av, char **envp)
{
	char	**cmd;

	fd[0] = open(av[1], O_RDONLY);
	if (fd[0] == -1)
		ft_perror("Error");
	close(pipefd[0]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_perror("Error");
	if (dup2(pipefd[1], STDOUT_FILENO) == -1)
		ft_perror("Error");
	close(fd[0]);
	close(pipefd[1]);
	cmd = ft_split(av[2], ' ');
	if (cmd[0] && get_cmd_path(cmd[0], envp))
	{
		execve(get_cmd_path(cmd[0], envp), cmd, envp);
		ft_free_strs(cmd);
	}
	else
	{
		ft_free_strs(cmd);
		ft_error("Error, command 1 was not found");
	}
}

void	command_two(int *pipefd, int *fd, char **av, char **envp)
{
	char	**cmd;

	fd[1] = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd[1] == -1)
		ft_perror("Error");
	close(pipefd[1]);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_perror("Error");
	if (dup2(pipefd[0], STDIN_FILENO) == -1)
		ft_perror("Error");
	close(fd[1]);
	close(pipefd[0]);
	cmd = ft_split(av[3], ' ');
	if (cmd[0] && get_cmd_path(cmd[0], envp))
	{
		execve(get_cmd_path(cmd[0], envp), cmd, envp);
		ft_free_strs(cmd);
	}
	else
	{
		ft_free_strs(cmd);
		ft_error("Error, command 2 was not found");
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		pipefd[2];
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		ft_error("Error arguments: ./pipex file1 cmd1 cmd2 file2");
	if (pipe(pipefd) == -1)
		ft_perror("Error");
	pid1 = fork();
	if (pid1 == -1)
		ft_perror("Error");
	else if (pid1 == 0)
		command_one(pipefd, fd, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		ft_perror("Error");
	else if (pid2 == 0)
		command_two(pipefd, fd, argv, envp);
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
