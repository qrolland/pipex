# pipex

pipex est un projet 42 visant à mieux comprendre la redirection du shell et les pipes, en les gérant en C.

Ce programme pipex prend un fichier d'entrée, exécute une commande dessus, transmet le résultat à une autre commande qui écrit ensuite son résultat dans un fichier de sortie. Le résultat est pratiquement identique à ce type de commande shell :

` $ < input_file command1 | command2 > output file ` 
